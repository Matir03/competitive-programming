#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n;

    cin >> t;

    while(t--)
    {
        cin >> n;

        cout << ((1<<n) + ((n&1)<<1) - 1) / 3 << ' ';
        cout << (1<<n) << ' ';
    }

    return 0;
}
