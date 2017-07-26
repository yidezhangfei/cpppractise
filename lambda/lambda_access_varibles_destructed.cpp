#include <iostream>
#include <string>
#include <functional>

struct Counter {
    int a = 10;
};

std::function<void()> getCallBack() {
    Counter counter;

    auto func = [&counter] () mutable {
        std::cout << "Inside Lambda:: counter = " << counter.a << std::endl;

        counter.a = 20;

        std::cout << "Inside Lambda:: After changing :: counter = " << counter.a << std::endl;
    };

    return func;
}

int main(int argc, char** argv) {
    std::function<void()> func = getCallBack();

    func();

    return 0;
}