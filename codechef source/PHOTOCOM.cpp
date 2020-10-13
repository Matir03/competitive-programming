#include <iostream>
using namespace std;

typedef long long int ll;

ll gcd(ll a, ll b)
{
	if(b==0) return a; 
	return gcd(b, a%b);
}

#define MAX(p, q) (p>q?p:q)
#define MIN(p, q) (p<q?p:q)

int main()
{		
	freopen("in.txt", "r", stdin);
	
	ll t, h1, w1, h2, w2, i, j, x, y, s;
	char c;
	
	cin >> t;
	
	while(t--)
	{
		cin >> h1 >> w1;
		
		bool P1[h1][w1];
		
		for(i=0;i<h1;++i)
			for(j=0;j<w1;++j)
			{
				cin >> c;
				P1[i][j] = (c == '1');
			}
			
		cin >> h2 >> w2;
		
		s = 0;
		
		for(i=0;i<h2;++i)
			for(j=0;j<w2;++j)
			{
				cin >> c;
				
				for(x=(i*h1)/h2;x*h2<((i+1)*h1);++x)
					for(y=(j*w1)/w2;y*w2<((j+1)*w1);++y)
					
						if(P1[x][y] == (c == '1'))
							s += (MIN((i+1)*h1,(x+1)*h2) - MAX(i*h1,x*h2)) *
								 (MIN((j+1)*w1,(y+1)*w2) - MAX(j*w1,y*w2));
			}
				
		
		cout << s/(gcd(h1,h2)*gcd(w1,w2)) << '\n';
	}
}
