#include<iostream>
#include<string>
using namespace std;

int main()
{
	int count[26], i, k, x;
	string s, o;
	char c;
	
	cin >> s;
	cin >> k;
	
	for(i = 0; i < 26; i++) count[i] = 0;
	
	c = '\0';
	
	for(i = 0; i < s.length(); i++)
	{	
		if(++count[s[i] - 'a'] >= k)
		{
			for(x=0; x < s[i]-'a'; x++)
				count[x] = 0;
		
			if(s[i] > c) c = s[i]; 
		}
	}
	
	if(c == '\0') return 0;
	
	for(i = 0; i < s.length(); i++)
	{
		if(s[i] == c)
		{
			o.push_back(c);
			
			if(--count[c-'a'] == 0)
			{
				while(1)
				{
					if(c == 'a') 
					{
						cout << o;
						return 0;
					}
					
					if(count[--c - 'a'] >= k) break;
				}	
			} 
			 
		}
		
	}
	
	cout << o;
}
