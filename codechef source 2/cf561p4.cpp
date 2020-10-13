#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

ull r[100];

int main()
{
    int q, i;
    ull a, b, m, n, k, p, t, s;
    double c;

    ios_base::sync_with_stdio(false);

    cin >> q;

    while(q--)
    {
        cin >> a >> b >> m;

        n = (ull)floor(log2(b/(double)(a+1))) + 2;

        p = 1<<(n-2);

        c = (b/(double)p)-a;

        if(c>m || b<a)
        {
            cout << "-1\n";
            continue;
        }

        k = (ull)floor(c);

        t=b-(a+k)*p;

        for(i=2;i<n;++i)
        {
            p >>= 1;
            r[i] = k;

            if(p<=t)
            {
                t -= p;
                ++r[i];
            }
        }

        r[n] = k;
        if(t>=1) ++r[n];

        cout << n << ' ';

        cout << a << ' ';
        s = a;

        for(i=2;i<=n;++i)
        {
            cout << s + r[i] << ' ';
            s += s + r[i];
        }

        cout << '\n';
    }
}
