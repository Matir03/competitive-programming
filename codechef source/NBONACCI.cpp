#include<bits/stdc++.h>
using namespace std;

int s[100001];

int main()
{
    int n, q, i, k;

    ios_base::sync_with_stdio(false);

    cin >> n >> q;

    for(i=1;i<=n;++i)
    {
        cin >> k;
        s[i] = s[i-1] ^ k;
    }

    for(i=1;i<=q;++i)
    {
        cin >> k;
        cout << s[k%(n+1)] << '\n';
    }
}
