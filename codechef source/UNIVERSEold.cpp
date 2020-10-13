#include <bits/stdc++.h>
using namespace std;

typedef pair<pair<int, int>, int> triplet;

struct cmp
{
	bool operator()(triplet a, triplet b)
	{
		return a.second > b.second;
	}
};

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("C:\\Python27\\Lib\\site-packages\\visual\\examples\\in.txt", "r", stdin);
//  freopen("C:\\Python27\\Lib\\site-packages\\visual\\examples\\out.txt","w",stdout);
	#endif
	
	int n, m, q, d, i, j, u, p, u1, p1, u2, p2;
	pair<int, int> up, up2;
	bool flag;
	map<int, int>::iterator it;
	map<int, list<pair<int, int> > >::iterator it2;
	list<pair<int, int> >::iterator it3;
	
	cin >> n >> m >> q;
	
	map<int, map<int, list< pair<int, int> > > > univ; 
	map<int, int> dist[n+1];
	
	for(i=1;i<n;++i)
	{
		cin >> p1 >> p2;
		
		it = dist[p1].begin();
		for(j=0; j < dist[p1].size(); j++)
		{
			dist[it->first][p2] = it->second + 1;
			it++;
		}
		
		it = dist[p2].begin();
		for(j=0; j < dist[p2].size(); j++)
		{
			dist[p1][it->first] = dist[it->first][p1] = it->second + 1;
			it++;
		}
		
		it = dist[p1].begin();
		for(j=0; j < dist[p1].size(); j++)
		{
			dist[p2][it->first] = dist[it->first][p2];
			it++;
		}
		
		dist[p1][p2] = dist[p2][p1] = 1;
	}
		
	for(i=0;i<m;++i)
	{
		cin >> p1 >> u1 >> p2 >> u2;
		
		univ[u1][p1].push_front(pair<int, int>(u2, p2));
		univ[u2][p2].push_front(pair<int, int>(u1, p1));				
	}
		
	priority_queue<triplet, vector<triplet>, cmp> fringe;
	set<pair<int, int> > explored;
	
	while(q--)
	{
		cin >> p1 >> u1 >> p2 >> u2;
				
	
		while(!fringe.empty()) fringe.pop();
		explored.clear();
		flag = false;
		
		fringe.push(triplet(pair<int, int>(u1, p1), 0));
		
		while(!fringe.empty())
		{
			up = fringe.top().first;
			d  = fringe.top().second;
			
			fringe.pop();
			
			if(explored.count(up)) continue;
			
			u  = up.first;
			p  = up.second;
			
			if(u == u2) if(p == p2) {flag = true; break;} 
			
			explored.insert(up);
			
			if(u == u2) fringe.push(triplet(pair<int, int>(u, p2), d + dist[p][p2]));
			
			it2 = univ[u].begin();
			for(j=0; j < univ[u].size(); j++)
			{
				if(explored.count(up2 = pair<int, int>(u, it2->first)) == 0)
					fringe.push(triplet(up2, d + dist[p][it2->first]));
				
				it2++;
			}
							
			if(univ[u].count(p))
			{
				it3 = univ[u][p].begin();
				
				for(j=0; j < univ[u][p].size(); j++)
				{
					fringe.push(triplet(*it3, d+1));
					it3++;
				}
			}
		}
		
		if(flag) cout << d << '\n'; else cout << "impossible\n";
	
	}
		
}

