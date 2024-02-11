// CUSTOM JSON-PARSER TO PROCESS SPECIAL TYPES LIKE "UniversalTypes" and "UniversalUnion"


#include <vector>
#include "./rows.cpp"

struct RowInfo {};
struct RowInput {
  RowInfo info;
  std::vector<Row> rows;
};

class UniversalJsonParser {
  ~UniversalJsonParser() {};

public:
  // Row<RowInfo, Vector<Row>>
  void ParseRows() {};
};
