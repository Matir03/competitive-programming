#include<iostream>
#include<string>
using namespace std;

int main()
{
    int n, c=0, k=0;
    string s;

    cin >> n;

    while(n--)
    {
        k = 0;
        cin >> s;

        for(char c : s)
            k += c - '0';

        if(k%3 == 0) ++c;
    }

    cout << c;
}
