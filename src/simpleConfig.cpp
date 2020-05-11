#include "simpleConfig/simpleConfig.hpp"

#include <fstream>
#include <experimental/filesystem>


namespace simpleConfig {

  // Initialize configFilePath and make sure file exists, else throw
  SimpleConfig::SimpleConfig(const std::string &configFilePath)
    : configFilePath_ (configFilePath)
    {
      if (!std::experimental::filesystem::exists(configFilePath_))
        throw std::runtime_error("Config file does not exist");

      if (!SimpleConfig::isValidConfigFile())
        throw std::runtime_error("Config file is not valid");

      configInfo_ = parseFile();
    };

  std::vector<std::string> SimpleConfig::findWords(const std::string &line, const unsigned short int numWords) {
    std::vector<std::string> words;

    std::string word;
    for (const auto c : line) {
      if (c == ' ') continue;
      if (c == ':' || c == '?') {
        words.push_back(word);
        if (words.size() == numWords) return words;
        word = "";  // Reset string
        continue;
      }
      word += c;
    }
    words.push_back(word);

    return words;
  };

  bool SimpleConfig::isValidConfigLine(const std::string &line) {
    // Line should not start with # -- comment
    if (line.find("#") == 0)  return false;
    
    // Find words
    // 1) Should not be empty 
    auto parsedWords = SimpleConfig::findWords(line);
    if (parsedWords.size() != 3) return false;
    auto name = parsedWords[0];
    auto type = parsedWords[1];
    auto value = parsedWords[2];
    if (name == "" || type == "" || value == "") return false;

    // TODO (@charkops): Add more checks

    return true;
  };

  bool SimpleConfig::isLineComment(const std::string &line) {
    for (const auto c : line) {
      if (c == ' ') continue;
      if (c != '#')
        return false;
      else
        return true;
    }
    return false;
  };

  // If the configFilePath_ exists is none of this function's concern
  bool SimpleConfig::isValidConfigFile() {
    // Open file
    const std::string filePath = configFilePath_.u8string();

    // Read each line
    std::ifstream file (filePath);
    std::string line;
    while (std::getline(file, line)) {
      if (line.empty()) continue;
      if (SimpleConfig::isLineComment(line)) continue;
      if (!SimpleConfig::isValidConfigLine(line)) return false;
    }
    return true;
  };


  ConfigInfo SimpleConfig::parseFile() {
    ConfigInfo info;
    // Open file and parse line by line && add to info
    std::string filePath = configFilePath_.u8string();
    std::ifstream file (filePath);
    std::string line;
    while (getline(file, line)) {
      // Parse line 
      if (SimpleConfig::isValidConfigLine(line)) {
        auto parsedLine = findWords(line);
        auto name = parsedLine[0];
        auto type = parsedLine[1];
        auto value = parsedLine[2];

        ConfigValue configValue;
        configValue.name = name;
        configValue.type = type;
        configValue.value = value;

        info.configValues.push_back(configValue);
      }
    }

    return info;
  };

  // Overload operators
  std::ostream& operator<< (std::ostream &os, const ConfigValue &value) {
    os << "(" << value.name << ", " << value.type << ", " <<
                  value.value << ")";
    return os;
  };

  std::optional<ConfigValue> ConfigInfo::getConfigValue(const std::string &key) {
    for (const auto &value : configValues)
      if (key == value.name)
        return std::optional<ConfigValue> {value};
    return std::nullopt;
  };

  
}