#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
int query (vector<int> V); //Do not change this line
//You are free to add variables and functions at global scope here
// If you use global variables, remember to initialize them in the findHiddenVertex() function.

//Do not change the following function signature
int findHiddenVertex(int n, vector<int> parents)
{
	int i;

	for(i=1;i<=n;++i)
        if(query(vi(1,i)) == 0) return i;
}
