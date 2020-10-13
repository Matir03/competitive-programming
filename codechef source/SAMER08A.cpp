#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

int ds[500], dt[500];
vector<pi> ein[500], eout[500];
bool vis[500];

priority_queue<pi, vector<pi>, greater<pi> > pq;

int main()
{
    int n, m, s, t, u, v, w, i, d;
    bool good;

    while(true)
    {
        cin >> n >> m;

        if(n == 0 && m == 0) return 0;

        cin >> s >> t;

        for(i=0;i<n;++i)
        {
            ds[i] = 0;
            dt[i] = 0;
            ein[i].clear();
            eout[i].clear();
            vis[i] = false;
        }

        for(i=0;i<m;++i)
        {
            cin >> u >> v >> w;

            eout[u].push_back(pi(w, v));
             ein[v].push_back(pi(w, u));
        }

        while(!pq.empty()) pq.pop();
        pq.emplace(0, s);

        while(!pq.empty())
        {
            d = pq.top().first;
            u = pq.top().second;
            pq.pop();

            if(ds[u] > 0) continue;
            ds[u] = d;

            for(auto nb : eout[u])
            {
                w = nb.first;
                v = nb.second;

                pq.emplace(d+w, v);
            }
        }

        pq.emplace(0, t);

        while(!pq.empty())
        {
            d = pq.top().first;
            u = pq.top().second;
            pq.pop();

            if(dt[u] > 0) continue;
            dt[u] = d;

            for(auto nb : ein[u])
            {
                w = nb.first;
                v = nb.second;

                pq.emplace(d+w, v);
            }
        }

        pq.emplace(0, s);
        good = false;

        while(!pq.empty())
        {
            d = pq.top().first;
            u = pq.top().second;
            pq.pop();

            if(vis[u]) continue;
            vis[u] = true;

            if(u == t)
            {
                cout << d << '\n';
                good = true;
                break;
            }

            for(auto nb : eout[u])
            {
                w = nb.first;
                v = nb.second;

                if(ds[u] + dt[v] + w > ds[t])
                    pq.emplace(d+w, v);
            }
        }

        if(!good) cout << "-1\n";
    }
}
