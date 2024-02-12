#include <iostream>
#include <array>

class OceanString {
public:
  std::array<char, 65535> _v;

  void Load(std::string* s) {};
  auto Get() { return this->_v; };
};
