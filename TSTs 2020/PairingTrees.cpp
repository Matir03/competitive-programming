#include<bits/stdc++.h>
using namespace std;

#define MAX 500001
#define INF 1000000000

vector<int> adj[MAX], prt[MAX], ch[MAX];
int N, fo[MAX], lo[MAX], ci, bs = INF, sz[MAX], ie[MAX], c2v[MAX], val[MAX];
vector<int> et;

void getet(int v, int p)
{
    ++ci;
    c2v[ci] = v;
    fo[v] = et.size();
    et.push_back(ci);

    for(auto u : adj[v])
    {
        if(u != p)
        {
            getet(u, v);

            lo[v] = et.size();
            et.push_back(ci);

            ch[v].push_back(u);
        }
    }
}

void dfs(int v)
{
    int ee = ie[v], bie = 0, tie = 0, oie;
    sz[v] = 1;

    for(auto u : ch[v])
    {
        dfs(u);
        sz[v] += sz[u];
        ie[v] += ie[u];
        tie += ie[u];
        bie = max(bie, ie[u]);
        ee += sz[u] - 2*ie[u];
    }

    oie = N+2*ie[v]-2*sz[v];
    bie = max(bie, oie);
    tie += oie;

    if(2*bie <= tie)
        bs = min(bs, (tie+1)/2);
}

int RMQ(int node, int x, int y, int l, int r)
{
    if(r<x || l>y) return INF;

    if(x<=l && r<=y) return val[node];

    int m = (l+r)/2;
    return min(RMQ(node*2, x, y, l, m), RMQ(node*2+1, x, y, m+1, r));
}

int LCA(int u, int v)
{
    int m = RMQ(1, min(fo[u], fo[v]), max(lo[u], lo[v]), 0, et.size()-1);
    return c2v[m];
}

void getvals(int node, int l, int r)
{
    if(l==r)
    {
        val[node] = et[l];
        return;
    }

    int m = (l+r)/2;

    getvals(node*2, l, m);
    getvals(node*2+1, m+1, r);

    val[node] = min(val[node*2], val[node*2+1]);
}


int main()
{
    int i, u, v;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for(i=1;i<N;++i)
    {
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    getet(1, 0);
    getvals(1, 0, et.size()-1);

    for(i=1;2*i<=N;++i)
    {
        cin >> u >> v;

        prt[u].push_back(v);
        prt[v].push_back(u);

        ie[LCA(u,v)]++;
    }

    dfs(1);

    cout << bs;
}
