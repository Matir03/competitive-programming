#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
typedef pair<pi,  int> ppi;

vector<int> sl[1001];
int v[1001], p[1001], b[1001], tv[1001];
vector<int> dp[1001][1002];

int main()
{
    int n, m, pb, i, j, k, mp;

    ios_base::sync_with_stdio(false);

    cin >> n >> m >> pb;

    for(i=1;i<=m;++i)
        sl[i] = vector<int>();

    for(i=1;i<=n;++i)
    {
        cin >> k >> p[i] >> v[i];
        sl[k].push_back(i);
        tv[k] += v[i];
    }

    for(i=1;i<=m;++i)
    {
        cin >> b[i];
        dp[0][i] = vector<int>(1001, 0);
    }

    for(mp=1;mp<=pb;++mp)
    {
        dp[mp][1].push_back(0);

        for(i=1;i<=m;++i)
        {
            for(j=0;j<sl[i].size();++j)
            {
                dp[mp][i].push_back(dp[mp][i][j]);

                if(mp>=p[sl[i][j]])
                    dp[mp][i][j+1] = max(dp[mp][i][j], v[sl[i][j]] + dp[mp-p[sl[i][j]]][i][j]);
            }

            dp[mp][i+1].push_back(dp[mp][i][sl[i].size()]);
            if(mp>=b[i])
                dp[mp][i+1][0] = max(dp[mp][i+1][0], tv[i] + dp[mp-b[i]][i][0]);
        }
    }

    cout << dp[pb][m+1][0];
}
