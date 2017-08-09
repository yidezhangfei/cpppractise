#include <iostream>
#include <memory>

class Encrypto {
    public:
    Encrypto() {
        m_isIncremental = false;
        m_count = 0;
    }
    Encrypto(bool isIncremental, int count) {
        m_isIncremental = isIncremental;
        m_count = count;
    }

    std::string operator()(std::string data) {
        for (auto& letter : data) {
            if ((letter >= 'a' && letter <= 'z') ||
              (letter >= 'A' && letter <= 'Z')) {
                  if (m_isIncremental) {
                      letter ++;
                  } else {
                      letter --;
                  }
              }
        }
        return data;
    }
    private:
    bool m_isIncremental;
    int m_count = 1;
};

std::string BuildCompleteMessage(std::string rawData,
    Encrypto encryptoFunctor) {
    return encryptoFunctor(rawData);        
}

int main(int argc, char* argv[]) {
    Encrypto encryptoFunctor(true, 1);
    std::string input = "Example";
    std::cout << "input string: " << input.c_str() << std::endl;
    std::cout << "Encrypted string: " << BuildCompleteMessage(input, encryptoFunctor).c_str() << std::endl;
}