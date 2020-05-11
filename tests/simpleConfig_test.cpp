#include "catch/catch.hpp"

#include "simpleConfig/simpleConfig.hpp"

using namespace simpleConfig;


TEST_CASE("Constructor") {
  SECTION("Basic construction") {
    REQUIRE_NOTHROW([&](){
      SimpleConfig config ("../config/test.config");
    });

    // TODO (@charkops): Test doesn't work where constructor clearly throws a runtime_error, don't 
    //                    know why catch2 doesn't cooperate
    // REQUIRE_THROWS_AS([&](){
    //   SimpleConfig ("config/somefile.whwatever");
    // }, std::runtime_error);
  }
};

TEST_CASE("findWords") {
  const std::string testLine ("  someValue : integer ? 3  ");
  auto result = SimpleConfig::findWords(testLine);
  REQUIRE(result.size() == 3);
  auto name = result[0];
  auto type = result [1];
  auto value = result [2];
  REQUIRE(name == "someValue");
  REQUIRE(type == "integer");
  REQUIRE(value == "3");

  const std::string anotherTestLine = ":?";
  result = SimpleConfig::findWords(anotherTestLine);
  REQUIRE(result.size() == 3);
  name = result[0];
  type = result [1];
  value = result [2];
  REQUIRE(name == "");
  REQUIRE(type == "");
  REQUIRE(value == "");
}

TEST_CASE("isValidConfigLine") {

  SECTION("Valid line") {
    const std::string line ("someValue: string ? 'whatisthis'");
    REQUIRE(SimpleConfig::isValidConfigLine(line));
  };

  SECTION("InvalidLine") {
    // Comment
    const std::string line (" someValue: integer ? ");
    REQUIRE_FALSE(SimpleConfig::isValidConfigLine(line));
  }
};

TEST_CASE("isValidConfigFile") {
  SECTION("Valid file") {
    SimpleConfig config ("../config/test.config");
    REQUIRE(config.isValidConfigFile());
  };

  // SECTION("Invalid file") {
  //   // REQUIRE_THROWS([](){SimpleConfig config ("../config/invalid.config");});
  // };
};

TEST_CASE("isLineComment") {
  SECTION ("Valid comment") {
    const std::string validComment ("# this is a comment");
    REQUIRE(SimpleConfig::isLineComment(validComment));
    const std::string anotherValidComment ("  # This is also a comment");
    REQUIRE(SimpleConfig::isLineComment(anotherValidComment));
    const std::string multipleSpacesButValid ("  ####   thiss should be a comment");
    REQUIRE(SimpleConfig::isLineComment(multipleSpacesButValid));
  };

  SECTION ("Invalid comment") {
    const std::string invalidComment ("this#should be invalid");
    REQUIRE_FALSE(SimpleConfig::isLineComment(invalidComment));
  };
}

TEST_CASE("parseFile") {
  SECTION("Valid Config file") {
    SimpleConfig config ("../config/test.config");
    auto info = config.parseFile();
    REQUIRE(info.configValues.size() == 3);
  };
};



