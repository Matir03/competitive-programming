#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define K 10001

typedef long long ll;
typedef tuple<ll, ll, ll> pl;

ll dp1[K][K], dp2[K][K], d11[K][K], d12[K][K], d21[K][K], d22[K][K];
pl xy[K], rxy[K];

int main()
{
    ll T, n, m, k, i, j, x, y, t, l;

    cin >> T;

    while(T--)
    {
        cin >> n >> m >> k;

        for(i=0;i<k;++i)
        {
            cin >> x >> y >> t;

             xy[i] = tie(x,  y, t);
            rxy[i] = tie(x, -y, t);
        }
        xy[k] = pl(1, 1, 0);
        rxy[k] = pl(1, -1, 0);

        sort(xy, xy + k + 1);
        sort(rxy, rxy + k + 1);

        for(i=0;i<k;++i)
        {
            for(j=0;j<i;++j)
            {
                d11[i][j] = xy[i].X - xy[j].X + xy[i].Y-1 + xy[j].Y-1;
                d12[i][j] = xy[i].X - xy[j].X + M-xy[i].Y + M-xy[j].Y;

                d21[i][j] = rxy[i].X - rxy[j].X - rxy[i].Y-1 - rxy[j].Y-1;
                d22[i][j] = rxy[i].X - rxy[j].X + M+rxy[i].Y + M+rxy[j].Y;
            }
        }

        for(i=k;i>=0;--i)
        {
            for(j=0;j<=k-i;++j)
            {
                for(l=0)

            }
        }

    }
}
