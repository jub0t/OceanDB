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

class Bucket {
public:
  std::unordered_map<std::string, BucketSchemaField> schema;
  bool strict_type;
  
  // HashMap<Id, Row<RowName, Data>
  std::unordered_map<uint64_t, RowCore> rows;

  Bucket() {
    // this->strict_type = strict_type_checking;
  }

  void AppendType(std::string name, BucketSchemaField sf) {
    schema[name] = sf;
  }

  Rows Search(std::string key, UniversalUnion) {
    Rows results;

    std::for_each(rows.begin(), rows.end(), [](auto row){
      // Match the "key" and collect the value in the "results" vector
    });

    return results;
  };
};

#endif // !DB_BUCKET

