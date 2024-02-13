#ifndef OCEAN_ROWS
#define OCEAN_ROWS

#include <array>
#include <unordered_map>

#include "./datatypes.cpp"

using RowCore = std::unordered_map<std::string, UniversalUnion>;
using RowsCore = std::array<RowCore, 8>;

// Wrapper for RowCore:
class Row {
private:
  RowsCore data;

public:
  Row(RowCore data) {};
  
  RowsCore Get() {
    return this->data;
  };
};

class Rows {
private:
  RowsCore data;

public:
  Rows() {};
};

#endif // !OCEAN_ROWS
