#include<iostream>
#include<string>
using namespace std;

bool a[10001][10001];
bool c[10001][10001];

bool compute(int x, int y)
{
	if(c[x][y]) return a[x][y];
	
	c[x][y] = true;
	
	if((x+y) % 2) return a[x][y] = compute(x-1,y) & compute(x,y-1);
	else          return a[x][y] = compute(x-1,y) | compute(x,y-1);
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	
	int t, n, m, x, y, i, j, q;
	string s1, s2;
	
	cin >> t;
	
	while(t--)
	{
		cin >> s1;
		m = s1.length();
		
		cin >> s2;
		n = s2.length();
		
		for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			c[i][j] = false; 
		
		
		for(i=1;i<=m;++i)
		{
			a[0][i] = (s1[i-1] == '1') ^ (i % 2);
			c[0][i] = true;
		}
		
		for(i=1;i<=n;++i)
		{
			a[i][0] = (s2[i-1] == '1') ^ (i % 2);
			c[i][0] = true;
		}
		
		cin >> q;
		
		while(q--)
		{
			cin >> x >> y;
			
			cout << ((compute(x, y) ^ ((x+y) % 2)) ? '1' : '0');	
		}
		
		cout << '\n';
	} 
}
