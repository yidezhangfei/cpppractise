#include <memory>
#include <iostream>

#include "custom_del_template.hpp"

struct Sample {
    Sample() {
        std::cout << "constructor called" << std::endl;
    }
    ~Sample() {
        std::cout << "destructor called" << std::endl;
    }
};

int main(int argc, char* argv[]) {
    std::shared_ptr<int> int_ptr_array = make_shared_ptr_array<int>(8);
    std::shared_ptr<int> int_ptr = make_shared_ptr<int>();
    std::shared_ptr<Sample> sample_array = make_shared_ptr_array<Sample>(10);
    return 0;
}