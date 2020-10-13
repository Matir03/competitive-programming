#include<bits/stdc++.h>
using namespace std;

bool r[1000001], c[1000001];

int main()
{
    int t, n, k, i, x, y;

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> k;

        for(i=1;i<=n;++i)
            r[i] = c[i] = false;

        for(i=0;i<k;++i)
        {
            cin >> x >> y;
            r[x] = c[y] = true;
        }

        k = n-k;
        cout << k;

        x = 1; y = 1;

        while(k--)
        {
            while(r[x]) ++x;
            while(c[y]) ++y;

            cout << ' ' << x << ' ' << y;

            ++x; ++y;
        }

        cout << '\n';
    }
}
