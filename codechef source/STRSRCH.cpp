#include<iostream>
#include<string>
using namespace std;

#define MOD 1000000007

int main()
{
    string s;
    int a, e=1, o=0, k=0, i=1;
    cin >> s;

    for(char c : s)
    {
        a = (c - '0') % 4;

        if(a%2)
        {
            o += i;
            o %= MOD;
        }
        else
        {
            k += (a==2) ? o : e;
            k %= MOD;
            e += i;
            e %= MOD;
        }

        i *= 2;
        i %= MOD;
    }

    cout << k;
}
