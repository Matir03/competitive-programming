#include<iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int t, k;
    long long n;

    cin >> t;

    while(t--)
    {
        cin >> n >> k;

        if(n==2)
        {
            cout << "0.5\n";
            continue;
        }

        if((n%4) == 2 && k == 1)
        {
            cout << (1.0)/((n+2)>>1) << '\n';
            continue;
        }

        if(k>64)
        {
            cout << "1\n";
            continue;
        }

        while(k--)
        {
            n = (n+1)>>1;
            if(n==1) break;
        }

        cout << (1.0/n) << '\n';
    }

    return 0;
}
