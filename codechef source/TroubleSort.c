#include <stdio.h>
#include <stdlib.h>

int *merge(int *s1, int *s2, int n1, int n2)
{
	int i=0,j=0;
    int *s;
    
    s=malloc(4*(n1+n2));
	
	while (i<n1 && j<n2)
	{
		if(s1[i]>s2[j])
		{
			s[i+j]=s2[j];
			j++;
		}
		else 
		{
			s[i+j]=s1[i];
			i++;			
		}  	
    }
	
	if (i==n1)
	{
		for (;j<n2;j++) s[i+j]=s2[j];
	}
	else
	{
		for (;i<n1;i++) s[i+j]=s1[i];	
	}
	
	return s;
}

int *msort(int n, int *arr)
{
	int *s = malloc(4*n);
	if(n<=1)
	{
		s[0] = arr[0];
		return s;
	}
	int m = n/2;

	int *s1 = msort(m, arr);
	int *s2 = msort(n-m,arr+m);
	
	s = merge(s1, s2, m, n-m);
	
	free(s1);
	free(s2);
	
	return s;
}

int main()
{
	int t,n,i,j,ans;
	int *arr,*arr1,*arr2,*sarr1,*sarr2;
	scanf("%d",&t);
		
	for(i=0;i<t;i++)
	{
		scanf("%d",&n);
		arr1 = malloc(4*n);
		arr2 = malloc(4*n);
				
		j=0;
		while(2*j<n-1) 
		{
			scanf("%d",arr1+j);
			scanf("%d",arr2+j);
			j++;
	    }
	    if(n%2) scanf("%d",arr1+j); 
	    
	    sarr1=msort(n/2+n%2,arr1); 
	    sarr2=msort(n/2,arr2); 
	    arr=merge(sarr1,sarr2,n/2+n%2,n/2);
	   
	    ans=0;
	    for(j=0;j<n;j++)
	    {
	    	if(j%2==0)
	    	{
	    		if(sarr1[j/2]!=arr[j]) 
				{
					ans = j+1;
					break;
				}
			}
			else
			{
				if(sarr2[(j-1)/2]!=arr[j]) 
				{
					ans=j+1;
					break;
				}
			}
		}
		
		printf("%d\n",ans);
		
		free(arr);
		free(arr1);
		free(arr2);
		free(sarr1);
		free(sarr2);
	}
}

