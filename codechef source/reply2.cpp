#include <bits/stdc++.h>
using namespace std;

#define mod 1'000'000'007
typedef long long ll;

ll r, n, m;

ll fastExp(ll a, ll n)
{
    if (n == 0)
        return 1;
    ll t = fastExp(a, n / 2);
    t = (t * t) % m;
    return (n % 2 == 1) ? (t * a) % m : t;
}

ll inverse(ll a)
{
    int mt=m, y=0, x=1;

    while(a>1)
    {
        int q = a/mt;
        int t = mt;

        mt = a%mt;
        a=t; t=y;

        y = x-q*y;
        x = t;
    }

    if(x<0) x+=m;

    return x;
}

ll GCD(ll a, ll b)
{
    ll r = 1;
    while (r != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void solve(int test)
{
    ll a, b;
    cout << "Case #" << test << ": ";
    cin >> r >> n >> m;
    if (r == 1)
    {
        ll ans = (n * n) % m;
        cout << ans << '\n';
        return;
    }
    a = fastExp(r, n * n) - 1;
    if (a < 0)
        a += m;
    b = (r - 1) % m;
    ll d = GCD(b, m);
    ll ans = ((a / d) * inverse(b / d)) % m;
    cout << ans << '\n';
}

int main()
{

    freopen("C:\\Users\\Ritam\\Downloads\\input-riceboard-9f35.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t { 1 };
    cin >> t;
    for (int i = 1; i <= t; ++i)
        solve(i);

    return 0;
}
