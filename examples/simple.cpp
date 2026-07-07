import tomlplusplus;
import std;

int main() {
    static constexpr std::string_view source = R"(
        title = "TOML Example"
        
        [owner]
        name = "Tom"
        
        [servers.alpha]
        ip = "10.0.0.1"
        port = 8001
    )";
    
    try {
        auto tbl = toml::parse(source);
        std::println("title = {}", tbl["title"].value_or("<none>"));
        std::println("owner.name = {}", tbl["owner"]["name"].value_or("<none>"));
        std::println("alpha.ip = {}", tbl["servers"]["alpha"]["ip"].value_or("<none>"));
        std::println("alpha.port = {}", tbl["servers"]["alpha"]["port"].value_or(0));
    } catch (const toml::parse_error& err) {
        std::println(std::cerr, "Parse failed: {}", err.description());
        return 1;
    }
    
    return 0;
}
