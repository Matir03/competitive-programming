#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
typedef pair<pi,  int> ppi;

int a[100001];
unordered_map<int, int> c;
vector<ppi> wi;
int col[100001];
vector<pi> cq;

int main()
{
    int t, n, i, j, k;

    ios_base::sync_with_stdio(false);

    cin >> t;
    while(t--)
    {
        wi.clear();
        c.clear();
        cq.clear();

        cin >> n;

        for(i=0;i<n;++i)
        {
            cin >> a[i];
            c[a[i]]++;
        }

        for(i=0;i<n;++i)
            wi.push_back(ppi(pi(c[a[i]], a[i]), i));

        sort(wi.rbegin(), wi.rend());

        k = wi[0].first.first;
        if(2*k>n)
        {
            cout << "No\n";
            continue;
        }

        cout << "Yes\n";

        for(i=0;i<k;++i)
            col[wi[i].second] = a[wi[n-1-i].second];

        for(i=k;i<n;++i)
            col[wi[i].second] = a[wi[i-k].second];

        for(i=0;i<n;++i)
            cout << col[i] << ' ';

        cout << '\n';
    }
}
