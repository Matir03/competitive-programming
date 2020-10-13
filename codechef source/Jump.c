#include<stdio.h>
#include<stdlib.h>

int jumps (int n, int *l)
{
	int loc=0,i=0,j=0,k,mk,mi;
	
	while(loc+l[loc]<n-1)
	{		
		mk=0;
		for(i=loc+1;i<=loc+l[loc];i++)
		{
			k = i + l[i];
			if (k>mk) 
			{
				mk = k;
				mi = i;			
			}
		}
		
		loc = mi;
		j += 1;
	}
	
	return j+1;
}

int main()
{
	
	int i, j, t; 
	scanf("%d",&t);
	
	int n[t];
	int *l[t];
	
	for(i=0;i<t;i++)
	{
		scanf("%d",n+i);
		l[i] = malloc(4*n[i]);
		for (j=0;j<n[i];j++)
		{
			scanf("%d",l[i]+j);
		}
	} 
	
	for(i=0;i<t;i++)
	{
		printf("%d\n", jumps(n[i], l[i]));
	}
	
	return 0;
}

