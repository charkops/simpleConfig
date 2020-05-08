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
  };
};