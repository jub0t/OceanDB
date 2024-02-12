#ifndef DB_DATATYPES
#define DB_DATATYPES

#include <cstdint>
#include "./ocean_string.cpp"

enum class UniversalTypes: uint16_t {
  STRING,
  NUMBER,
  INTEGER,
  BOOLEAN,
};

union UniversalUnion {
  OceanString str_val;
  int64_t int_val;
  float float_val;
  bool bool_val;
};

class UniversalConverter {
  OceanString ToString(UniversalUnion un) {
    return un.str_val;
  };

  int64_t ToInteger(UniversalUnion un) {
    return static_cast<int64_t>(un.int_val);
  };

  bool ToBoolean(UniversalUnion un) {
    return static_cast<bool>(un.bool_val);
  };
};

#endif
