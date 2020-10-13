#include <iostream>
using namespace std;

int maximum_price(int* price, int n)
{
	int max_price[n];
	for(int i=0;i<n;i++)
    {
		max_price[i] = price[i];
		
		for(int j=0;j<(i+1)/2;j++)
			max_price[i] = (max_price[j] + max_price[i-j-1] > max_price[i]) ? (max_price[j] + max_price[i-j-1]) : max_price[i];
	}

	return max_price[n-1];
}

int main()
{
	int n;
	cout << "Rod length: ";
	cin >> n;
	int price[n];
	
	cout << "Rod prices: ";
	for(int i=0;i<n;i++) cin >> price[i];
	
	cout << "Maximum price: " << maximum_price(price, n);
}

