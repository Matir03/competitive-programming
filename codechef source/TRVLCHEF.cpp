#include<bits/stdc++.h>
using namespace std;

int l[100000], h[100000];

int main()
{
    int t, n, d, c, ls, hs, m, i;
    bool g;

    ios_base::sync_with_stdio(false);

    cin >> t;

    while(t--)
    {
        cin >> n >> d;

        cin >> m;
        ls = hs = 0;

        for(i=1;i<n;++i)
        {
            cin >> c;

            if(c > m)
                h[hs++] = c;
            else
                l[ls++] = c;
        }

        sort(l, l + ls, greater<int>());
        sort(h, h + hs);

        for(i=1;i<ls;++i)
            if((l[i-1]-l[i]) > d) goto bad;

        for(i=1;i<hs;++i)
            if((h[i]-h[i-1]) > d) goto bad;

        if(ls == 0 || hs == 0) goto good;

        if((h[0]-l[0])>d) goto bad;

        if(ls == 1 || hs == 1) goto good;

        if((m-l[1])>d) goto bad1;

        for(i=0;i<ls-2;++i)
            if((l[i]-l[i+2])>d) goto bad1;

        goto good;

        bad1:

        if((h[1]-m)>d) goto bad;

        for(i=0;i<hs-2;++i)
            if((h[i+2]-h[i])>d) goto bad;

        good:

        cout << "YES\n";
        continue;

        bad:

        cout << "NO\n";
    }
}
