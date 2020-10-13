#include<bits/stdc++.h>
using namespace std;

#define MAX 500001

typedef long long ll;
typedef pair<ll, ll> pi;

vector<pi> hl, fl;

int main()
{
    int T, N, i;
    ll prevh, totc, bh, bp, bc, th, p, h;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;

    while(T--)
    {
        hl.clear();
        fl.clear();

        cin >> N;

        cin >> bh >> bp;
        hl.emplace_back(bp, bh);

        for(i=2;i<N;++i)
        {
            cin >> h >> p;

            if(p>=bp) continue;

            fl.emplace_back(p, h);

            if(h>=bh)
                hl.emplace_back(p, h);
        }

        cin >> th >> i;

        if(bh >= th)
        {
            cout << "0\n";
            continue;
        }

        sort(hl.begin(), hl.end());
        sort(fl.begin(), fl.end());

        totc = 0;
        prevh = th;

        for(auto ph : hl)
        {
            if(ph.second < prevh)
            {
                totc += ph.first * (prevh - ph.second);
                prevh = ph.second;
            }
        }

        bc = totc;

        totc = 0;
        prevh = th;

        for(auto ph : fl)
        {
            if(ph.second < bh)
            {
                bc = min(bc, totc + ph.first*(prevh - ph.second));
                continue;
            }

            if(ph.second < prevh)
            {
                totc += ph.first * (prevh - ph.second);
                prevh = ph.second;
            }
        }

        cout << bc << '\n';
    }

    return 0;
}
