#include "simpleConfig/simpleConfig.hpp"

#include <experimental/filesystem>


namespace simpleConfig {

  // Initialize configFilePath and make sure file exists, else throw
  SimpleConfig::SimpleConfig(const std::string &configFilePath)
    : configFilePath_ (configFilePath)
    {
      if (!std::experimental::filesystem::exists(configFilePath_))
        throw std::runtime_error("Config file does not exist");
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

  ConfigInfo SimpleConfig::parseConfigFile() {
    ConfigInfo info;

    return info;
  };
}