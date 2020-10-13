#include<bits/stdc++.h>
using namespace std;

int p[1001][1001], dpmin[1001][1001][22], dpmax[1001][1001][22];

int main()
{
    int t, n, m, i, j, k, K, a, b;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> m >> K;

        for(i=1;i<=n;++i)
        {
            for(j=1;j<=m;++j)
            {
                cin >> a;
                p[i][j] = p[i][j-1] + a;
            }
        }

        for(i=1;i<=n;++i)
        {
            for(j=1;j<=n;++j)
            {
                dpmin[i][j][0] = dpmin[i-1][j][0] + p[i][j-1];
                dpmax[i][j][0] = dpmax[i-1][j][0] + p[i][j];
            }
        }

        for(i=1;i<=n;++i)
        {
            for(j=1;j<=m;++j)
            {
                for(k=1;k<=K;++k)
                {
                    dpmin[i][j][k] = min(dpmin[i-1][j-1][k-1], dpmin[i-1][j][k]) + p[i][j-1];
                    dpmax[i][j][k] = max(dpmax[i-1][j-1][k-1], dpmax[i-1][j][k]) + p[i][j];
                }
            }
        }

        b = -1e9;

        for(i=1;i<m-K;++i)
        {
            for(j=i+K+1;j<=m;++j)
            {
                a = dpmax[n][j][K] - dpmin[n][i][K];
                if(a>b) b = a;
            }
        }

        cout << b << '\n';
    }
}
