#include <iostream>
#include <thread>
#include <future>

void initializer(std::promise<int>* promise) {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Inside thread" << std::endl;
    promise->set_value(35);
}

int main() {
    std::promise<int> promise;
    std::future<int> future = promise.get_future();
    std::thread thread(&initializer, &promise);
    std::cout << "wait" << std::endl;
    thread.join();
    std::cout << "future is: " << future.get() << std::endl; // thread block until future has been set value.
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return 0;
}