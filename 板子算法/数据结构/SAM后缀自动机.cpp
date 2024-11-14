#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int N =  2e6+ 10  ;
typedef long long LL ;

// 需要根据儿子的数量，改变Node和SAM中ch的大小 
typedef struct Node{
	int len ,fa ; 
	int ch[26]  ; 
}Node ;

LL siz[N] ; 

class SAM{
	public : 
		int size , last , tot ; 
		vector< Node>  tr ; 
	SAM( ) : size( 0 )  ,last( 1 ) , tot ( 1 ) { }   
	~SAM( ) { tr.clear() ; }   
	SAM( int _size) : size( _size) , tr( _size ),last( 1 ) , tot ( 1 ) { } 
	void add(int x ) {
		int p = last , np = last = ++tot ;	
		tr[np].len =  tr[p].len + 1 ;
		for(  ;  p && !tr[p].ch[x] ; p = tr[p].fa ) tr[p].ch[x] = np ; 
		if(!p)  tr[np].fa = 1 ;
		else {
			int q  = tr[p].ch[x] ; 
			if(  tr[p].len + 1 == tr[q].len  ) tr[np].fa = q ; 
			else {
				int nq=  ++tot ; 
				tr[nq] = tr[q] ; 
				tr[nq].len = tr[p].len + 1 ;
				tr[np].fa =  tr[q].fa = nq ;
				for( ; tr[p].ch[x] ==  q  ; p = tr[p].fa) tr[p].ch[x]= nq ; 
			} 
		}
//		siz[np] = 1 ;
	}
		
};
SAM sam( N) ; 
int h[N] , e[N] ,ne[N] ,  idx ;
LL res= 0 ; 
void add(int a, int b  ) {
	e[idx] =b, ne[idx] = h[a] , h[a] = idx++ ; 
}

void dfs(int u  ) {
	for(int i = h[u] ; ~i ; i = ne[i]) {
		int j =e[i] ; 
		dfs( j  ) ; 
		siz[u] += siz[j] ; 
	}
	if( siz[u] != 1) res =max( res , 1LL*siz[u]*sam.tr[u].len) ; 
}

int main( ) {
	string s; cin >> s; 
	int n = s.size( ) ;  
	
	for(int i = 0  ; i  < n  ;  ++ i ) sam.add( s[i] - 'a')  ;
	memset(  h , -1, sizeof h )  ;
	for(int i  =2 ;  i <= sam.tot ; ++ i ) add( sam.tr[i].fa , i ) ; 
	dfs( 1 ) ; 
	cout <<res <<'\n'  ; 
	
	
	return  0 ; 
	
}
