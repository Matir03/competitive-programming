#include <stdio.h>
#include <stdlib.h>

int maxSum(int l, int *a)
{
    int i, s=0;
    
    for(i=l;i>0;i--)
    {
        s += a[i]*i;
        a[i-1] = (a[i-1]>a[i]) ? (a[i-1]-a[i]) : 0;
    }
    
    return s;
}

int main() {
	int t, n, i, k, l, *a;
	
	a = malloc(sizeof(int)*21);
	
	scanf("%d",&t);
	
	while(t--)
	{
	    scanf("%d",&n);
	    
	    l=0;
	    for(i=0;i<21;i++) a[i] = 0;
	    
	    for(i=0;i<n;i++)
	    {
	        scanf("%d",&k);
	        if(k>l) l=k;
	        (a[k])++;
	    }
	    
	    printf("%d\n",maxSum(l, a));
	}
	
	return 0;
}

