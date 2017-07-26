#include <iostream>
#include <sstream>
#include <stdio.h>
using namespace std;

int hex2int(const string& hexStr)
{
    char *offset;
    if(hexStr.length() > 2)
    {
        if(hexStr[0] == '0' && hexStr[1] == 'x')
        {
            return strtol(hexStr.c_str(), &offset, 0);
        }
    }
    return strtol(hexStr.c_str(), &offset, 16);
}
 
int main()
{
    char dict[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
    string s;
    s = "13102";
    char x[3];
    x[0] = dict[10 >> 2 & 0xf];
    x[1] = dict[(15) - (10 ^ 9)];
    x[2] = dict[(139 | 193) % 5];
    
    int ret = hex2int(x);
    std::stringstream ss;
    std::string str;
    ss<<ret;
    ss>>str;
    
    s = s.insert(2, str);
    for (int i = s.length(); i > 0; i--) {
        cout<<s[i - 1];
    }
}