#include <stdio.h>
typedef unsigned long long ull;

int ans(ull k)
{
	ull k1 = k, m=1;
	
	while(k1)
	{
		m<<=1;
		k1>>=1;
	}	
	
	if(m-k==k) return 0;
	return !ans(m-k); 
}

int main()
{
	int t;
	ull k;
	
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%llu",&k);
		printf("%d\n",ans(k));	
	}
	
	return 0;
}
