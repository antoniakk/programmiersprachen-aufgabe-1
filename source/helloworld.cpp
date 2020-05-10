#include <iostream>


int zahl1_20() {
  bool not_found = true;
  int number = 20;
  while (not_found) {
    for (int i = 1; i <= 20; ++i) {
      if (number%i != 0) {
        number+=20;
        break;
      }
      if (i==20) {
        not_found = false;
      }
    }
  }
  return number;
}


int main()
{
  std::cout << zahl1_20() << std::endl;
  return 0;
}
