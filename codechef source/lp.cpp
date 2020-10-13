#include<stdlib.h>

#include<iostream>
#include<string>

using namespace std;

struct span
{
	int i; // inclusive
	int f; // exclusive
	
	int l() {return f-i;}	
};

string s;
span **table;

span lp(span w)
{
	cout << '(' << w.i << ',' << w.f << ')' << '\n';
	
	if(w.l()<2) return w;
	if(table[w.i][w.f].l()>0) return table[w.i][w.l()];
	
	span s1 = w, s2 = w, s3 = w;
	span t1, t2, t3;
	
	s3.i++; s3.f--;

	t3 = lp(s3);
	
	if(s3.l()==t3.l())
		if(s[w.i] == s[w.f-1]) 
		{
			table[w.i][w.l()] = w;
			cout << s.substr(table[w.i][w.l()].i, table[w.i][w.l()].f) << '\n';
			return w;
		}
		
	s1.i++; s2.f--; 
		
	t1 = lp(s1);
	t2 = lp(s2);

	table[w.i][w.l()] = (t1.l() > t2.l()) ? t1 : t2;
	
	cout << s.substr(table[w.i][w.l()].i, table[w.i][w.l()].f) << '\n';
	return table[w.i][w.l()];
}

int main()
{	
	cin >> s;
	
	table = (span**)malloc(s.length()*sizeof(span*));
	
	for(int k=0;k<s.length();k++)
		table[k] = (span*)malloc((s.length()-k)*sizeof(span));
		
	span o;
	o.i = 0; o.f = s.length();
	
	span r = lp(o);
	
	cout << s.substr(r.i,r.f);
}
