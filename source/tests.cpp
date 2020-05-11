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

int sum_multiples() {
  int sum = 0;
  for(int i = 1; i <= 1000; ++i) {
    if (i%3 == 0 || i%5 == 0) {
      sum += i;
    }
  }
  return sum;
}

TEST_CASE("describe_sum_multiples", "[sum_multiples]") {
  REQUIRE(sum_multiples() == 234168);
}

float fract(float a) {
  int a_int = a;
  return a - a_int;
}

TEST_CASE("describe_fract", "[fract]") {
  REQUIRE(fract(1.83) == Approx(0.83));
  REQUIRE(fract(2.54603) == Approx(0.54603));
  REQUIRE(fract(9.99932) == Approx(0.99932));
}

int main(int argc, char* argv[])
{
  return Catch::Session().run(argc, argv);
}
