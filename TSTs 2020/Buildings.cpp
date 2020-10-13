#include<bits/stdc++.h>
using namespace std;

#define MAX 500001

typedef long long ll;
typedef pair<ll, ll> pi;

pi pri[MAX];

int main()
{
    int T, N, i;
    ll prevh, totc, bh, bp;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;

    while(T--)
    {
        cin >> N;

        for(i=1;i<=N;++i)
            cin >> pri[i].second >> pri[i].first;

        prevh = pri[N].second;
        totc = 0;
        bh = pri[1].second;
        bp = pri[1].first;
        pri[N].first = 0;

        if(bh >= prevh)
        {
            cout << "0\n";
            break;
        }

        sort(pri+1,pri+N+1);

        for(i=2;i<=N;++i)
        {
            if(pri[i].second <= bh)
            {
                cout << totc + min(bp*(prevh-bh), pri[i].first*(prevh-pri[i].second)) << '\n';
                break;
            }

            if(pri[i].second < prevh)
            {
                totc += pri[i].first * (prevh - pri[i].second);
                prevh = pri[i].second;
            }
        }
    }

    return 0;
}
