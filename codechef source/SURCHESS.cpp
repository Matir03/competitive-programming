#include<iostream>
using namespace std;

int h[200][200][201], v[200][200][201];
int inv[200][200][201];
int sm[201];

int main()
{
    int n, m, q, i, j, k, t, x, s;
    char c;

    cin >> n >> m;

    for(i=0;i<n;++i)
    {
        for(j=0;j<m;++j)
        {
            cin >> c;
            inv[i][j][0] = (c-'0') ^ ((i+j) % 2);
        }
    }

    if(m<n) x=m; else x=n;

    for(i=0;i<n;++i)
    {
        for(j=0;j<m;++j)
        {
            h[i][j][0] = v[i][j][0] = inv[i][j][0];

            for(k=1;k<m-j;++k)
                h[i][j][k] = h[i][j][k-1] + inv[i][j+k][0];

            for(k=1;k<n-i;++k)
                v[i][j][k] = v[i][j][k-1] + inv[i+k][j][0];
        }
    }

    for(k=1;k<x;++k)
    {
        t = k >> 1;
        s = 40000;

        if(k%2 == 1)
        {
            for(i=0;i<n-k;++i)
                for(j=0;j<m-k;++j)
                {
                    inv[i][j][k] = inv[i][j][t] + inv[i+t+1][j][t] + inv[i][j+t+1][t] + inv[i+t+1][j+t+1][t];
                    if(inv[i][j][k] < s) s = inv[i][j][k];
                    if((k+1)*(k+1) - inv[i][j][k] < s) s = (k+1)*(k+1) - inv[i][j][k];
                }
        }
        else
        {
            for(i=0;i<n-k;++i)
                for(j=0;j<m-k;++j)
                {
                    inv[i][j][k] = inv[i][j][t] + inv[i+t][j][t] + inv[i][j+t][t] + inv[i+t][j+t][t] - h[i+t][j][k] - v[i][j+t][k] - inv[i+t][j+t][0];
                    if(inv[i][j][k] < s) s = inv[i][j][k];
                    if((k+1)*(k+1) - inv[i][j][k] < s) s = (k+1)*(k+1) - inv[i][j][k];
                }
        }

        sm[k] = s;
    }

    sm[0] = 0;

    cin >> q;

    while(q--)
    {
        cin >> t;

        i = 0; j = x;

        while(j-i>1)
        {
           k = (i+j)/2;

           if(sm[k]<=t)
                i = k;
           else
                j = k;
        }

        cout << i+1 << '\n';
    }
}
