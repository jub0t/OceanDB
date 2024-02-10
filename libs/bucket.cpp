#ifndef DB_BUCKET
#define DB_BUCKET

#include <cstdint>
#include <stdint.h>
#include <unordered_map>
#include "./datatypes.cpp"
#include <string>

struct BucketSchemaField {
  uint64_t max_len;
  BucketDataTypes datatype;  
};

class Bucket {
public:
  std::unordered_map<std::string, BucketSchemaField> schema;
  bool strict_type;
  
  // HashMap<RowName, Row<Id, Data>
  std::unordered_map<uint64_t, std::unordered_map<std::string, BucketDataTypes>> rows;

  Bucket() {
    // this->strict_type = strict_type_checking;
  }

  void AppendType(std::string name, BucketSchemaField sf) {
    schema[name] = sf;
  }
};

#endif // !DB_BUCKET

