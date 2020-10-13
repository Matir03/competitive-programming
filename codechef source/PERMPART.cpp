#include<bits/stdc++.h>
using namespace std;

int a[1000000];
int b[1000000], c[1000000];

int main()
{
    int t, n, i, l, m, j;

    ios_base::sync_with_stdio(false);

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(i=0;i<n;++i)
        {
            cin >> a[i];
            b[i] = 0;
            c[i] = 0;
        }

        sort(a, a+n);

        m = 0;
        l = 0;
        j = 0;
        for(i=0;i<n;++i)
        {
            if(a[i] == l)
            {
                ++j;
                if(j>m) m = j;
            }
            else
            {
                l = a[i];
                j = 0;
            }

            c[j]++;
            b[j] = max(b[j], 2*c[j] - l);
        }

        for(i=0;i<=m;++i)
            n -= b[i];

        cout << n << '\n';
    }
}
