#include <thread>
#include <iostream>
#include <vector>
#include <mutex>
#include <condition_variable>

class Application {

public:
    Application() {
        m_loadData = false;
    }
    void LoadData() {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << "Loading Data From Xml" << std::endl;
        // lock the data structure.
        std::lock_guard<std::mutex> guard(m_mutex);
        m_loadData = true;
        // m_condVar.notify_one();     // notify_one notice only a thread which wait for mutex in order.
         m_condVar.notify_all();
    }
    bool isDataLoaded() {
        return m_loadData;
    }
    void MainTask() {
        std::unique_lock<std::mutex> mlock(m_mutex);
        m_condVar.wait(mlock, std::bind(&Application::isDataLoaded, this));
        std::cout << "do processing on loaded data" << std::endl;
    }

private:
    bool m_loadData;
    std::mutex m_mutex;
    std::condition_variable m_condVar;

};

int main() {
    Application app;
    std::thread thread1(&Application::MainTask, &app);
    std::thread thread3(&Application::MainTask, &app);
    std::thread thread2(&Application::LoadData, &app);
    thread1.join();
    thread2.join();
    thread3.join();
    return 0;
}