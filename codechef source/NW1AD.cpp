#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;

vector<ll> arr[11];

int main()
{
    int t, d, i;
    ll n;
    bool f;
    vector<ll>::iterator it;

    arr[0] = vector<ll>({1, 2, 3, 4, 5, 6, 7, 8, 9});

    for(i=1;i<12;++i)
    {
        for(it = arr[i-1].begin(); it != arr[i-1].end(); ++it)
        {
            d = (*it) % 10;

            if(d != 0)
            {
                arr[i].push_back((*it)*10 + d-1);
  //              cout << arr[i].back() << ' ';
            }
            if(d != 9)
            {
                arr[i].push_back((*it)*10 + d+1);
  //              cout << arr[i].back() << ' ';
            }
        }
    }

    cin >> t;

    while(t--)
    {
        cin >> n;

        f = false;

        for(i=1;i<12;++i)
        {
            for(it = arr[i].begin(); it != arr[i].end(); ++it)
            {
                if(*it > n)
                {
                        f = true;
                        break;
                }

                cout << *it << ' ';
            }

            if(f) break;
        }

        if(n<10) cout << "-1";
        cout << '\n';
    }
}
