#include<stdio.h>
#include<math.h>
#define DIGITS 16

long long int arr2int(int* d, int n)
{
	long long int a=0;
	int i;
	
	for(i=0;i<n;i++)
	    a += pow(10,i)*d[i];
	
	return a;
}

long long int eight(int k)
{
	int* e = malloc(sizeof(int)*k);
	int i;
	
	for(i=0;i<k;i++) e[i]=8;
	
	return arr2int(e,k);
}

long long int min_p(int* d, int n)
{
	int lead = d[n-1];
	if(lead % 2 == 0) return 0;
	long long int num = arr2int(d,n);
	
	if(lead==9) return num-eight(n);
	
	long long int higher = (lead+1) * pow(10,n-1) - num;
	long long int lower  = num - (lead-1)*pow(10,n-1) - eight(n-1);	
	
	
	return higher<lower?higher:lower; 
}

long long int min_presses(long long int n)
{
	int digits[DIGITS];
	int i=0;
	
	while(n>0)
	{
		digits[i] = n % 10;
		n = (n-digits[i])/10;
		
		i++;
	}
	
	int num_digits = i;
	
	for(i=num_digits-1;i>=0;i--)
	    if(digits[i]%2==1) break; 
	
	num_digits = i+1;
	
	return min_p(digits, num_digits);
}

int main()
{
	int i,t;
	long long int n;
	
	scanf("%d",&t);
	long long int ans[t];
	
	for(i=0;i<t;i++)
	{
		scanf("%lld", &n);
	    ans[i] = min_presses(n);
	}

	for(i=0;i<t;i++) printf("%lld\n", min_presses(n));
	
	return 0;
}
