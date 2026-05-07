# Docker Setup Guide

## Overview

Docker allows you to build and test the Two Sum project in a reproducible, isolated environment without installing dependencies on your local machine.

## Files Created

- **Dockerfile** - Multi-stage build for production-ready image
- **docker-compose.yml** - Orchestration for easy container management
- **.dockerignore** - Excludes unnecessary files from Docker build context

## Quick Start

### Option 1: Using Docker Compose (Recommended)

```bash
# Run tests inside a container
docker-compose run build-and-test

# Output: Full test suite results
```

### Option 2: Using Docker Directly

```bash
# Build the Docker image
docker build -t twosum:latest .

# Run tests
docker run --rm twosum:latest

# Run with output
docker run --rm twosum:latest /app/build/two_sum_tests
```

## Dockerfile Features

### Multi-Stage Build
- **Stage 1 (Builder)**: Compiles the project with all dev tools
- **Stage 2 (Runtime)**: Lightweight runtime with only necessary libraries
- **Result**: Smaller final image size (~150MB vs 500MB+)

### Build Configuration
```dockerfile
# Uses:
- Ubuntu 22.04 base image
- GCC C++ compiler
- CMake + Ninja build system
- C++20 standard
- Release build type for performance
```

## Docker Compose Services

### `build-and-test` (Default)
```bash
# Runs the full test suite
docker-compose run build-and-test
```

### `dev` (Development)
```bash
# Interactive bash shell in container with project mounted
docker-compose run dev

# Inside container:
apt-get update
apt-get install -y g++ cmake ninja-build
cmake -S . -B build -G Ninja -DCMAKE_CXX_STANDARD=20
cmake --build build
ctest --test-dir build --output-on-failure
```

## Common Commands

### Build the image
```bash
docker build -t twosum:latest .
```

### Run tests with output
```bash
docker run --rm twosum:latest
```

### Run main application
```bash
docker run --rm twosum:latest /app/build/two_sum_app
```

### Interactive shell in container
```bash
docker run -it --rm twosum:latest /bin/bash
```

### Mount local source for development
```bash
docker run -it --rm -v $(pwd)/src:/app/src twosum:latest /bin/bash
```

### View image size
```bash
docker images twosum
```

## Dockerfile Breakdown

### Stage 1: Builder
```dockerfile
FROM ubuntu:22.04 as builder
RUN apt-get install -y g++ cmake ninja-build git
COPY . /app
RUN cmake -S . -B build -G Ninja ...
RUN cmake --build build
```

### Stage 2: Runtime
```dockerfile
FROM ubuntu:22.04
COPY --from=builder /app/build /app/build
ENTRYPOINT ["/app/build/two_sum_tests"]
```

## Benefits

✅ **Reproducible Environment** - Same setup on all machines
✅ **Isolated Dependencies** - No conflicts with local tools
✅ **Easy CI/CD Integration** - GitHub Actions can use this image
✅ **Clean** - No system pollution
✅ **Portable** - Works on Windows, Mac, Linux

## Integration with GitHub Actions

The Docker image can be used in GitHub Actions:

```yaml
jobs:
  docker-test:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v4
      - name: Build and test with Docker
        run: docker build -t twosum . && docker run --rm twosum
```

## Troubleshooting

### Image build fails
```bash
# Clean build (no cache)
docker build --no-cache -t twosum:latest .
```

### Container exits immediately
```bash
# Run with interactive terminal
docker run -it --rm twosum:latest /bin/bash
```

### Permission denied errors
```bash
# On Linux, prefix with sudo if needed
sudo docker build -t twosum .
sudo docker-compose run build-and-test
```

## Size Optimization

Current image sizes (approximate):
- Builder stage: ~500MB
- Runtime stage: ~150MB (final)
- Size reduction: ~70% with multi-stage build

## Next Steps

1. Install Docker: https://www.docker.com/products/docker-desktop
2. Navigate to project directory
3. Run `docker-compose run build-and-test`
4. View test results

## Resources

- [Docker Documentation](https://docs.docker.com/)
- [Docker Compose Documentation](https://docs.docker.com/compose/)
- [Ubuntu Docker Images](https://hub.docker.com/_/ubuntu)
