#include <thread>
#include <iostream>
#include <algorithm>

class ThreadRATI {
    public:
        ThreadRATI(std::thread& threadObj) : m_thread(threadObj) {

        }
        ~ThreadRATI() {
            // check if thread is joinable thaen detach the thread
            if (m_thread.joinable()) {
                m_thread.detach();
            }
        }
        void join() {
            m_thread.join();
        }
        std::thread& m_thread;

};

void thread_function() {
    for (int i = 0; i < 10000; i++) {
        std::cout << "thread_function Executing" << std::endl;
    }
}

class WorkerThread {
    public:
        void operator()() {
            std::cout << "Worker Thread" << std::endl;
        }

};

int main() {
    std::thread threadObj(thread_function);
    // threadObj.join();      // Program will terminate as we have't called either join or detach with the std::thread object.
    // Hence std::thread's object destructor will terminate the program
    // threadObj.join();
    // threadObj.join();
    // threadObj.detach();
    // threadObj.detach();  // join or detach twise will cass program terminate both;
    ThreadRATI wrapperObj(threadObj);
    wrapperObj.join();
    return 0;
}