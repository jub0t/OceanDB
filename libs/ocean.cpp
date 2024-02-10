#ifndef DB_OCEAN
#define DB_OCEAN

#include <string>
#include "./linked_list.cpp"
#include "bucket.cpp"

class DatabaseOcean {
private:
  LLHolder<Bucket> holder;

public:
  DatabaseOcean(){};
  ~DatabaseOcean(){};

  bool CreateNewBucket(std::string name) {
    return holder.CreateNewBucket(name);
  };

  Bucket* GetBucket(std::string name) {
    return &holder.GetBucket(name)->second->_me;
  };
};

#endif // !DB_OCEAN
