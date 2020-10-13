#include <stdio.h>

typedef unsigned long long ull;

ull non2dec(ull n)
{
	ull d=0, k=1;
	int j;
	
	while(n)
	{
		j = n % 10;
		d += j * k;
		n = (n-j)/10;
		k *= 9;
		
	}
	
	return d;
}

ull mult9(ull f, ull l)
{
	
}

int main()
{
	int i, t;
	ull f, l;
	
	scanf("%d",&t);
	
	for(i=1;i<=t;i++)
	{
		scanf("%llu %llu", &f, &l);
		printf( "Case #%d: %llu\n" , i, non2dec(l) - non2dec(f) + 1 - mult9(f, l) );	
	}
	
	return 0;	
}
