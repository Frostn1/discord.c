# Port Ranges
- Tcp 443
- Udp 50,000 - 65,535 (For voice)



-----------------
DeReference Of Void Pointers

#include <stdio.h>

struct dict {
  void* data;  
};
int main()
{
    struct dict dict1;
    int num = 10, num2 = 0;
    dict1.data = &num;
    num2 = *((int*)(dict1.data));
    printf("Hello World %d", (num2));

    return 0;
}
