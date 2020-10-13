#include <stdio.h>
#include <math.h>

#define MOD 1000000007

int modexp(int x, int k)
{
	int ans = 1;
	
	while(k--)
		ans = (ans*x) % MOD;
		
	return ans;
}

int cost(int n, int k, int *a)
{
	int tot = 0, i, j;
	
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			tot = (tot+modexp(abs(a[i]-a[j]), k)) % MOD;	
	
	return tot;
}

int main()
{
	int t, n, i, *a, k;
	
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d%d",&n,&k);
		
		a = malloc(sizeof(int)*n);
		for(i=0;i<n;i++) scanf("%d",a+i);
		
		printf("%d\n",cost(n,k,a));
		
		free(a);
	}
	
	return 0;
}
