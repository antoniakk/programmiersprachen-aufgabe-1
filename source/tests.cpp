#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <catch.hpp>
#include <cmath>
#include <string>
#include <cmath>

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

float cyl_surface(float radius, float height) {
  return (2*radius*M_PI*(height + radius));
}

TEST_CASE("describe_cyl_surface", "[cyl_surface]") {
  REQUIRE(cyl_surface(4.5, 5.7) == Approx(288.4));
  REQUIRE(cyl_surface(9.99, 10) == Approx(1254.75));
  REQUIRE(cyl_surface(2.4, 13.3) == Approx(236.75));
}

float cyl_volume(float radius, float height) {
  return M_PI*radius*radius*height;
}

TEST_CASE("describe_cyl_volume", "[cyl_volume]") {
  REQUIRE(cyl_volume(4.5, 5.7) == Approx(362.618));
  REQUIRE(cyl_volume(9.99, 10) == Approx(3135.31));
  REQUIRE(cyl_volume(2.4, 13.3) == Approx(240.67));
  }

unsigned int factorial(unsigned int N) {
  unsigned int fact_of_N = 1;
  for(int i = N; i > 1; --i) {
    fact_of_N *= i;
  }
  return fact_of_N;
}

TEST_CASE("describe_factorial", "[factorial]") {
  REQUIRE(factorial(3) == 6);
  REQUIRE(factorial(0) == 1);
  REQUIRE(factorial(7) == 5040);
}

bool is_prime(int a) {
  if (abs(a) == 1 || a == 0) {
    return false;
  }
  for (int i = 2; i < abs(a); ++i) {
    if (abs(a) % i == 0) {
      return false;
      break;
    }
  }
  return true;
}

TEST_CASE("describe_is_prime", "[is_prime]") {
  REQUIRE(is_prime(3) == true);
  REQUIRE(is_prime(1) == false);
  REQUIRE(is_prime(0) == false);
  REQUIRE(is_prime(-17) == true);
  REQUIRE(is_prime(-1) == false);
}

int main(int argc, char* argv[])
{
  return Catch::Session().run(argc, argv);
}
