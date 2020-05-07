#include "catch.hpp"

#include "simpleConfig.hpp"

using namespace simpleConfig;

TEST_CASE("Constructor") {
  SECTION("Basic construction") {
    REQUIRE_NOTHROW([](){
      SimpleConfig config ("../config/test.config");
    });
  }
}