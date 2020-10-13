#include <iostream>
using namespace std;

typedef long long int ll;

ll gcd(ll a, ll b)
{
	if(b==0) return a; 
	return gcd(b, a%b);
}

int main()
{
	freopen("in.txt", "r", stdin);
	
	ll t, h1, w1, h2, w2, i, j, sim;
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
		
		bool P2[h2][w2];
		
		for(i=0;i<h2;++i)
			for(j=0;j<w2;++j)
			{
				cin >> c;
				P2[i][j] = (c == '1');
			}
			
		sim = 0;
		
		for(i=0;i<h1*h2;++i)
			for(j=0;j<w1*w2;++j)
				if(P1[i/h2][j/w2] == P2[i/h1][j/w1]) ++sim; 	
		
		cout << sim/(gcd(h1,h2)*gcd(w1,w2)) << '\n';
	}
}
