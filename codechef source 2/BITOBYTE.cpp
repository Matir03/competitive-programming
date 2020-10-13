#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int t, n, x;
    long long c;

    cin >> t;

    while(t--)
    {
        cin >> n;
        --n;

        c = pow(2, floor(n/26));
        x = n % 26;

        if(x<2)
            cout << c << " 0 0\n";
        else if(x<10)
            cout << "0 " << c << " 0\n";
        else
            cout << "0 0 " << c << '\n';
    }
}
