#pragma once

#include <experimental/filesystem>
#include <vector>
#include <optional>
#include <iostream>
#include <type_traits>

namespace simpleConfig {

  struct ConfigValue {
    std::string type;
    std::string name;
    std::string value;

    friend std::ostream& operator<<(std::ostream &os, const ConfigValue &value);
  };

  

  struct ConfigInfo {
    std::vector<ConfigValue> configValues;
    std::optional<ConfigValue> getConfigValue(const std::string &key);
  };

  class SimpleConfig {
  private:
    std::experimental::filesystem::path configFilePath_;
    ConfigInfo configInfo_;  

  public:
    // TODO (@charkops): Add another constructor for std::filesystem::path ?
    SimpleConfig(const std::string &configFilePath);
    ~SimpleConfig() = default;
    
    bool isValidConfigFile();
    static bool isValidConfigLine(const std::string &line);
    static bool isLineComment(const std::string &line);
    static std::vector<std::string> findWords(const std::string &line, const unsigned short int numWords = 3);

    ConfigInfo parseFile();

    template <typename T>
    std::optional<T> getValue (const std::string &key) {
      // If value exists return it
      auto configValue = configInfo_.getConfigValue(key);
      if (configValue) {
        if constexpr (std::is_same<T, std::string>::value) {
          return std::optional<std::string>{(*configValue).value};
        }
        if constexpr (std::is_same<T, int>::value) {
          auto value = std::stoi((*configValue).value);
          return std::optional<int>{value};
        }
        if constexpr (std::is_same<T, double>::value) {
          auto value = std::stod((*configValue).value);
          return std::optional<double>{value};
        }
      }
      return std::nullopt;
    }
  };
};