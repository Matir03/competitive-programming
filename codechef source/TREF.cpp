#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

vector<int> ch[1001];
int p[1001], c[1001], fpm[1001], d[1001];

vector<pi> l;

void DFS(int n)
{
    if(ch[n].size() == 0) l.push_back(pi(d[n], n));

    for(int k : ch[n])
    {
        d[k] = pi(d[n].first + 1, k);
        DFS(k);
    }
}

int main()
{
    int t, n, x, i;

    ios_base::sync_with_stdio(false);

    cin >> t;

    while(t--)
    {
        cin >> n >> x;

        ch.clear();
        l.clear();

        for(i=2;i<=n;++i)
        {
            cin >> p[i];
            ch[p[i]].push_back(i);
        }

        DFS(1);

        sort(d+1,d+n+1);


    }
}
