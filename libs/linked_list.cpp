#ifndef DB_LINKED_LIST
#define DB_LINKED_LIST

#include <unordered_map>
#include <string>

template<typename T>
class LinkedList {
public:
  T _me;
  T* _next;
  T* _prev;

  LinkedList() {}
  
  ~LinkedList() {
    if (this->_next != nullptr) {
        this->_next->_prev = this->_prev;
    }

    if (this->_prev != nullptr) {
        this->_prev->_next = this->_next;
    }
  }

  void Append(T item) {
    if (this->_next ==nullptr) {
      this->_next = item;
    } else {
      auto current = this->_next;
      
      // We Keep looping forward until we find a an item with an empty next spot
      while(current->_next != nullptr) {
        current = current->_next->_next;
      };

      current->_next = item;
    }
  };
};

enum BucketErrors {
  Success,
  AlreadyExists,
};

template<typename T>
class LLHolder {
  std::unordered_map<std::string, LinkedList<T>*> buckets;

public:
  typename std::unordered_map<std::string, LinkedList<T>*>::iterator GetBucket(std::string name) {
    return buckets.find(name);
  }

  BucketErrors CreateNewBucket(std::string name) {
    if (buckets[name] == nullptr) {
    buckets[name] = new LinkedList<T>();
      return BucketErrors::Success;
    } else {
      return BucketErrors::AlreadyExists;
    }
  }
};

#endif // !DEBUG
