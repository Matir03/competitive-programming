#include<stdio.h>
#include<stdlib.h>
#include<time.h>

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
	int n, i, *arr;
	
	printf("Test size:"); scanf("%d", &n);
	arr = malloc(4*n);
	
	srand(time(NULL));
	for(i=0;i<n;i++) arr[i] = rand();
	
	time_t t = time(NULL);
	int *s = msort(n, arr);
	printf("\n Merge sort: %ld seconds \n", time(NULL)-t);
	if (n<100) for(i=0;i<n;i++) printf("%d ",s[i]);

	free(s);
	free(arr);
	
	return 0;
}
