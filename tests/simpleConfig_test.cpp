#include "catch/catch.hpp"

#include "simpleConfig/simpleConfig.hpp"

using namespace simpleConfig;


TEST_CASE("Constructor") {
  SECTION("Basic construction") {
    REQUIRE_NOTHROW([&](){
      SimpleConfig config ("../config/test.config");
    });

    
    REQUIRE_THROWS([&](){
      SimpleConfig config ("../config/somefile.whwatever");
    });
  }
}