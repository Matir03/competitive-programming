#include<bits/stdc++.h>
using namespace std;

int x[10], y[10];

int no1(int n)
{
    int k = 0;

    while(n>0)
    {
        k += n&1;
        n >>= 1;
    }

    return k;
}

int main()
{
    int t, n, i, j, mn, mx;
    bool good;

    int a[10] = {119, 96, 62, 124, 105, 93, 95, 100, 127, 125};

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(i=0;i<n;++i)
            cin >> x[i] >> y[i];

        mn = 8;
        mx = 0;

        for(i=0;i<128;++i)
        {
            good = true;

            for(j=0;j<n;++j)
            {
                if(no1(i & a[x[j]]) != y[j])
                {
                    good = false;
                    break;
                }
            }

            if(!good) continue;

            mn = min(mn, 7 - no1(i));
            mx = max(mx, 7 - no1(i));
        }

        if(mn == 8)
            cout << "invalid\n";
        else
            cout << mn << ' ' << mx << '\n';
    }
}
