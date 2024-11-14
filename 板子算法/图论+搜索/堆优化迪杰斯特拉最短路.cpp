#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int,int> PII;

const int N=  510 , M = 100010;
int n , m;
int h[N],e[N],ne[N],w[N],idx;
int dist[N];
bool st[N]; 

void add( int a,int b ,int c){
	e[idx] = b; ne[idx]  = h[a]; w[idx] = c;h[a] = idx++;
}

int Dijskra(){
	memset( dist, 0x6f , sizeof dist);
	dist[ 1] = 0;
	priority_queue<PII,vector<PII>, greater<PII> > heap;
	heap.push({0,1});
	while( heap.size()){
		auto t = heap.top();
		heap.pop();
		int arr = t.second, distance = t.first;
		if( st[arr] ) continue;
		st[arr] = true;
		for(int i = h[arr] ; i!= -1 ; i = ne[i]){
			int j = e[i];
			if( dist[j] > dist[arr] + w[i]){
				dist[j] = dist[arr] + w[i];
				heap.push({dist[j],j});
			}
		}
		
	}  
	if( dist[n] == 0x6f) return -1;
	return dist[n];
}

int main(){
	cin>>n>>m;
	memset( h, -1,sizeof h  ); 
	while( m--){
		int a,b,c;
		cin>>a>>b>>c;
		add(a,b,c);
	}
	cout<<Dijskra()<<endl;
	return 0;
} 
