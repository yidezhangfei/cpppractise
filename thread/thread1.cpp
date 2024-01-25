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

void thread_functionB() {
    for (int i = 0; i < 10000; i++) {
        std::cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX    " << i << std::endl;
    }
}

class WorkerThread {
    public:
        void operator()() {
            for (int i = 0; i < 10; i++) {
                std::cout << "Worker Thread Executing" << std::endl;
                std::cout << "thread ID: " << std::this_thread::get_id() << std::endl;
            }
        }

};

// 经过大量的注释打开，std::thread 对象一旦创建，线程就会跑起来，std::thread.join 表示当子线程退出时主线程才退出
int main() {
    //std::thread threadObj((thread_function));
    //std::thread threadObjB(thread_functionB);
    WorkerThread workerObj;
    std::thread threadObjC{workerObj};
    // threadObj.join();      // Program will terminate as we have't called either join or detach with the std::thread object.
    // Hence std::thread's object destructor will terminate the program
    // threadObj.join();
    // threadObj.join();
    // threadObj.detach();
    // threadObj.detach();  // join or detach twise will cass program terminate both;
    //ThreadRATI wrapperObj(threadObj);
    //wrapperObj.join();
    //threadObjB.join();            // 这个注释掉后，预期输出不了最后一个数, 果然，只输出到7090
    threadObjC.join();
    return 0;
}