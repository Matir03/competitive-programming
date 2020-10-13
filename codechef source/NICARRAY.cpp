#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

typedef long long int ll;

ll gcd[51][51];
ll arr[51];
ll fact[51];

int modInverse(int a, int m)
{
    int m0 = m;
    int y = 0, x = 1;

    if (m == 1)
      return 0;

    while (a > 1)
    {
        // q is quotient
        int q = a / m;
        int t = m;

        // m is remainder now, process same as
        // Euclid's algo
        m = a % m, a = t;
        t = y;

        // Update y and x
        y = x - q * y;
        x = t;
    }

    // Make x positive
    if (x < 0)
       x += m0;

    return x;
}
ll C(ll n, ll r)
{
    if(n<0 || r<0 || r>n) return 0;

    ll tmp = fact[r] * fact[n-r];
    tmp %= MOD;
    tmp = fact[n] / tmp;
    tmp %= MOD;

    cout << tmp;

    return tmp;
}

int main()
{
    ll t, n, s, i, j, k, x, sum, tot;

    fact[0] = 1;

    for(i=1;i<=50;++i)
    {
        gcd[i][0] = gcd[0][i] = i;
        fact[i] = (fact[i-1] * i) % MOD;
    }

    for(i=1;i<=50;++i)
        for(j=1;j<=i;++j)
            gcd[i][j] = gcd[j][i] = gcd[i%j][j];

    cin >> t;

    while(t--)
    {
        cin >> n >> s;

        for(i=0;i<=50;++i) arr[i] = 0;

        k = 0;

        for(i=0;i<n;++i)
        {
            cin >> x;

            if(x==-1)
            {
                ++k;
            }
            else
            {
                s -= x;
                ++arr[x];
            }
        }

        if(k==1) ++arr[s];

        tot = 0;
        for(i=1;i<=50;++i)
        {
            for(j=i+1;j<=50;++j)
            {
                tot += gcd[i][j] * arr[i] * arr[j];
                tot %= MOD;
            }

            tot += i * ((arr[i] * (arr[i]-1))/2);
            tot %= MOD;
        }

        sum = tot * C(s-1, k-1);
        sum %= MOD;

        if(k==1)
        {
            cout << sum << '\n';
            continue;
        }

        for(i=1;i<=s-k+1;++i)
        {
            tot = 0;
            for(j=1;j<=50;++j)
            {
                tot += gcd[i][j] * arr[j];
                tot %= MOD;
            }

            sum += k * tot * C(s-i-1, k-2);
            sum %= MOD;
        }

        if(k==2)
        {
            for(i=1;i<=s-1;++i)
                sum += gcd[i][s-i];

            cout << (sum % MOD) << '\n';
            continue;
        }

        for(i=1;i<=s-k+1;++i)
        {
            for(j=1;i+j<=s-k+2;++j)
            {
                sum += gcd[i][j] * C(k,2) * C(s-i-j-1,k-3);
                sum %= MOD;
            }
        }

        cout << sum << '\n';
    }
}
