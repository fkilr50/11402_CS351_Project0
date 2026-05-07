# Multi-stage Dockerfile for Two Sum Project
# Stage 1: Builder
FROM ubuntu:22.04 as builder

# Install dependencies
RUN apt-get update && apt-get install -y \
    g++ \
    cmake \
    ninja-build \
    git \
    && rm -rf /var/lib/apt/lists/*

# Set working directory
WORKDIR /app

# Copy project files
COPY . /app

# Configure and build
RUN cmake -S . -B build \
    -G Ninja \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_CXX_STANDARD=20 \
    -DCMAKE_CXX_STANDARD_REQUIRED=ON

RUN cmake --build build

# Stage 2: Runtime (smaller image)
FROM ubuntu:22.04

# Install only runtime dependencies
RUN apt-get update && apt-get install -y \
    libstdc++6 \
    && rm -rf /var/lib/apt/lists/*

# Set working directory
WORKDIR /app

# Copy built binaries from builder stage
COPY --from=builder /app/build /app/build

# Copy source files for reference
COPY . /app

# Set entrypoint to run tests
ENTRYPOINT ["/app/build/two_sum_tests"]

# Default command (can be overridden)
CMD []
