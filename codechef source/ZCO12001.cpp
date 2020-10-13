#include<iostream>
using namespace std;

int main()
{
    int n, i, m, md=0, mdp, d=0, ms=0, msp, s=0;

    cin >> n;

    for(i=1;i<=n;i++)
    {
        cin >> m;

        s++;

        if(m==1)
        {
            d++;

            if(d>md)
            {
                md  = d;
                mdp = i;
            }
        }
        else
        {
            d--;

            if(d==0)
            {
                if(s>ms)
                {
                    ms  = s;
                    msp = i - s + 1;
                }

                s = 0;
            }
        }
    }

    cout << md << ' ' << mdp << ' ' << ms << ' ' << msp;
}
