#include<bits/stdc++.h>
using namespace std;

#define MAXN 300001

typedef long long ll;
typedef pair<int, int> pi;

int root[MAXN], lc[MAXN], rc[MAXN], root2[MAXN], lc2[MAXN], rc2[MAXN];
vector<int> adj[MAXN], adj2[MAXN], ch[MAXN];
bool vis[MAXN], vis2[MAXN];

void dfs(int v, int r)
{
    vis[v] = true;
    root[v] = r;

    lc[r] = min(v, lc[r]);
    rc[r] = max(v, rc[r]);

    for(auto c : adj[v])
        if(!vis[c]) dfs(c, r);
}

void dfs2(int v, int r)
{
    vis2[v] = true;
    root2[v] = r;

    lc2[r] = min(lc[v], lc2[r]);
    rc2[r] = max(rc[v], rc2[r]);

    for(auto c : adj2[v])
        if(!vis2[c]) dfs2(c, r);
}

ll cnt(int r)
{
    ll tot = 0, run = 0;
    int pr = 0;

    for(auto c : ch[r])
    {
        tot += cnt(c);

        if(lc2[c] == pr+1)
            ++run;
        else
            run = 1;

        pr = rc2[c];
        tot += run;
    }

    return tot;
}

int main()
{
    int N, M, R, R2, i, a, b, k;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for(i=1;i<=M;++i)
    {
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    k = 0;
    for(i=1;i<=N;++i)
    {
        if(vis[i]) continue;

        lc[k] = rc[k] = i;
        dfs(i, k);
        ++k;
    }
    R = k;

    stack<int> stk;

    for(i=0;i<R;++i)
    {
 //       cout << lc[i] << ' ' << rc[i] << '\n';
        while(true)
        {
            if(stk.empty()) break;
            if(rc[stk.top()] > lc[i]) break;

            stk.pop();
        }

        while(!stk.empty())
        {
            if(rc[stk.top()] < rc[i])
            {
                adj2[stk.top()].push_back(i);
                adj2[i].push_back(stk.top());

                stk.pop();
            }
            else break;
        }

        stk.push(i);
    }

    k = 0;
    for(i=0;i<R;++i)
    {
        if(vis2[i]) continue;

        lc2[k] = lc[i];
        rc2[k] = rc[i];
        dfs2(i, k);
        ++k;
    }
    R2 = k;

    while(!stk.empty()) stk.pop();

    for(i=0;i<R2;++i)
    {
 //       cout << lc2[i] << ' ' << rc2[i] << '\n';

        while(true)
        {
            if(stk.empty()) break;
            if(rc2[stk.top()] > lc2[i]) break;

            stk.pop();
        }

        if(stk.empty())
            ch[R2].push_back(i);
        else
            ch[stk.top()].push_back(i);

        stk.push(i);
    }

    cout << cnt(R2);

    return 0;
}
