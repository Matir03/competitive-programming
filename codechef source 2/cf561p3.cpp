#include<bits/stdc++.h>
using namespace std;

long long int a[200001];

int main()
{
    long long int n, i, j, k, x, n0=0, c=0;

    ios_base::sync_with_stdio(false);

    cin >> n;

    for(k=0;k<n;++k)
    {
        cin >> x;

        if(x>0) a[k] = x;
        if(x<0) a[k] = -x;
        if(x==0) n0++;
    }

    sort(a,a+n);

    i=0;
    j=0;

    while(j<n)
    {
        if(a[j]<=2*a[i])
        {
            c += j-i;
            ++j;
        }
        else
            ++i;
    }

    c += (n0*(n0-1))/2;

    cout << c;
}
