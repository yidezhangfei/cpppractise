#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <future>

using namespace std::chrono;

class FetchDataFromDB {
    public:
        std::string operator()(std::string recvData) {
            std::this_thread::sleep_for(std::chrono::seconds(5));
            auto result = "FromDB: " + recvData;
            return result;
        }
};

class FetchDataFromFile {
    public:
        std::string operator()(std::string recvData) {
            std::this_thread::sleep_for(std::chrono::seconds(7));
            auto result = "FromFile: " + recvData;
            return result;
        }
};


int main() {
    // get the start time
    system_clock::time_point start = system_clock::now();

    // fetch data from db
    std::future<std::string> dbfuture = std::async(FetchDataFromDB(), "Data");

    // fetch data from file
    std::future<std::string> file_future = std::async(FetchDataFromFile(), "Data");

    std::string from_db_result = dbfuture.get();

    std::string from_file_result = file_future.get();

    // get the end time
    auto end = system_clock::now();

    auto duration = duration_cast<std::chrono::seconds>(end - start).count();
    std::cout << "total time taken: " << duration << " seconds" << std::endl;

    std::cout << from_db_result << std::endl;
    std::cout << from_file_result << std::endl;
    return 0;
}