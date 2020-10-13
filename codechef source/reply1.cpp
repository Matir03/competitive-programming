#include<bits/stdc++.h>
using namespace std;

#define M 100003
#define INF 1000000000

int xin[2000], xout[2000], yin[2000], yout[2000];
bool act[2000];

int main()
{
    int t, x, y, x0, y0, n, i, a, d, bd, bi, td, c;

    freopen("C:\\Users\\Ritam\\Downloads\\input-teleportation-0115.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;

    for(c=1;c<=t;++c)
    {
        cin >> x >> y;
        cin >> x0 >> y0;

        cin >> n;

        for(i=0;i<n;++i)
        {
            cin >> xin[i] >> yin[i] >> xout[i] >> yout[i];
            act[i] = true;
        }

        a = n;
        td = 0;

        while(a--)
        {
            bd = INF;

            for(i=0;i<n;++i)
            {
                if(!act[i]) continue;

                d = abs(xin[i]-x0)+abs(yin[i]-y0);

                if(d < bd)
                {
                    bi = i;
                    bd = d;
                }
                else if(d == bd)
                {
                    if(xin[i]<xin[bi])
                    {
                        bi = i;
                        bd = d;
                    }
                    else if(xin[i] == xin[bi])
                    {
                        if(yin[i]<yin[bi])
                        {
                            bi = i;
                            bd = d;
                        }
                    }
                }
            }

            act[bi] = false;
            td += bd;
            td %= M;
            x0 = xout[bi];
            y0 = yout[bi];
        }

        cout << "Case #" << c << ": " << td << '\n';
    }
}
