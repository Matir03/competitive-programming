#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

long long poly[1001][1001];
long long fact[1001];

void gcdExtended(int a, int b, int *x, int *y)
{
    if (a == 0)
    {
        *x = 0, *y = 1;
        return;
    }

    int x1, y1;
    gcdExtended(b%a, a, &x1, &y1);

    *x = y1 - (b/a) * x1;
    *y = x1;
}

int inv(int a)
{
    int x, y;
    gcdExtended(a, MOD, &x, &y);
    return (x%MOD + MOD) % MOD;
}

int eval(int k, int n)
{
    if(n<=0) return 0;
    if(n<=1000) return poly[n][k];

    int i;
    long long p = 1, d, x, t=0;

    for(i=0;i<=k;++i)
    {
        p *= (n-i);
        p %= MOD;
    }

    for(i=1;i<=k;++i)
    {
        d = fact[i] * fact[k-i];
        d %= MOD;
        if((k-i)%2) d = MOD - d;

        t += (((((p*inv(n-i)) % MOD) * inv(d)) % MOD) * poly[i][k]) % MOD;
    }

    return t % MOD;
}

int main()
{
    int t, n, k, j;
    long long i;

    fact[0] = 1;
    for(j=0;j<=1000;++j)
        poly[j][0] = 1;

    for(i=1;i<=1000;++i)
    {
        fact[i] = (fact[i-1] * i) % MOD;

        for(j=1;j<=1000;++j)
            poly[j][i] = (poly[j-1][i] + poly[j][i-1] + poly[j-1][i-1]) % MOD;
    }

    cin >> t;

    while(t--)
    {
        cin >> n >> k;

        cout << eval(k, n-k+1) << '\n';
    }
}
