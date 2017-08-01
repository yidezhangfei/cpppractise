#include <iostream>
#include <vector>

#include "template.hpp"

int main(int argc, char* argv[]) {
    std::vector<int> int_vector = { 1, 2, 3, 4 };
    std::vector<std::string> str_vector = { "I", "LOVE", "YOU" };

    print_vector(int_vector);
    print_vector(str_vector);

    int a = 0;
    int b = 3;
    b = a++;
    std::cout << b << std::endl;
    std::cout << a << std::endl;
}}