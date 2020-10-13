#include<iostream>
#include<stack>
using namespace std;

int main()
{
    int n, m, k, d1=0, d2=0, ad=0, mad=0, r1=1, r2=1, mr1=0, mr2=0;
    stack<bool> b;

    cin >> n;

    while(n--)
    {
        cin >> m;

        if(d1 > 0) ++r1;
        if(d2 > 0) ++r2;

        if(m==1 || m==3)
        {
            if(!b.empty())
            {
                 if(b.top() == (m==1))
                    if(++ad > mad) mad = ad;
            }
            else ++ad;

            b.push(m==3);

            if(m==1) ++d1; else ++d2;
        }
        else
        {
            b.pop();

            if(!b.empty())
            {
                if(b.top() == (m==2)) --ad;
            }
            else --ad;

            if(m==2)
            {
                if(--d1 == 0)
                {
                    if(mr1<r1) mr1 = r1;
                    r1 = 1;
                }
            }
            else
            {

                if(--d2 == 0)
                {
                    if(mr2<r2) mr2 = r2;
                    r2 = 1;
                }
            }
        }
    }

    if(mr1 == 1) mr1 = 0;
    if(mr2 == 1) mr2 = 0;
    if(mad == 0) mad = 1;

    cout << mad << ' ' << mr1 << ' ' << mr2 << ' ';
}
