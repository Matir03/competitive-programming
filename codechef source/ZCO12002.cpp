#include<iostream>
#include<algorithm>

#define INF 10000000
#define MAX 100000

using namespace std;

typedef pair<int, int> pp;

bool cmp2(pp p1, pp p2) { return p1.second < p2.second; }

void parr(int arr[], int n)
{
    for(int i=0;i<n;++i)
        cout << arr[i] << ' ';

    cout << '\n';
}

pp bg[MAX];
pp nd[MAX];
int v[MAX];
int w[MAX];
int bef[MAX];
int aft[MAX];

int main()
{
    int n, x, y, a, b;
    register int i, j, m;

    cin >> n >> x >> y;

    for(i=0;i<n;++i)
    {
        cin >> a >> b;

        bg[i] = pp(i, a);
        nd[i] = pp(i, b);
    }

    for(i=0;i<x;++i) cin >> v[i];
    for(i=0;i<y;++i) cin >> w[i];

    sort(bg, bg + n, cmp2);
    sort(nd, nd + n, cmp2);
    sort(v, v + x);
    sort(w, w + y);

    for(i=0;i<n;++i) aft[i] = INF;

    i = 0; j = 0;

    while(i<n && j<y)
    {
        if(w[j] >= nd[i].second)
        {
            aft[nd[i].first] = w[j];
            ++i;
        }
        else
            ++j;
    }

    i = n-1; j = x-1;

    while(i>=0 && j>=0)
    {
        if(v[j] <= bg[i].second)
        {
            bef[bg[i].first] = v[j];
            --i;
        }
        else
            --j;
    }

    m = INF;
    for(i=0;i<n;++i) if(aft[i]-bef[i]<m) m = aft[i] - bef[i];

    cout << m+1;
}
