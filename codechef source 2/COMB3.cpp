#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

pi h[100000];
int a[100000];

int main()
{
    int n, k, x, y, i, c, l;

    cin >> n >> k;

    for(i=0;i<n;++i)
    {
        cin >> h[i].first;
        h[i].second = i;
    }

    for(i=0;i<k;++i)
    {
        cin >> x >> y;
        --x; --y;

        if(h[x].first > h[y].first)
            --a[x];
        else if(h[y].first > h[x].first)
            --a[y];
    }

    sort(h, h+n);

    l = -1;
    for(i=0;i<n;++i)
    {
        if(h[i].first != l)
            c = 0;

        a[h[i].second] += i - c;
        l = h[i].first;
        ++c;
    }

    for(i=0;i<n;++i)
        cout << a[i] << ' ';
}
