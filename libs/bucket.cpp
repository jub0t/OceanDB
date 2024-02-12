#ifndef DB_BUCKET
#define DB_BUCKET

#include <algorithm>
#include <cstdint>
#include <stdint.h>
#include <unordered_map>
#include "./datatypes.cpp"
#include <string>

#include "./rows.cpp"

struct BucketSchemaField {
  uint64_t max_len;
  UniversalTypes datatype;  
};

using SchemaMap = std::unordered_map<std::string, BucketSchemaField>;

class Bucket {
public:
  SchemaMap schema;
  bool strict_type;
  
  // HashMap<Id, Row<RowName, Data>
  RowsCore rows;

  Bucket() {
    // this->strict_type = strict_type_checking;
  }

  void AppendType(std::string name, BucketSchemaField sf) {
    schema[name] = sf;
  }

  bool InsertRow(RowCore row) {


    return true;
  };

  Rows Search(std::string key, UniversalUnion un) {
    Rows results;

    std::for_each(rows.begin(), rows.end(), [](auto row){
      // Match the "key" and collect the value in the "results" vector
    });

    return results;
  };
};

#endif // !DB_BUCKET

