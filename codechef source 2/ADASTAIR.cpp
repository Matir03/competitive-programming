#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int t, n, hi, hf, a;
    double k;
    cin >> t;

    while(t--)
    {
        cin >> n >> k;
        hi = 0;
        a = 0;

        while(n--)
        {
            cin >> hf;

            a += ceil((hf-hi)/k) - 1;
            hi = hf;
        }

        cout << a << '\n';
    }
}
