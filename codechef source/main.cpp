#include <iostream>
using namespace std;

int main()
{
	int n, k, i, l, j, m;
	
	cin >> n >> k;
	
	int arr[n];
	int q[n];
	
	while(k--)
	{
		for(i=0;i<n;i++)
		{
			cin >> arr[i];
		}
		
		l = 0;
		
		for(i=n-1;i>=0;i--) 
		{
			if(arr[i] < l) break;
			
			l = q[n-i-1] = arr[i];
		}	
		
		for(j=0;j<n;j++)
			if(q[j]>arr[i]) break; 
		
		for(m=0;m<i;m++) cout << arr[m] << ' ';
		cout << q[j] << ' ';
		
		q[j] = arr[i];
		
		for(m=0;m<n-i-1;m++) cout << q[m] << ' ';
		
		cout << endl;
	}
}

