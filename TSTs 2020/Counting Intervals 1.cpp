#include<bits/stdc++.h>
using namespace std;

#define MAX 600002

typedef long long ll;
typedef pair<int, int> pi;

int a[MAX], b[MAX], lc[MAX], rc[MAX];
pi ai[MAX], bi[MAX];
vector<int> ch[MAX], adj[MAX];
bool vis[MAX], nb[MAX];

void dfs(int v, int r)
{
    vis[v] = true;

    lc[r] = min(a[v], lc[r]);
    rc[r] = max(b[v], rc[r]);

    for(auto c : adj[v])
        if(!vis[c]) dfs(c, r);
}

ll cnt(int r)
{
    ll tot = 0, run = 0;
    int pr = 0;

    for(auto c : ch[r])
    {
        tot += cnt(c);

        if(lc[c] == pr+1)
            ++run;
        else
            run = 1;

        pr = rc[c];
        tot += run;
    }

    return tot;
}

int main()
{
    int N, M, R, i, k;

  //  ios_base::sync_with_stdio(false);
  //  cin.tie(0);

    cin >> N >> M;

    for(i=1;i<=M;++i)
    {
        cin >> a[i] >> b[i];

        ai[i] = pi(a[i],i);
        bi[i] = pi(b[i],i);

        nb[a[i]] = nb[b[i]] = true;
    }

    k = M;
    for(i=1;i<=N;++i)
    {
        if(!nb[i])
        {
            ++k;
            a[k] = b[k] = i;
            ai[k] = pi(i, k);
            bi[k] = pi(i, k);
        }
    }
    M = k;

    sort(ai+1, ai+M+1);
    sort(bi+1, bi+M+1, greater<pi>());

    stack<int> stk;

    for(i=1;i<=M;++i)
    {
        while(true)
        {
            if(stk.empty()) break;
            if(b[stk.top()] >= ai[i].first) break;

            stk.pop();
        }

        while(!stk.empty())
        {
            if(b[stk.top()] <= b[ai[i].second])
            {
                adj[stk.top()].push_back(ai[i].second);
                adj[ai[i].second].push_back(stk.top());

                stk.pop();
            }
            else break;
        }

        stk.push(ai[i].second);
    }

    while(!stk.empty()) stk.pop();

    for(i=1;i<=M;++i)
    {
        while(true)
        {
            if(stk.empty()) break;
            if(a[stk.top()] <= bi[i].first) break;

            stk.pop();
        }

        while(!stk.empty())
        {
            if(a[stk.top()] >= a[bi[i].second])
            {
                adj[stk.top()].push_back(bi[i].second);
                adj[bi[i].second].push_back(stk.top());

                stk.pop();
            }
            else break;
        }

        stk.push(bi[i].second);
    }

    k = 0;
    for(i=1;i<=M;++i)
    {
        if(vis[ai[i].second]) continue;

        lc[k] = ai[i].first;
        rc[k] = b[ai[i].second];
        dfs(ai[i].second, k);
        ++k;
    }
    R = k;

    while(!stk.empty()) stk.pop();

    for(i=0;i<R;++i)
    {
        while(true)
        {
            if(stk.empty()) break;
            if(rc[stk.top()] > lc[i]) break;

            stk.pop();
        }

        if(stk.empty())
            ch[R].push_back(i);
        else
            ch[stk.top()].push_back(i);

        stk.push(i);
    }

    cout << cnt(R);
}
