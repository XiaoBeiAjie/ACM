#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
const int N =510;
int g[N][N];
bool st[N];
int dist[N];
int n , m ;


int prim(){
	memset( dist, 0x3f , sizeof dist);
	dist[1] = 0;

}

int main()
{
	cin>>n>>m;
	memset( g, 0x3f , sizeof g);
	while(m--){
		int a,b,c;
		cin>>a>>b>>c;
		g[a][b] = min( g[a][b],c);
	}	
}
