#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <catch.hpp>
#include <cmath>
#include <string>

int gcd(int a, int b) {
  if (a < b) {
    gcd(b, a);
  }
  if (b == 0) {
    return a;
  }
  else {
    return gcd(b, a % b);
  }
  
}

TEST_CASE("describe_gcd", "[gcd]") {
  REQUIRE(gcd(2, 4) == 2);
  REQUIRE(gcd(9, 6) == 3);
  REQUIRE(gcd(3, 7) == 1);
}

int checksum(int n) {
  std::string n_str = std::to_string(n);
  int checksum = 0;
  for(int i = 0; i < n_str.size(); ++i) {
    char temp = n_str[i];
    int temp_int = temp - '0';
    checksum += temp_int;
  }
  return checksum;
}

TEST_CASE("describe_checksum", "[checksum]") {
  REQUIRE(checksum(122266) == 19);
  REQUIRE(checksum(10079) == 17);
  REQUIRE(checksum(735564) == 30);
}



int main(int argc, char* argv[])
{
  return Catch::Session().run(argc, argv);
}
