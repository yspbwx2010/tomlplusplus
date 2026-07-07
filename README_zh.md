# tomlplusplus

> TOML 配置文件解析器与序列化器，C++17（及更高版本），仅头文件

[![MIT License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)
[![C++17](https://img.shields.io/badge/C%2B%2B-17-blue.svg)](https://en.cppreference.com/w/cpp/17)
[![TOML v1.0.0](https://img.shields.io/badge/TOML-v1.0.0-blue.svg)](https://toml.io/en/v1.0.0)

**中文 | [English](README.md)**

**Fork 说明**：本仓库基于 [marzer/tomlplusplus](https://github.com/marzer/tomlplusplus)，添加了 [mcpp](https://github.com/mcpp-community/mcpp) 构建工具支持。

## 上游项目

- **作者**：Mark Gillard
- **原仓库**：https://github.com/marzer/tomlplusplus
- **许可证**：MIT
- **文档**：https://marzer.github.io/tomlplusplus/

## mcpp 安装与使用

### 从 mcpp-index 安装（推荐）

```bash
mcpp add compat.tomlplusplus@3.4.0
```

### 在代码中使用

**使用 C++20 模块**（mcpp 推荐方式）：

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

**或使用传统头文件**：

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

### 本地构建与测试

```bash
mcpp build           # 构建库
mcpp run             # 运行测试（tests/basic_test.cpp）
mcpp run simple      # 运行示例（examples/simple.cpp）
```

## 项目结构

```
tomlplusplus/
├── mcpp.toml                      # mcpp 包清单
├── README.md                      # 英文文档
├── README_zh.md                   # 中文文档（本文件）
├── README.upstream.md             # 上游原始 README
├── src/modules/tomlplusplus.cppm  # C++23 模块接口
├── include/toml++/                # 模块化头文件
├── toml.hpp                       # 单头文件版本
├── tests/basic_test.cpp           # 基础测试
└── examples/simple.cpp            # 使用示例
```

## C++ 标准要求

- **最低要求**：C++17
- **模块支持**：C++20（使用 `import tomlplusplus;` 时）

## 特性

- ✅ **完整的 TOML v1.0.0 支持**
- ✅ **仅头文件**，无需编译
- ✅ **C++17 及更高版本**
- ✅ **解析与序列化**
- ✅ **清晰的错误消息**
- ✅ **多种格式输出**（TOML、JSON、YAML）
- ✅ **可选的 C++20 模块支持**

## Fork 修改内容

相比上游，本 fork 添加了：

1. **mcpp.toml** - mcpp 包清单
2. **tests/basic_test.cpp** - 基础功能测试（使用 `import std` 和 `import tomlplusplus`）
3. **examples/simple.cpp** - 最小使用示例
4. **README.md** - 英文文档
5. **README_zh.md** - 中文文档（本文件）
6. **.gitignore** - 忽略 mcpp 构建产物（`target/`）

## 上游文档

完整的 API 文档、高级用法和性能优化，请参阅：

- 📖 [上游 README](README.upstream.md)
- 🌐 [官方文档站](https://marzer.github.io/tomlplusplus/)
- 📦 [上游仓库](https://github.com/marzer/tomlplusplus)

## 许可证

MIT License - 详见 [LICENSE](LICENSE)

## 相关链接

| 项目 | 说明 |
|------|------|
| [mcpp](https://github.com/mcpp-community/mcpp) | 现代 C++23 构建与包管理工具 |
| [mcpp-index](https://github.com/mcpplibs/mcpp-index) | mcpp 默认包索引 |
| [tomlplusplus 上游](https://github.com/marzer/tomlplusplus) | 原始项目 |
