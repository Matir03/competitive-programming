#include <iostream>
using namespace std;

/*
Make two copies of Bahadur run in both roads.
When the cross, pretend that only the copy of Bahadur
which got the more reward existed;
pa, pb -> position of Bahadurs in road A and road B
ra, rb -> reward accumulated by Bahadur A and Bahadur B from previous crossing point
la, lb -> length of the two roads
score  -> maximum possible score of Bahadur till the last crossing point
*/

#define MAX(x, y) ((x > y) ? x : y) 

int main()
{	
	int la, lb, pa, pb, ra, rb, score;    
	
	cin >> la;
	int a[la]; // rewards in first road
	for(pa=0; pa<la; ++pa) cin >> a[pa];
	
	cin >> lb;
	int b[lb]; // rewards in second road
	for(pb=0; pb<lb; ++pb) cin >> b[pb];
		
	pa = 0;
	pb = 0;
	
	ra = 0;
	rb = 0;
	
	score = 0;
		
	while(pa < la && pb < lb) // neither of them have completed the journey
	{
		// if they are at unequal checkpoints, 
		// push the lower Bahadur forward after adding his current reward
		if(a[pa] > b[pb]) 
		{
			rb += b[pb]; 
			++pb;			
		}
		else if(a[pa] < b[pb])
		{
			ra += a[pa];
			++pa;
		}
		// if they are at equal checkpoints
		else
		{
			score += MAX(ra, rb) + a[pa]; // update score as the larger of the two road scores + this checkpoint
			
			ra = 0; // reset cumulative rewards
			rb = 0;
						
			++pa; // push both Bahadurs forward
			++pb;  
		}
	}
	
	// make both Bahadurs finish their road
	// (the one not yet finished
	//  the other will be ignored)
	
	while(pa < la)
		ra += a[pa++];
	
	while(pb < lb)
		rb += b[pb++];
	
	score += MAX(ra, rb);
	
	cout << score;
}

