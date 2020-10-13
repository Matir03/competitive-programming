#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i;

    clock_t intime = clock();

    while(++i < 1000000000);

    cout << (clock()-intime)/(double)CLOCKS_PER_SEC;
}
