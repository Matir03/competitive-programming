#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int adj[900][900][13];

int main()
{
    int t, n, m, k, q, i, u, v;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> m >> k;

        for(i=0;i<m;++i)
        {
            cin >> u >> v;

            adj[u][v][0] = 1;
        }
    }
}
