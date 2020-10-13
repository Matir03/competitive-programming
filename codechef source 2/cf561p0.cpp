#include<bits/stdc++.h>
using namespace std;

int C(int n)
{
    return (n*(n-1))>>1;
}

int c[26];

int main()
{
    int n, x=0, i;
    string s;

    cin >> n;

    for(i=0;i<n;++i)
    {
        cin >> s;

        ++c[s[0]-'a'];
    }

    for(i=0;i<26;++i)
        x += C(c[i]>>1) + C((c[i]+1)>>1);

    cout << x;
}
