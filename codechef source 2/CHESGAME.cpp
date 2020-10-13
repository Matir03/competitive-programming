#include<iostream>
#include<cmath>
#include<unordered_map>
using namespace std;

unordered_map<long long, int> a[8][8];

int f(int x, int y, long long k)
{
    if(a[x][y].count(k))
        return a[x][y][k];


}

int main()
{
    int m;
    long long n;

    cin >> n >> m;

    int h = log2(n);

    for(i=0;i<m;++i)
    {
        for(j=0;j<m;++j)
        {
            if(abs(i-j) == 2) a[i][j][0] = b[i][j][1] = 1;
        }
    }

    cout << f(0,m-1,n);
}
