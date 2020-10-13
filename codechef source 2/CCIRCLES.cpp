#include<bits/stdc++.h>
using namespace std;

long long x[1000], y[1000], r[1000];
long double mn[1000000], mx[1000000];

int main()
{
    int n, q, k=0, i, j, m, t, l;

    cin >> n >> q;

    for(i=0;i<n;++i)
    {
        cin >> x[i] >> y[i] >> r[i];

        for(j=0;j<i;++j)
        {
            mx[k] = sqrt( (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) ) + r[i] + r[j];
            mn[k] = mx[k] - 2*r[i] - 2*r[j];
            if(mn[k]<0) mn[k] = -mn[k] - 2*min(r[i], r[j]);
            ++k;
        }
    }

    sort(mn, mn + k);
    sort(mx, mx + k);

    while(q--)
    {
        cin >> l;

        i = 0;
        j = k;

        while(i<j)
        {
            m = (i+j)/2;

            if(mn[m]<=l)
                i = m+1;
            else
                j = m;
        }

        t = i;

        i = 0;
        j = k;

        while(i<j)
        {
            m = (i+j)/2;

            if(mx[m]<l)
                i = m+1;
            else
                j = m;
        }

        cout << t-i << '\n';
    }
}
