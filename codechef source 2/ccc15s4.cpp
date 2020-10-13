#include<bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> ti;

int bh[2001];
vector<ti> adj[2001];
priority_queue<ti, vector<ti>, greater<ti> > pq;

int main()
{
    int k, n, m, i, u, v, s, t, d, h, d2, h2;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> k >> n >> m;

    for(i=0;i<m;++i)
    {
        cin >> u >> v >> d >> h;

        adj[u].push_back(ti(d, h, v));
        adj[v].push_back(ti(d, h, u));
    }

    cin >> s >> t;

    for(i=1;i<=n;++i)
        bh[i] = k;

    pq.emplace(0, 0, s);

    while(!pq.empty())
    {
        tie(d, h, u) = pq.top();
        pq.pop();

        if(h >= bh[u]) continue;

        bh[u] = h;

        if(u == t)
        {
            cout << d;
            return 0;
        }

        for(auto edge : adj[u])
        {
            tie(d2, h2, v) = edge;
            pq.emplace(d + d2, h + h2, v);
        }
    }

    cout << -1;
    return 0;
}
