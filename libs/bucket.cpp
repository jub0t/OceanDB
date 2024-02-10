#ifndef DB_BUCKET
#define DB_BUCKET

#include <algorithm>
#include <cstdint>
#include <stdint.h>
#include <unordered_map>
#include "./datatypes.cpp"
#include <string>
#include <vector>
#include <iostream>

struct BucketSchemaField {
  uint64_t max_len;
  BucketDataTypes datatype;  
};

class Bucket {
public:
  std::unordered_map<std::string, BucketSchemaField> schema;
  bool strict_type;
  
  // HashMap<Id, Row<RowName, Data>
  std::unordered_map<uint64_t, std::unordered_map<std::string, BucketDataTypes>> rows;

  Bucket() {
    // this->strict_type = strict_type_checking;
  }

  void AppendType(std::string name, BucketSchemaField sf) {
    schema[name] = sf;
  }

  std::vector<std::unordered_map<std::string, BucketDataTypes>> Search(std::string key, Data ) {
    std::vector<std::unordered_map<std::string, BucketDataTypes>> results;

    std::for_each(rows.begin(), rows.end(), [](auto row){
      std::cout << row.second.find("") << "\n";
    });

    return results;
  };
};

#endif // !DB_BUCKET

