import tomlplusplus;
import std;

int main() {
    // Test 1: Parse from string
    auto config = toml::parse(R"(
        [server]
        port = 8080
        host = "localhost"
        
        [database]
        enabled = true
    )");
    
    // Test 2: Access values
    auto port = config["server"]["port"].value<int>();
    auto host = config["server"]["host"].value<std::string>();
    auto enabled = config["database"]["enabled"].value<bool>();
    
    // Test 3: Verify values
    bool test1 = port.value_or(0) == 8080;
    bool test2 = host.value_or("") == "localhost";
    bool test3 = enabled.value_or(false) == true;
    
    std::println("Test 1 (port): {}", test1 ? "PASS" : "FAIL");
    std::println("Test 2 (host): {}", test2 ? "PASS" : "FAIL");
    std::println("Test 3 (enabled): {}", test3 ? "PASS" : "FAIL");
    
    return (test1 && test2 && test3) ? 0 : 1;
}
