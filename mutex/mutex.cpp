#include <iostream>
#include <map>
#include <string>
#include <chrono>
#include <thread>
#include <mutex>

std::map<std::string, std::string> g_pages;
std::mutex g_pages_mutex;

void save_page(const std::string &url) {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::string result = "fake content";

    std::lock_guard<std::mutex> guad(g_pages_mutex);

    g_pages[url] = result;
}

int main() {
    std::thread save_page_thread1(save_page, "http://foo/");
    std::thread save_page_thread2(save_page, "http://bar/");
    save_page_thread1.join();
    save_page_thread2.join();
    for (auto& pair : g_pages) {
        std::cout << pair.first << "=>" << pair.second << std::endl;
    }
    return 0;
}