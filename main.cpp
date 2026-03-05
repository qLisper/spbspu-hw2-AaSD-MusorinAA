#include <iostream>
template<class T>
T* unique(T* a, size_t& s) {
  if (s == 0 || a == nullptr) {
    s = 0;
    return nullptr;
  }
  T* result = new T[s];  // T должен иметь конструктор по умолчанию
  size_t uniqueCount = 0;
  for (size_t i = 0; i < s; ++i) {
    bool found = false;
    for (size_t j = 0; j < uniqueCount; ++j) {
      // T должен поддерживать operator==
      if (result[j] == a[i]) {
        found = true;
        break;
      }
    }
    if (!found) {
      // T должен поддерживать оператор присваивания
      result[uniqueCount] = a[i];
      ++uniqueCount;
    }
  }
  s = uniqueCount;
  return result;  // должен быть delete[]
}
