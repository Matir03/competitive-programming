#include<stdio.h>
#include<stdlib.h>

int *divisors(int *k, int n)
{
	int i, *d = NULL;
	*k = 0;
	
	for(i=n;i>0;i--)
	{
		if( (n%i) == 0) 
		{
			*k += 1;
			d = realloc(d, 4*(*k));
			d[*k-1] = i; 
		}
	}
	
	return d;
}

int pyth(int n)
{
	if(n%2) return -1;
	
	int i, j, k, m, a, x, n1, abc, max = -1;
	int *d = divisors(&k, n/2);
	
	for(i=0;i<k;i++)
	{
		a = d[i];
		for(j=0;j<k;j++)
		{
			x = d[j];
			
			if(((n/(2*a)) % x) == 0)
			{
				m = n/(2*a*x);
				if(m>=x) break;
				
				n1 = x-m;
				
				if (m > n1) abc = n * a * a * (m*m+n1*n1) * (m-n1) * n1;
				
				if (abc > max) max = abc;
			}
		}
	}
	
	return max;
}

int main()
{
	
	int i, t;
	scanf("%d",&t);
	int n[t];
	
	for(i=0;i<t;i++)
	{
		scanf("%d",n+i);
	}
	
	for(i=0;i<t;i++)
	{
		printf("%d\n",pyth(n[i]));
	}
	
	return 0;
}
