#include <iostream>
#include <algorithm>
using namespace std;

const int  N = 510, M = 100010;

int fa[N];
int n, m;
struct edge{
	int a,b,w;
	bool operator<( const struct edge &e){
		return w<e.w;
	}	
} edges[M];
int find( int x){
	if( x == fa[x]) return fa[x];
	return fa[x] = find(fa[x]);
}


int res= 0 ;
int cnt =0;
int main()
{
	cin>>n>>m;
	for(int i = 0; i <m ; ++i){
		int a,b,w;
		cin>>a>>b>>w;
		edges[i] = {a,b,w};
	}
	sort( edges,edges+m);
	for(int i = 1; i<= n ; ++i) fa[i] = i;
	for( int i = 0 ; i< m ; ++i){
		int a= edges[i].a, b= edges[i].b, w = edges[i].w;
		a = find(a), b = find(b); 
		if( a== b) continue;
		fa[a]= b;
		res+= w;
		++cnt;
	}
	if( cnt< n-1) cout<<"impossible"<<endl;
		else cout<<res<<endl; 
	return 0;	
}
