#include <bits/stdc++.h>
using namespace std;

#define MIN(x, y) ((x<y)?(x):(y))
#define INF 100000000

typedef pair<pair<int, int>, int> triplet;

struct cmp
{
	bool operator()(triplet a, triplet b)
	{
		return a.second > b.second;
	}
};

struct segNode
{
	segNode* lt;
	segNode* rt;
	
	int hi;
	int lo;
	
	int val;	
};

segNode* createSegTree(vector<int> seq, int lo, int hi)
{
	segNode* node = (segNode*)malloc(sizeof(segNode));
	
	node->hi = hi;
	node->lo = lo;
	
	if(lo == hi)
	{ 
		node->val = seq[lo];
		return node;	
	}
	
	int mid = (lo + hi)/2;
	
	node->lt = createSegTree(seq, lo, mid);
	node->rt = createSegTree(seq, mid+1, hi);
	
	node->val = MIN(node->lt->val, node->rt->val);
	
	return node; 
}

int getMin(segNode* node, int lo, int hi)
{
	if(lo > hi) return getMin(node, hi, lo);
	
	if(lo > node->hi || hi < node->lo) return INF;
	
	if(lo <= node->lo && hi >= node->hi) return node->val;
	
	return MIN(getMin(node->lt, lo, hi), getMin(node->rt, lo, hi));
}

vector<int> Euler(int& pos, int& cid, int parent, int node, list<int> conn[], int depth[], int p2pos[], int id2p[])
{
	list<int>::iterator it;
	vector<int> trail, tmptrail;
	int tmp = cid;
	
	trail.push_back(cid);
	p2pos[node] = pos;
	id2p[cid] = node;
	cid++; 
	pos++;
		
	for(it = conn[node].begin(); it != conn[node].end(); it++)
	{
		if(*it == parent) continue;
		
		depth[*it] = depth[node] + 1;
		
		tmptrail = Euler(pos, cid, node, *it, conn, depth, p2pos, id2p);
		trail.insert(trail.end(), tmptrail.begin(), tmptrail.end());
		trail.push_back(tmp);
		pos++;
	}
		
	return trail;
}

#define dist(p1, p2) (depth[p1] + depth[p2] - 2*depth[id2p[getMin(root, p2pos[p1], p2pos[p2])]])

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("C:\\Python27\\Lib\\site-packages\\visual\\examples\\in.txt", "r", stdin);
//  freopen("C:\\Python27\\Lib\\site-packages\\visual\\examples\\out.txt","w",stdout);
	#endif
	
	int n, m, q, d, i, j, u, p, u1, p1, u2, p2;
	pair<int, int> up, up2;
	bool flag;
	map<int, int>::iterator it, it1;
	map<int, list<pair<int, int> > >::iterator it2;
	list<pair<int, int> >::iterator it3;

	cin >> n >> m >> q;
	
	map<int, map<int, list< pair<int, int> > > > univ; 
	list<int> conn[n+1];
	segNode* root;
	int depth[n+1];
	int p2pos[n+1];
	int id2p[n+1];
	int pos = 0, cid = 1;
	
	cout << "check";
	
	for(i=1;i<n;++i)
	{
		cin >> p1 >> p2;
		
		conn[p1].push_front(p2);
		conn[p2].push_front(p1);
	}
	
	depth[1] = 0;
	root = createSegTree(Euler(pos, cid, 0, 1, conn, depth, p2pos, id2p), 0, 2*n-1);
	
	cout << "check";
	
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
			
			if(u == u2) fringe.push(triplet(pair<int, int>(u, p2), d + dist(p, p2)));
			
			it2 = univ[u].begin();
			for(j=0; j < univ[u].size(); j++)
			{
				if(explored.count(up2 = pair<int, int>(u, it2->first)) == 0)
					fringe.push(triplet(up2, d + dist(p, it2->first)));
				
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

