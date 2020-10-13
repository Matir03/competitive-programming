#include<bits/stdc++.h>
using namespace std;

int id[257][257];
bool e[257][257];
vector<int> dd;

int trim(int x, int s)
{
    if(s==1) return x;

    int a = trim(x,s/2), b = trim(x+s/2,s/2);

    dd.push_back(id[a][b]);

    return e[a][b] ? a : b;
}

int main()
{
    int t, n, k, i, j, u, v;
    bool flag;

    cin >> t;

    while(t--)
    {
        cin >> n;

        dd.clear();

        for(i=1;i<=n;++i)
        {
            for(j=1;j<=n;++j)
            {
                e[i][j] = false;
                id[i][j] = 0;
            }
        }

        for(i=1;i<=(n*(n-1))/2;++i)
        {
            cin >> u >> v;
            e[u][v] = true;
            id[u][v] = id[v][u] = i;
        }

        flag = false;
        k = n;
        while(k>1)
        {
            if(k&1)
            {
                cout << "-1\n";
                flag = true;
                break;
            }

            k >>= 1;
        }

        if(flag) continue;

        trim(1, n);
        sort(dd.rbegin(), dd.rend());

        cout << ((n*(n-1))/2 - (n-1)) << '\n';

        for(i=1;i<=(n*(n-1))/2;++i)
        {
            if(i == dd.back())
            {
                dd.pop_back();
            }
            else
            {
                cout << i << ' ';
            }
        }

        cout << '\n';
    }
}
