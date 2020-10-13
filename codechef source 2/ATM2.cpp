#include<iostream>
#include<stack>
using namespace std;

int main()
{
	int t, n, q, i, p, v, w;
	stack<int> path;
	
	cin >> t;
	
	while(t--)
	{
		cin >> n;
		int a[n+1];
		int conn[n+1];
				
		for(i=1;i<=n;i++) cin >> a[i];
		for(i=2;i<=n;i++) cin >> conn[i]; 
					
		cin >> q;
		p = 0;
		
		while(q--)
		{
			cin >> v >> w;
			
			v ^= p;
			w ^= p;
						
			while(v > 1)
			{
				path.push(v);
				v = conn[v];	
			} 		
			
			path.push(1);
			
			p = 0;
			
			while(!path.empty())
			{
				v = path.top();
				path.pop();
				
				if(a[v] > w)
				{
					w = a[v];
					p++;
				}
			}
			
			cout << p << '\n';
		}
	}
}
