#include<bits/stdc++.h>
using namespace std;

string mult(string s, int n)
{
    int i;
    string r = "";

    for(i=0;i<n;++i)
        r += s;

    return r;
}

int main()
{
    int k, i, m, n;
    cin >> k;

    string s, g[5] = {"aeiou","eioua","iouae","ouaei","uaeio"};

    for(m=5;m<=100;++m)
        if(k%m==0) break;

    n = k/m;
    if(k%m!=0 || n<5)
    {
        cout << -1;
        return 0;
    }

    for(i=0;i<5;++i)
        s += mult(g[i], m/5) + g[i].substr(0,m%5);

    s = mult(s, n/5);
    s += s.substr(0, (n%5)*m);

    cout << s;
}
