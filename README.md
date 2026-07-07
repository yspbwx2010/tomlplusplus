# tomlplusplus

> Header-only TOML config file parser and serializer for C++17 (and later)

[![MIT License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)
[![C++17](https://img.shields.io/badge/C%2B%2B-17-blue.svg)](https://en.cppreference.com/w/cpp/17)
[![TOML v1.0.0](https://img.shields.io/badge/TOML-v1.0.0-blue.svg)](https://toml.io/en/v1.0.0)

**[中文](README_zh.md) | English**

**Fork Notice**: This repository is based on [marzer/tomlplusplus](https://github.com/marzer/tomlplusplus), with added [mcpp](https://github.com/mcpp-community/mcpp) build tool support.

## Upstream Project

- **Author**: Mark Gillard
- **Original Repository**: https://github.com/marzer/tomlplusplus
- **License**: MIT
- **Documentation**: https://marzer.github.io/tomlplusplus/

## Installation with mcpp

### From mcpp-index (Recommended)

```bash
mcpp add compat.tomlplusplus@3.4.0
```

### Usage in Code

**With C++20 modules** (recommended for mcpp):

```cpp
import tomlplusplus;
import std;

int main() {
    auto config = toml::parse(R"(
        [server]
        port = 8080
        host = "localhost"
    )");
    
    auto port = config["server"]["port"].value<int>();
    std::println("Port: {}", port.value_or(0));
    
    return 0;
}
```

**Or with traditional headers**:

```cpp
#include <toml++/toml.hpp>
#include <iostream>

int main() {
    auto config = toml::parse(R"(
        [server]
        port = 8080
    )");
    
    auto port = config["server"]["port"].value<int>();
    std::cout << "Port: " << port.value_or(0) << std::endl;
    
    return 0;
}
```

### Build & Test

```bash
mcpp build           # Build library
mcpp run             # Run tests (tests/basic_test.cpp)
mcpp run simple      # Run example (examples/simple.cpp)
```

## Project Structure

```
tomlplusplus/
├── mcpp.toml                      # mcpp package manifest
├── README.md                      # English documentation (this file)
├── README_zh.md                   # Chinese documentation
├── README.upstream.md             # Original upstream README
├── src/modules/tomlplusplus.cppm  # C++23 module interface
├── include/toml++/                # Modular headers
├── toml.hpp                       # Single-header version
├── tests/basic_test.cpp           # Basic tests
└── examples/simple.cpp            # Usage example
```

## C++ Standard Requirements

- **Minimum**: C++17
- **Module support**: C++20 (when using `import tomlplusplus;`)

## Features

- ✅ **Full TOML v1.0.0 support**
- ✅ **Header-only**, no compilation required
- ✅ **C++17 and later**
- ✅ **Parsing & serialization**
- ✅ **Clear error messages**
- ✅ **Multiple output formats** (TOML, JSON, YAML)
- ✅ **Optional C++20 module support**

## Fork Changes

Compared to upstream, this fork adds:

1. **mcpp.toml** - mcpp package manifest
2. **tests/basic_test.cpp** - Functional tests using `import std` and `import tomlplusplus`
3. **examples/simple.cpp** - Minimal usage example
4. **README.md** - English documentation (this file)
5. **README_zh.md** - Chinese documentation
6. **.gitignore** - Ignore mcpp build artifacts (`target/`)

## Upstream Documentation

For complete API documentation, advanced usage, and performance tuning, see:

- 📖 [Upstream README](README.upstream.md)
- 🌐 [Official Documentation](https://marzer.github.io/tomlplusplus/)
- 📦 [Upstream Repository](https://github.com/marzer/tomlplusplus)

## License

MIT License - see [LICENSE](LICENSE)

## Related Links

| Project | Description |
|---------|-------------|
| [mcpp](https://github.com/mcpp-community/mcpp) | Modern C++23 build and package management tool |
| [mcpp-index](https://github.com/mcpplibs/mcpp-index) | Default package index for mcpp |
| [tomlplusplus upstream](https://github.com/marzer/tomlplusplus) | Original project |
