#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
//ÁÚ½Ó¾ØÕó±íÊ¾Í¼ 
const int N = 510;
int n ,m;
int g[N][N];
int dist[N];
bool st[N];

int Dijskra(){
	memset( dist, 0x3f , sizeof dist);
	dist[1] = 0;
	for(int i =1; i < n; ++i){
		int t= -1;
		for(int j = 1; j <=n ; ++j ){
			if( !st[j] && ( t== -1 || dist[t] > dist[j]))
				t= j;
		}
		st[t] = true;
		for(int j = 1; j<=n; ++j){
			dist[j] = min( dist[j], dist[t]+g[t][j]);
		}
		
	}
	if( dist[n] == 0x6f) return -1;
	return dist[n];
}


int main(){
	memset( g,0x3f,sizeof g);
	scanf("%d%d",&n,&m);
	while(m--){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		g[a][b] = min( g[a][b],c);
		
	}
	int t= Dijskra();
	cout<<t<<endl;
	return 0 ;
} 
