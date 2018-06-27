#include <thread>
#include <mutex>
#include <iostream>
#include <vector>

class Wallet {

public:
    Wallet():m_money(0) {}
    ~Wallet() = default;
    int getMoney() { return m_money; }
    void addMoney(int money) {
        std::lock_guard<std::mutex> guard(m_mutex);
        for (int i = 0; i < money; i++) {
            m_money += 1;
        }
    }

private:
    std::mutex m_mutex;
    int m_money = 0;

};

int testRaceCondition() {
    Wallet wallet;
    std::vector<std::thread> threads;

    for (int i = 0; i < 5; i++) {
        threads.push_back(std::thread(&Wallet::addMoney, &wallet, 1000));
    }

    for (int i = 0; i < threads.size(); i++) {
        threads.at(i).join();
    }
    return wallet.getMoney();
}

int main() {
    int val = 0;
    for (int k = 0; k < 1000; k++) {
        if ((val = testRaceCondition()) != 5000) {
            std::cout << "error at count = " << k << "money in wallet =" << val << std::endl;
        }
    }
    std::cout << "corrent money in wallet = " << val << std::endl;
    return 0;
}