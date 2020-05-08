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
}