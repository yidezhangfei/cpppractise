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
    int a[5] = {1, 2, 3, 4, 5};
    int *ptr = (int*)(&a+1);
    printf("%d, %d", *(a+1), *(ptr-1));
    return 0;
}