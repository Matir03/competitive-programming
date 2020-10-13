#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MAX 500001

typedef long long ll;
typedef vector<ll> vl;

int N, K;
ll nCk[11][11], ans, pt[32];
vector<int> adj[MAX];
vl sts[MAX], ts[MAX];

vl incr(vl sums)
{
    vl nsums(K+1, 0);
    int i, j;

    for(i=0;i<=K;++i)
        for(j=0;j<=i;++j)
        {
            nsums[i] += nCk[i][j]*sums[j];
            nsums[i] %= MOD;
        }

    return nsums;
}

vl vlsum(vl a, vl b)
{
    int i;
    vl t(K+1,0);

    for(i=0;i<=K;++i)
        t[i] = (a[i] + b[i]) % MOD;

    return t;
}

vl vldiff(vl a, vl b)
{
    int i;
    vl t(K+1,0);

    for(i=0;i<=K;++i)
        t[i] = (a[i] + MOD - b[i]) % MOD;

    return t;
}

void dfs1(int v, int p)
{
    sts[v] = vl(K+1,0);

    if(adj[v].size() == 1)
        sts[v][0] = 1;

    for(auto c : adj[v])
    {
        if(c == p) continue;

        dfs1(c, v);

        sts[v] = vlsum(sts[v], incr(sts[c]));
    }
}

void dfs2(int v, int p)
{
    if(adj[v].size() == 1)
    {
        ans += ts[v][K];
        ans %= MOD;
    }

    for(auto c : adj[v])
    {
        if(c == p) continue;

        ts[c] = vlsum(sts[c], incr(vldiff(ts[v], incr(sts[c]))));

        dfs2(c, v);
    }
}

ll pot(int xp)
{
    ll r = 1, b = 0;

    while(xp > 0)
    {
        if(xp & 1)
            r = (r*pt[b]) % MOD;

        ++b;
        xp >>= 1;
    }

    return r;
}

int main()
{
    int T, i, j, k, a, b;

 //   ios_base::sync_with_stdio(false);
 //   cin.tie(0);

    for(i=0;i<=10;++i)
        nCk[i][0] = 1;

    for(i=1;i<=10;++i)
        for(j=1;j<=i;++j)
            nCk[i][j] = nCk[i-1][j] + nCk[i-1][j-1];

    pt[0] = 2;

    for(i=1;i<32;++i)
        pt[i] = (pt[i-1]*pt[i-1]) % MOD;

    cin >> T;

    while(T--)
    {
        cin >> N >> K;

        for(i=1;i<=N;++i)
        {
            adj[i].clear();

        }

        for(i=1;i<N;++i)
        {
            cin >> a >> b;

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        ans = 0;
        dfs1(1, 0);
        ts[1] = sts[1];
        dfs2(1, 0);

        if(ans % 2 == 0)
            ans /= 2;
        else
            ans = (ans + MOD)/2;

        cout << ans << ' ';
        cout << ((K == 1 && ts[1][0] == 2) ? pot(N-2) : 1) << '\n';
    }
}
