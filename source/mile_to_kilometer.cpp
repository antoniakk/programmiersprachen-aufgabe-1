#include <iostream>


float miles_to_kilometer(float miles) {
  return miles*1.60934;
}


int main()
{
  std::cout << "Hallo! Ich rechne Meilen in Kilometer um. Bitte geben Sie mir eine Zahl in Meilen."  << std::endl;
  float miles;
  std::cin >> miles;
  std::cout << "Hier ist Ihre Zahl in Kilometer: " << miles_to_kilometer(miles) << std::endl;
  return 0;
}
