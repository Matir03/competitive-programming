#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, k, l, r;
    stack<int> mh;
    stack<int> lt;

    cin >> t;

    while(t--)
    {
        cin >> n;

        while(n--)
        {
            cin >> k;

            r = 0;

            while(!mh.empty())
            {
                if(mh.top()>k) break;
                mh.pop();
                l = lt.top();
                lt.pop();
                r = min(l, r) + 1;

            }

            mh.push(k);
            lt.push(r);
        }

        r = 0;

        while(!mh.empty())
        {
            mh.pop();
            l = lt.top();
            lt.pop();
            r = min(l, r) + 1;
        }

        cout << r << '\n';
    }
}
