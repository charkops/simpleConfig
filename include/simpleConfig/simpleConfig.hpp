#pragma once

#include <experimental/filesystem>

namespace simpleConfig {
  class SimpleConfig {
  private:
    std::experimental::filesystem::path configFilePath_;

  public:
    SimpleConfig(const std::string &configFilePath);
    ~SimpleConfig() = default;
  };
};