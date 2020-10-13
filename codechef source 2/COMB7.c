#include <iostream>
#include <string>
using namespace std;

bool v[1000];
int  c[1000];

inline int before(int i, int l)
{
    if(i&1)
        return l-(i>>1)-1;
    else
        return i>>1;
}

int main()
{
	int n, i, l, x, j;
	string s;

	cin >> n;
	cin >> s;

	l = s.length();

	for(i=0;i<l;++i)
	{
	    if(v[i]) continue;

	    x = 0;
	    j = i;

	    while(j = before(j, l))
	    {
	        v[j] = true;
	        ++x;
	        if(i==j) break;
	    }

	    while(j = before(j, l))
	    {
	        c[j] = x;
	        if(i==j) break;
	    }
	}

	for(i=0;i<l;++i)
	{
	    x = i;
	    for(j=0;j<(n%c[i]);++j)
	        x = before(x, l);

	    cout << s[x];
	}

	return 0;
}
