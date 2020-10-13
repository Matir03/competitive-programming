#include<iostream>
#include<ctime>

int main()
{
    int n = 0;

    clock_t tm = clock();
    while(clock()<tm+CLOCKS_PER_SEC)
    {
        ++n;
    }

    std::cout << n;
}
