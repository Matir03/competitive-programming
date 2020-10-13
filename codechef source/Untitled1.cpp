#include <iostream>
#include <math.h>
using namespace std;

double modexp(double b, int e, int m)
{
    if(e==0) return 1;
    
    while(b>m) b-=m;
    
    double r = modexp(b, e/2, m);
    
    r = r * r * ((e%2)?b:1);
    
    while(r>m) r-=m;
    
    return r;
}

int main() 
{
	int t, a, b, c, n, m;
	double alpha, beta, k;
    
    cin >> t;
    
    while(t--)
    {
        cin >> a >> b >> c >> n >> m;
        
        alpha = (a + sqrt(a*a+4*b)) / 2;
        beta  = a - alpha;
        
        k = (a+b+c-1)/(alpha-beta);

        cout << k*( (modexp(alpha,n-1,m)-1)/(alpha-1) - 
                    (modexp(beta ,n-1,m)-1)/(beta -1) ) + 1 << '\n';
    }

    return 0;
}
