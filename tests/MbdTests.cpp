
// This tells Catch to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_MAIN
#include "catch.hpp"


#include "agent.hpp"


TEST_CASE("test nothing much", "[testing]") {
  CHECK(2 == 2);
}