#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll s[5001], e[5000], dp[5001][5001];

ll dsc(ll k)
{
    ll a=0, d;

    while(k>0)
    {
        d = k%10;
        k /= 10;
        a += d;
    }

    return a*a*a;
}

int main()
{
    int n, i, j;

    cin >> n >> s[0];

    for(i=0;i<n;++i)
    {
        cin >> e[i];
        s[i+1] = s[i] + dsc(s[i]);
    }

    for(i=n-1;i>=0;--i)
        for(j=0;j<=i;++j)
            dp[i][j] = max(dp[i+1][j]+e[i]*s[j], dp[i+1][j+1]);

    cout << dp[0][0];
}
