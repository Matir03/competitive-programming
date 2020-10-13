#include<bits/stdc++.h>
using namespace std;

int h[100000], c[100000];
bool used[100000];
stack<int> dom;

int main()
{
    int t, m, n, i, mh, k;

    cin >> t;

    while(t--)
    {
        cin >> n >> m;

        for(i=0;i<n;++i)
        {
            cin >> h[i];
        }

        for(i=0;i<n;++i)
        {
            cin >> c[i];
        }

        for(i=0;i<n;++i)
        {
            while(!dom.empty())
            {
                mh = dom.top();
                if(h[i]<h[mh]) break;
                dom.pop();
            }

            dom.push(i);
        }

        for(i=0;i<n;++i)
                used[i] = false;


        k=0;
        while(!dom.empty())
        {
            i = dom.top();
            dom.pop();
            if(!used[c[i]])
            {
                used[c[i]] = true;
                ++k;
            }
        }

        cout << k << '\n';
    }
}
