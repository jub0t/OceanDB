#ifndef OCEAN_DEBUGGER
#define OCEAN_DEBUGGER

#include "datatypes.cpp"
#include <unordered_map>
#include <iostream>

class OceanDebugger {
public:
  void DebugRows(std::unordered_map<std::string, UniversalUnion> map) {
    for (auto& [key, value] : map) {
      std::cout << "[KEY]: " << key << "\n[INT64]: " << value.int_val.Get();
    }
  };
};

#endif
