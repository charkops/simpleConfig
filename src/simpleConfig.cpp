#include "simpleConfig.hpp"


namespace simpleConfig {

  // Initialize configFilePath and make sure file exists, else throw
  SimpleConfig::SimpleConfig(const std::string &configFilePath)
    : configFilePath_ (configFilePath) {}
}