#include<iostream>
using namespace std;

int main()
{
    int t, p1, p2, k, x;

    cin >> t;

    while(t--)
    {
        cin >> p1 >> p2 >> k;

        if(((int)(p1 + p2) / k) % 2)
            cout << "COOK\n";
        else
            cout << "CHEF\n";
    }
}
