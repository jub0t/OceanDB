#ifndef DB_DATATYPES
#define DB_DATATYPES

#include <cstdint>
#include <string>

enum class UniversalTypes: uint16_t {
  STRING,
  NUMBER,
  INTEGER,
  BOOLEAN,
};

union UniversalUnion {
  int64_t int_val;
  std::string str_val;
  float float_val;
};

class Universal {};

#endif
