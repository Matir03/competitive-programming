#include<bits/stdc++.h>
using namespace std;

#define MAX 500001
#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> pi;

int d[MAX];
ll occ[MAX], occ1[MAX];
bool vis[MAX];

vector<int> adj[MAX];
queue<int> fringe;

int main()
{
    int N, M, i, u, v;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for(i=1;i<=M;++i)
    {
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vis[1] = true;
    d[1] = 0;
    occ[1] = 1;
    occ1[1] = 0;
    fringe.push(1);

    while(!fringe.empty())
    {
        v = fringe.front();
        fringe.pop();

        for(auto x : adj[v])
        {
            if(!vis[x])
            {
                vis[x] = true;
                occ[x] = occ[v];
                d[x] = d[v] + 1;
                occ1[x] = 0;
                fringe.push(x);
            }
            else if(d[x] == d[v] + 1)
            {
                occ[x] += occ[v];
                occ[x] %= MOD;
            }
            else if(d[x] == d[v])
            {
                occ1[x] += occ[v];
                occ1[x] %= MOD;
            }
            else if(d[v] == d[x] + 1)
            {
                occ1[v] += occ1[x];
                occ1[v] %= MOD;
            }
        }
    }

    for(i=1;i<=N;++i)
        cout << (occ[i] + occ1[i]) % MOD << '\n';

    return 0;
}
