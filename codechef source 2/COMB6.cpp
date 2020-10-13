#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

ull query(ull l, ull r, ull v)
{
    ull f = 1;
    ull ans = 0;

    while(v!=0)
    {
        if(v&1)
        {
            l /= 2;
            --r;
            r /= 2;
        }
        else
        {
            if(l&1)
            {
                if((l&v)==v) ans += f;
                ++l;
            }
            if((r&1)==0)
            {
                if((r&v)==v) ans += f;
                --r;
            }
            f*=2;
            r/=2;
            l/=2;
        }
        v/=2;
    }

    return ans + f*(r-l+1);
}

int main() {
	int q;
	ull l, r, v;

	cin >> q;

	while(q--)
	{
	    cin >> l >> r >> v;

	    cout << query(l, r, v) << '\n';
	}

	return 0;
}
