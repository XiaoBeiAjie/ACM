#include <iostream>
#include <algorithm>
using namespace std;

const int N=  510,INF = 1e9;
int n, m,Q;
int d[N][N];

void floyd(){
	for(int k = 1 ; k<= n ; ++k){
		for(int i = 0;i <=n ; ++i)
			for(int j = 0; j<=n ; ++j)
				d[i][j] = min( d[i][j],d[i][k]+d[k][j]);
	}
}

int main()
{
	cin>>n>>m>>Q;
	 
	for(int i = 1; i<=n ; ++i)
		for(int j = 1; j<=n ; ++j){
			if( i ==j ) d[i][j] = 0;
				else d[i][j] = INF ;
		}
	while(m--){
		int a,b,c;
		cin>>a>>b>>c;
		d[a][b] = min( d[a][b], c);
	}
	floyd();
	while( Q--){
		int a,b;
		cin>>a>>b;
		if( d[a][b] > INF/2) cout<<"impossible"<<endl;
			else cout<<d[a][b]<<endl;
	}
	return 0;
	
}
