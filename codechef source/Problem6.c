#include <stdio.h>
#include <math.h>

int ans(int a, int b, int x)
{
	if(a==1) return (x==1) ? 1 : 0;
	if(b<0)  return 0;
	  
	int k = pow(a, b);
	
	if( (k%x) <= (x/2) ) return floor(k/x)*x;
	
	return floor(k/x)*x + x;
}

int main()
{
	int t, a, b, x;
	
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d%d%d",&a,&b,&x);
		printf("%d\n",ans(a,b,x));	
	}
	
	return 0;
}
