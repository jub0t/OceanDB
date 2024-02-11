#ifndef OCEAN_ROWS
#define OCEAN_ROWS

#include <array>
#include <unordered_map>

#include "./datatypes.cpp"

using RowCore = std::unordered_map<std::string, UniversalUnion>;
using RowsCore = std::array<RowCore, 1024 * 1024>;

// Wrapper for RowCore:
class Row {
private:
  RowCore data;

public:
  Row(RowCore data): data(data)  {};
  
  RowCore Get() {
    return this->data;
  };
};

#endif // !OCEAN_ROWS
