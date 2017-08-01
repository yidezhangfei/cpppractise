#pragma once

#include <vector>
#include <string>
#include <iostream>

template <typename T>
void print_vector(const std::vector<T>& vector_to_print) {

  std::vector<T>::const_iterator iter = vector_to_print.begin();
  for (;iter != vector_to_print.end(); iter++) {
      std::cout << *iter << std::endl;
  }
}