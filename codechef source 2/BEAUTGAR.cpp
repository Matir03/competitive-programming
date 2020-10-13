#include<iostream>
#include<string>
using namespace std;

int main()
{
    int t, r, g;
    string s;

    cin >> t;

    while(t--)
    {
        cin >> s;
        r = g = 0;

        for(char c : s)
        {
            if(c=='R') ++r;
            else ++g;
        }

        cout << ((r==g) ? "yes\n" : "no\n");
    }
}
