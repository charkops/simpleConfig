#pragma once

#include <experimental/filesystem>

namespace simpleConfig {
  class SimpleConfig {
  private:
    std::experimental::filesystem::path configFilePath_;
    
  public:
    // TODO (@charkops): Add another constructor for std::filesystem::path ?
    SimpleConfig(const std::string &configFilePath);
    ~SimpleConfig() = default;
    
    bool isValidConfigFile();
    static bool isValidConfigLine(const std::string &line);
    static bool isLineComment(const std::string &line);
    static std::vector<std::string> findWords(const std::string &line, const unsigned short int numWords = 3);
  };
};