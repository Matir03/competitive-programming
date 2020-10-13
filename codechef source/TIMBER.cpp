#include<bits/stdc++.h>
using namespace std;

struct Node
{
    Node *lt, *rt;
    int sum[1001];
};

int arr[1001][1001], n;

void create(Node* cur, int l, int r)
{
    int j;
    if (l==r)
    {
        for(j=1;j<=n;++j)
            cur->sum[j] = cur->sum[j-1]+arr[l][j];

        return;
    }

    int m = (l+r)/2;

    cur->lt = new Node;
    create(cur->lt,l,m);

    cur->rt = new Node;
    create(cur->rt,m+1,r);

    for(j=1;j<=n;++j)
        cur->sum[j] = cur->lt->sum[j]+cur->rt->sum[j];
}

int getval(Node* cur, int l, int r, int x, int y, int u, int v)
{
    if (y<l || x>r) return 0;
    if (x<=l && y>=r) return cur->sum[v]-cur->sum[u-1];

    int m = (l+r)/2;
    return getval(cur->lt,l,m,x,y,u,v)+getval(cur->rt,m+1,r,x,y,u,v);
}

int main()
{
    int i, j, x, y, u, v, m, c;

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> m >> n;

    for(i=1;i<=m;++i)
        for(j=1;j<=n;++j)
            cin >> arr[i][j];

    Node* root = new Node;
    create(root,1,m);

    cin >> c;

    while(c--)
    {
        cin >> x >> u >> y >> v;
        cout << getval(root, 1, m, x, y, u, v) << '\n';
    }
}
