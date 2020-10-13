#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

ii p[100000];

ii operator-(ii a, ii b)
{
    return ii(a.first-b.first,a.second-b.second);
}

ii operator+(ii a, ii b)
{
    return ii(a.first+b.first,a.second+b.second);
}

int dist(ii m, ii n)
{
    return (m.first-n.first)*(m.first-n.first)+(m.second-n.second)*(m.second-n.second);
}

int main()
{
    int t, n, i, x, y;
    ii kp, d;
    bool flag;

    cin >> t;

    while(t--)
    {
        cin >> n;
        bool table[3][3] = {false};

        for(i=0;i<n;++i)
            cin >> p[i].first >> p[i].second;

        cin >> kp.first >> kp.second;

        for(i=0;i<n;++i)
        {
            d = p[i] - kp;

            if(d.first>2 || d.first< -2 || d.second>2 || d.second < -2) continue;

            for(x=-1;x<=1;++x)
            {
                for(y=-1;y<=1;++y)
                {
                    if(dist(kp+ii(x,y), p[i]) == 5)
                        table[x+1][y+1] == true;
                }
            }
        }

        flag = true;
        for(x=0;x<3;++x)
            for(y=0;y<3;++y)
            {
                if(!table[x][y])
                {
                    flag = false;
                    break;
                }
            }

        cout << (flag ? "YES" : "NO") << '\n';
    }
}
