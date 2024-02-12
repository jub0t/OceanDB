#include <iostream>
#include "../libs/ocean.cpp"
#include "../libs/debugger.cpp"

int main() {
  DatabaseOcean ocean;
  OceanDebugger debug;

  bool success = ocean.CreateNewBucket("users");
  std::cout << "Success: " << success << "\n";

  bool success_new = ocean.CreateNewBucket("users");
  std::cout << "Success: " << success_new << "\n";

  Bucket* users_bucket = ocean.GetBucket("users");

  for (int i = 0; i < users_bucket->rows.size(); i++) {
    RowCore row = users_bucket->rows[i];
    debug.DebugRows(row);
  }

  return 0;
}
