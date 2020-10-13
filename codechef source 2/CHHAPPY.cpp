#include<bits/stdc++.h>
using namespace std;

int   a[100001];
bool  v[100001];
bool aa[100001];

int main()
{
    int t, n, i;
    bool happy;

    cin >> t;

    while(t--)
    {
        cin >> n;
        happy = false;

        for(i=1;i<=n;++i)
        {
             v[i] = false;
            aa[i] = false;
        }

        for(i=1;i<=n;++i)
            cin >> a[i];

        for(i=1;i<=n;++i)
        {
            if(v[a[i]]) continue;
            if(aa[a[a[i]]])
            {
                happy = true;
                break;
            }
            v[a[i]] = true;
            aa[a[a[i]]] = true;
        }

        cout << (happy ? "Truly Happy\n" : "Poor Chef\n");
    }

    return 0;
}
