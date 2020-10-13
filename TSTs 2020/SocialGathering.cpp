#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MAXN 300001
#define MAXNN 600002

typedef long long ll;
typedef pair<ll, int> pi;
ll l[MAXN], r[MAXN];
pi sci[MAXNN];

int main()
{
    int N, M, i, a, b;
    ll ans = 0, tmp, fct, k, rl, ll;

    cin >> N >> M;

    fct = 1;
    for(i=1;i<=N-2;++i)
    {
        fct *= i;
        fct %= MOD;
    }

    for(i=1;i<=N;++i)
    {
        cin >> l[i] >> r[i];
        sci[2*i-1] = pi(l[i], 0);
        sci[2*i] = pi(r[i], 1);

        k = max(l[i], r[i]);

        tmp = (((2*N-k-1)*k)/2);
        tmp %= MOD;
        tmp *= fct;
        tmp %= MOD;
        ans = ans + MOD-tmp;
        ans %= MOD;
    }

    sort(sci+1, sci+2*N+1, greater<pi>());

    ll = N;
    rl = N;

    for(i=1;i<=2*N;++i)
    {
        k = sci[i].first;
        if(sci[i].second == 0)
        {
            --ll;
            tmp = (((2*N-k-1)*k)/2);
            tmp %= MOD;
            tmp *= rl;
            tmp %= MOD;
            tmp *= fct;
            tmp %= MOD;
            ans += tmp;
            ans %= MOD;
        }
        else
        {
            --rl;
            tmp = (((2*N-k-1)*k)/2);
            tmp %= MOD;
            tmp *= ll;
            tmp %= MOD;
            tmp *= fct;
            tmp %= MOD;
            ans += tmp;
            ans %= MOD;
        }
    }

    for(i=1;i<=M;++i)
    {
        cin >> a >> b;

        k = max(l[a], r[b]);

        tmp = (((2*N-k-1)*k)/2);
        tmp %= MOD;
        tmp *= fct;
        tmp %= MOD;
        ans = ans + MOD-tmp;
        ans %= MOD;

        k = max(r[a], l[b]);

        tmp = (((2*N-k-1)*k)/2);
        tmp %= MOD;
        tmp *= fct;
        tmp %= MOD;
        ans = ans + MOD-tmp;
        ans %= MOD;
    }

    cout << ans;
}
