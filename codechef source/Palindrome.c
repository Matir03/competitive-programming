#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define ll long long int
#define dist(a, b) ((a>b)?(a-b):(b-a))

int *reverse(int m, int *arr)
{
    int i, *rev=malloc(sizeof(int)*(m+1));
    
    for(i=0;i<m;i++)
    {
        rev[i] = arr[m-i-1];
    }
    
    return rev;
}

int *int2arr(int m, ll n)
{
    int *arr = malloc(sizeof(int)*(m+1));
    int i;
    
    for(i=0;i<m;i++)
    {
        arr[i] = n % 10;
        n=(n-arr[i])/10;
    }
    
    return arr;
}

ll arr2int(int m, int *arr)
{
    int i;
    ll ans=0;
    
    for(i=0;i<m;i++)
        ans+=arr[i]*pow(10,i);
    
    return ans;
}

ll nearestPalindrome(ll n)
{
	if(modf(log10(n), NULL) == 0) return n-1;
	
    int m = log10(n) + 1;
    int *digits = int2arr(m, n);
    ll closest=0, mindist=0;
    ll b,e,n1,n2,n3;
    
    if(m%2)
    {
        int *final = digits+(m+1)/2;
        b = arr2int((m-1)/2,reverse((m-1)/2,final));
        e = arr2int((m+1)/2,final-1);
        n1 = e     * pow(10,(m-1)/2) + b;
        n2 = (e+1) * pow(10,(m-1)/2) + b;
        n3 = (e-1) * pow(10,(m-1)/2) + b;
                
        closest = n3; mindist = dist(n3, n);
        if(dist(n1, n) < mindist)
        {
            closest = n1;
            mindist = dist(n1, n);
        }
        
        if(dist(n2, n) < mindist) closest = n2;
    }
    else
    {
        int *final = digits + m/2;
        b = arr2int(m/2,reverse(m/2,final));
        e = arr2int(m/2,final);
        n1 = e  * pow(10,m/2) + b;
        
        (*final)++;
        
        b = arr2int(m/2,reverse(m/2,final));
        e = arr2int(m/2,final);
        n2 = e  * pow(10,m/2) + b;
        
        (*final)-=2;
        
        b = arr2int(m/2,reverse(m/2,final));
        e = arr2int(m/2,final);
        n3 = e  * pow(10,m/2) + b;
        
        closest = n3; mindist = dist(n3, n);
        if(dist(n1, n) < mindist)
        {
            closest = n1;
            mindist = dist(n1, n);
        }
        
        if(dist(n2, n) < mindist) closest = n2;
    }
    
    return closest;
}

int main() {
	int i, t;
	ll n;
	
	scanf("%d",&t);
	
	for(i=0;i<t;i++)
	{
	    scanf("%lld",&n);
	    printf("%lld\n",nearestPalindrome(n));
	}
	
	return 0;
}
