#include<bits/stdc++.h>
using namespace std;

int a[1000001], b[1000001];

int main()
{
    int t, n, i;
    bool bad;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(i=1;i<=n;++i)
            cin >> a[i];

        for(i=1;i<=n;++i)
            cin >> b[i];

        if(a[1] != 0 || b[n] != 0 || a[n] != b[1])
        {
            cout << "No\n";
            continue;
        }

        bad = false;
        for(i=2;i<n;++i)
        {
            if(max(a[i],b[i]) - min(a[i],b[i]) > b[1] ||
               a[i]+b[i]<b[1] || a[i] == 0 || b[i] == 0)
            {
                cout << "No\n";
                bad = true;
                break;
            }
        }

        if(!bad) cout << "Yes\n";
    }
}
