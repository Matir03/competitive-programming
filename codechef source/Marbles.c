#include<stdio.h>

int gcd(x,y)
{
	if (x%y==0) return y;
	
	return gcd(y,x%y);
}

int dist(m, n)
{
	int tot = (n*(n+1))/2;
	
	if ((tot+m) % 2) return 0;
	
	int x = (tot+m)/2, y=(tot-m)/2;
	
	if (gcd(x,y) == 1) return 1;
	
	return 0;
}

int main()
{
	int t, m, n, i;
	
	scanf("%d",&t);
	
	int a[t];
	
	for(i=0;i<t;i++)
	{
		scanf("%d",&n);
		scanf("%d",&m);
		 
		a[i] = dist(m,n);
	}
	
	for(i=0;i<t;i++) printf("%s",a[i] ? "Yes" : "No");
}
