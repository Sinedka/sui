#include "connector.h"
#include <iostream>
#include <span>

staticArr& get_list() {
  static staticArr list;
  return list;
}

extern "C" void create_array(int* arr) { get_list().arr = arr; }

extern "C" void resize(int size) { get_list().size = size; }

extern "C" void process_array(int changed) {
  std::span<int> s(get_list().arr, get_list().size);
  for(int v : s) std::cout << v << " ";
  std::cout << ":object " << changed << " changed\n";
}
