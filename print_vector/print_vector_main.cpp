#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main(int argc, char* argsv[]) {
   std::vector<int> int_vector = { 1, 2, 3, 4 };
   std::vector<std::string> str_vector = { "I", "LOVE", "YOU" };

   auto print_vector = [] (auto& iter) {
       std::cout << iter << std::endl;
   };
   
   std::for_each(int_vector.begin(), int_vector.end(), print_vector);

   std::for_each(str_vector.begin(), str_vector.end(), print_vector); 
}