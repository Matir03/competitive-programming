#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int dsum(ll n)
{
    int t=0;

    while(n>0)
    {
        t += (n % 10);
        n /= 10;
    }

    return t;
}

int main()
{
    int t, x, i;
    ll d, n, k;

    cin >> t;

    while(t--)
    {
        cin >> n >> d;

        queue<pair<ll, int> > fringe;
        fringe.push(pair<ll, int>(n,0));

        if(d%9==0)
        {
            x = n % 9;
            if(x==0) x = 9;
        }
        else if(d%3==0)
        {
            x = n % 3;
            if(x==0) x = 3;
        }
        else
        {
            x = 1;
        }

        while(true)
        {
            k = fringe.front().first;
            i = fringe.front().second;
            if(k==x) break;
            fringe.pop();
            fringe.push(pair<ll, int>(k+d, i+1));
            fringe.push(pair<ll, int>(dsum(k), i+1));
        }

        cout << x << ' ' << i << '\n';
    }
}
