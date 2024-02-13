#include <iostream>
#include "../libs/ocean.cpp"
#include "../libs/debugger.cpp"
#include "../libs/json_parser.cpp"

int main() {
  DatabaseOcean ocean;
  OceanDebugger debug;

  bool success = ocean.CreateNewBucket("users");
  std::cout << "Success: " << success << "\n";

  bool success_new = ocean.CreateNewBucket("users");
  std::cout << "Success: " << success_new << "\n";

  Bucket* users_bucket = ocean.GetBucket("users");

  for (int i; i < 8; i++) {
    RowCore row;

    UniversalUnion val = UniversalUnion{0};
    val.int_val = 100;
    row["UserId"] = val;

    UniversalUnion age = UniversalUnion{0};
    age.float_val = 18.0;
    row["Age"] = age;

    users_bucket->InsertRow(row);
  }
  
  std::cout << users_bucket->row_count << "\n";

  for (int i = 0; i < users_bucket->row_count; i++) {
    RowCore row = users_bucket->rows[i];
    // debug.DebugRows(row);
  }

  std::cout << "Rows Proccessed!" << "\n";
  OceanJsonParser json;
  RowInput ri;

  ri.rows = &users_bucket->rows;
  ri.schema = &users_bucket->schema;
  
  std::string parsed = json.ParseRows(ri);
  std::cout << parsed << "\n";


  int i;
  while (true) {
    std::cin >> i;
  };

  return 0;
}
