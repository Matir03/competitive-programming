#include <iostream>
using namespace std;

int main() 
{
	int t, n, q, l, r, X, x, i;
	
	cin >> t;
	
	while(t--)
	{
	    cin >> n >> q;
	    int arr[n];
	    
	    X = 0;
	    for(i=0;i<n;i++)
	    {
	        cin >> arr[i];
	        X ^= arr[i];
	    }
	    
	    while(q--)
	    {
	        cin >> l >> r;
	        
	        x = 0;
	        for(i=l-1;i<r;i++)
	        {
	            x ^= arr[i]; 
	        }
	        
	        cout << (x^X) << endl;
	    }
	}
	
	return 0;
}
