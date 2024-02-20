#include <iostream>
#include <array>

class OceanString {
public:
  std::array<char, 65535> _v;

void Load(const std::string& s) {
  if (!s.empty()) {
      std::copy(s.begin(), s.end(), _v.begin());
  }
}
  
  // Get first 'x' number of non-null charecters
  auto Get() { return this->_v; };
  
  // Get as string
std::string ToString() const {
  std::string result;
  for (const auto c : _v) {
    if (c != '\0') {
        result += c;
    } else {
        break;
    }
  }
  return result;
}
};
