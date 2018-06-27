#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <future>

using namespace std::chrono;

std::string fetchDataFromDB(std::string data) {
    std::this_thread::sleep_for(std::chrono::seconds(6));   // suppose prossing.
    return "DB" + data;
}

std::string fectchDataFromFile(std::string data) {
    std::this_thread::sleep_for(std::chrono::seconds(5));   // suppose prossing.
    return "File" + data;
}

int main() {
    // get the start time
    system_clock::time_point start = system_clock::now();

    std::future<std::string> resultFromDBFuture = std::async(std::launch::async, &fetchDataFromDB, "data");

    // fetch data from file
    std::string resultFromFile = fectchDataFromFile("data");

    // fetch data from db
    std::string resultFromDB = resultFromDBFuture.get();

    // get the end time
    auto end = system_clock::now();

    auto diff = duration_cast<std::chrono::seconds>(end - start).count();
    std::cout << "total time taken: " << diff << "seconds" << std::endl;

    std::string data = resultFromDB + "::" + resultFromFile;

    std::cout << data << std::endl;
    return 0;
}