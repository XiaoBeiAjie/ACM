#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;


const int N = 510, M = 10010;
struct edge{
	int a,b,w;
}edges[N];


int n , m,k ;
int dist[N],backup[N];

int bellman_ford(){
	memset( dist, 0x3f ,sizeof dist);
	dist[1]  = 0;
	for(int i = 0; i< k ; ++i){
		memcpy( backup, dist,  sizeof dist);
		for(int j = 0 ;j < m ; ++j) {
			int a= edges[j].a,b = edges[j].b,w = edges[j].w;
			dist[b] = min ( dist[ b], backup[a]+w);
		}
	}
	//for(int i = 1; i <=n ; ++i) cout<<dist[i]<<" ";
	if( dist[n] > 0x3f3f3f3f / 2) return -1;
	return dist[n];
}


int main()
{
	cin>>n>>m>>k;
	for(int i= 0; i< m ; ++i){
		int a,b,c;
		cin>>a>>b>>c;
		edges[i] = {a,b,c};
	}	
	int t= bellman_ford();
	if( t== -1) cout<<"impossible"<<endl;
		else cout<<t<<endl;
	return 0;
}
