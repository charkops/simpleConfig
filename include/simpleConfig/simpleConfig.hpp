#pragma once

#include <string>

namespace simpleConfig {
  class SimpleConfig {
  private:
    std::string configFilePath_;

  public:
    SimpleConfig(const std::string &configFilePath);
    ~SimpleConfig() = default;
  };
};