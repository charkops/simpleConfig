#include "simpleConfig.hpp"

#include <experimental/filesystem>


namespace simpleConfig {

  // Initialize configFilePath and make sure file exists, else throw
  SimpleConfig::SimpleConfig(const std::string &configFilePath)
    : configFilePath_ (configFilePath)
    {
      if (!std::experimental::filesystem::exists(configFilePath_))
        throw std::runtime_error("Config file does not exist");
    }
}