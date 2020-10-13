#include <stdio.h>

typedef long long int ll;

ll gcd(ll x, ll y)
{
	if(y==0) return x;
	return gcd(y, x%y);
}

int main()
{
	int t, n, k;
	ll a, x, y, d;
	
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d%lld%d", &n, &a, &k);
		
		x = (k-1)*(180*(n-2) - n*a);
		y = n*(n-1)/2;
		d = gcd(x, y);
		
		printf("%lld %lld \n", (x+a*y)/d, y/d);
	}
}

