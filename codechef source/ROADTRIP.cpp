#include<bits/stdc++.h>
using namespace std;

int mus[1000001];
bool vis[1000001];
vector<int> mc;
vector<int> e[1000001];

int DFS(int r)
{
    if(vis[r]) return 0;
    vis[r] = true;

    int tm = mus[r];

    for(auto nb : e[r])
        tm += DFS(nb);

    return tm;
}

int main()
{
    int t, n, m, k, i, u, v, r;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> m >> k;

        for(i=1;i<=n;++i)
        {
            e[i].clear();
            vis[i] = false;
        }

        r = 0;
        mc.clear();

        for(i=0;i<m;++i)
        {
            cin >> u >> v;

            e[u].push_back(v);
            e[v].push_back(u);
        }

        for(i=1;i<=n;++i)
            cin >> mus[i];

        for(i=1;i<=n;++i)
            if(!vis[i])
                mc.push_back(DFS(i));

        if(k>mc.size())
        {
            cout << "-1\n";
            continue;
        }

        sort(mc.begin(), mc.end());

        for(i=0;i<k/2;++i)
            r += mc[i];

        for(i=0;2*i<k;++i)
            r += mc[mc.size()-i-1];

        cout << r << '\n';
    }
}
