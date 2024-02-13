// CUSTOM JSON-PARSER TO PROCESS SPECIAL TYPES LIKE "UniversalTypes" and "UniversalUnion"


#include "./rows.cpp"
#include "bucket.cpp"
#include "../libs/debugger.cpp"
#include "../libs/rows.cpp"
#include <cstdint>

struct RowInput {
  SchemaMap* schema;
  RowsCore* rows;
};

#define JSON_ARRAY_START "["
#define JSON_ARRAY_END "]"
#define JSON_OBJECT_START "{"
#define JSON_OBJECT_END "}"
#define JSON_COMMA ","

enum JsonResults: uint8_t {
  ParseSuccess,
  InvalidToken,
  DataInvalid,
};

class OceanJsonParser {
  OceanDebugger debug;

public:
  ~OceanJsonParser() {};

public:
  // Row<RowInfo, Vector<Row>>
  std::string ParseRows(RowInput ri) {
    auto rows = ri.rows;
    std::cout << rows->size()<<"\n";

    std::string json;
    json.append(JSON_ARRAY_START);
    
    int ic = 0;

    for (auto& row : *rows) {
      // this->debug.DebugRows(row);
      std::string el_str;
      el_str.append(JSON_OBJECT_START);

      int fc = 0;
      for (auto& [key, value] : row) {
        
        el_str += "\"" + key + "\":" + "\"" + static_cast<const char>(value.int_val) + "\", ";
        
        fc++;
      }

      el_str.append(JSON_OBJECT_END);

      if (ic > 0) { json.append(JSON_COMMA);  };
      json.append(el_str);
      ic++;
    }
    
    json.append(JSON_ARRAY_END);
    return json;
 };
};
