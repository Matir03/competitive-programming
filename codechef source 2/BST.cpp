#include <iostream>
using namespace std;

int maxSum(int n, int *arr)
{
    int run=0, max=-100;
    
    for(int i=0;i<n;i++)
    {
        run+=arr[i];
        cout<<"run="<<run<<endl;
        if(run>max) max=run;
        if(run<0) run=0;
    }
    
    return max;
}

int main() 
{
	int t;
	cin>>t;
	
	int ans[t];
	
	for(int i=0;i<t;i++)
	{
	    int n;
	    cin>>n;
	    
	    int arr[n];
	    for(int j=0;j<n;j++) cin>>arr[j];
	    
	    cout<<maxSum(n, arr)<<endl;
	}
	
	return 0;
}
