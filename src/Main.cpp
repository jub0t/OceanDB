#include <iostream>
#include "../libs/ocean.cpp"

int main() {
  DatabaseOcean ocean;
  bool success = ocean.CreateNewBucket("users");
  std::cout << "Success: " << success << "\n";

  bool success_new = ocean.CreateNewBucket("users");
  std::cout << "Success: " << success_new << "\n";

  return 0;
}
