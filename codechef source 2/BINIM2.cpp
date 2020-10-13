#include<iostream>
using namespace std;

int main()
{
    int t, n, k, i;
    string s;
    bool p, b;

    cin >> t;

    while(t--)
    {
        cin >> n >> s;

        if(s == "Dee")
            p = false;
        else
            p = true;

        k = 0;
        while(n--)
        {
            cin >> s;

            k += s[0] + s[s.length()-1] - '0' - '1';
        }

        if(k<0)
            cout << "Dum";
        else if(k>0)
            cout << "Dee";
        else
            if(p)
                cout << "Dum";
            else
                cout << "Dee";

        cout << '\n';
    }
}
