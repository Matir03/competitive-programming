#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
typedef long long ll;

int x[100000], y[100000];
unordered_set<ll> cult, v;

ll h(ll a, ll b)
{
    return a + 1000001*b;
}

int fence(int a, int b)
{
    if(v.count(h(a,b))) return 0;
    if(cult.count(h(a,b)) == 0) return 1;

    v.insert(h(a,b));

    return fence(a+1,b) + fence(a,b+1) + fence(a-1,b) + fence(a,b-1);
}

int main()
{
    int r, c, n, i, f, lf = 0;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> r >> c >> n;

    for(i=0;i<n;++i)
    {
        cin >> x[i] >> y[i];

        cult.insert(h(x[i],y[i]));
    }

    for(i=0;i<n;++i)
    {
        f = fence(x[i], y[i]);
        if(f>lf) lf = f;
    }

    cout << lf;
}
