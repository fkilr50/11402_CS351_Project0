# Contributing Guidelines

Thank you for your interest in contributing to the Two Sum Project! This document outlines the process and standards for contributing.

## Getting Started

1. Fork the repository
2. Clone your fork locally
3. Follow the [Installation Guide](INSTALLATION.md)
4. Review [GETTING_STARTED.md](GETTING_STARTED.md) to understand the project

## Branch Workflow

### Main Branch (`main`)
- Contains stable, tested code
- Only accepts pull requests from the `test` branch
- Reserved for production-ready code

### Test Branch (`test`)
- Staging environment for new features
- All changes must be tested here first
- Must pass quality checks before merging to main

### Feature Development
1. Create a feature branch from `test`: `git checkout -b feature/your-feature-name`
2. Make your changes
3. Test thoroughly
4. Create a pull request to `test` branch

## Code Style

This project follows the **Google C++ Style Guide**. Before submitting:

- Use 2-space indentation
- Follow Google naming conventions (snake_case for variables, CamelCase for classes)
- Include comments for complex logic
- Ensure code is self-documenting

### Example
```cpp
// Good: Clear function name and comments
std::vector<int> twoSum(std::vector<int>& nums, int target) {
  // Hash map to store number -> index
  std::unordered_map<int, int> seen;
  
  for (int i = 0; i < nums.size(); ++i) {
    int complement = target - nums[i];
    if (seen.find(complement) != seen.end()) {
      return {seen[complement], i};
    }
    seen[nums[i]] = i;
  }
  
  return {}; // No solution found
}
```

## Commit Messages

Write clear, concise commit messages:

```
[FEATURE|FIX|DOCS] Brief description

Detailed explanation if needed
```

Examples:
- `[FEATURE] Add hash map optimization to twoSum`
- `[FIX] Handle edge case with duplicate numbers`
- `[DOCS] Update API reference with examples`

## Pull Request Process

1. Update documentation for any API changes
2. Add comments for new functions
3. Test your changes thoroughly
4. Create PR with clear description of changes
5. Wait for review and address feedback
6. Maintainers will merge after approval

## Testing

Before submitting a PR:
- Test with the provided examples
- Test edge cases (empty arrays, single element, no solution)
- Compile without warnings
- Verify output correctness

## Documentation

When contributing:
- Update relevant .md files in `docs/` folder
- Keep documentation synchronized with code
- Add examples for new features
- Update CHANGELOG.md

## Questions or Issues?

Refer to:
- [FAQ.md](FAQ.md) for common questions
- [TROUBLESHOOTING.md](TROUBLESHOOTING.md) for common issues
- Create an issue on the repository

## Code of Conduct

- Be respectful and professional
- Provide constructive feedback
- Help others in the community
- Focus on code quality and clarity
