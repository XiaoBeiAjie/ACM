#include <iostream>
#include <cstring>
#include <queue>
#include <map>
#include <cstdio>
#include <unordered_map>
#include <deque>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <bitset>
#include <limits.h>
#define x first
#define y second

using namespace std;
typedef  long long LL;
typedef long long ll  ; 
typedef pair<int,int> PII;
typedef pair<int,LL> PIL;
typedef pair<int ,PII> PIII ;
typedef pair<LL , LL> PLL ; 
typedef pair<LL ,int > PLI ;
typedef pair<int,char > PIC ; 
typedef unsigned long long ULL ;

const int N = 2e5+10,M = 6e5+10  ;
const LL mod = 1e9+7, INF = 1e18+10;
const double eps = 1e-7 ;
const ULL  P=  131 ;
int n , m   , k ;

struct node{
	int  ls, rs , l , r , fa,  dep ; 
}tr[N*40];
int tot = 0 ; 

void build(int &u , int l ,int r ) {
	u = ++tot ;
	tr[u] = { 0 , 0, l , r , l , 0 } ; 
	if( l == r ) return ;
	int mid = l +r >> 1; 
	build( tr[u].ls , l  , mid ) ; build( tr[u].rs,  mid + 1, r ) ; 
}

void modify(int &u , int v , int l ,int r , int pos , int x ,int dep  ) {
	u =  ++tot ;
	tr[u] =  tr[v] ;
	if( l == r )  {  tr[u].fa = x ; tr[u].dep = dep ;   return ; } 
	int mid = l  +r >> 1 ;
	if( pos <= mid ) modify( tr[u].ls , tr[v].ls , l ,mid ,  pos , x  ,dep) ; 
	else modify( tr[u].rs , tr[v].rs ,   mid  + 1 , r , pos ,x  ,dep  ) ; 
}

int query(int u ,int l , int r, int pos ) {
	if( l == r )  return tr[u].fa  ;
	int mid = l + r >> 1 ;
	if( pos <= mid )  return query( tr[u].ls , l , mid ,  pos ) ;
	return query( tr[u].rs  , mid  + 1 ,r  , pos ) ; 
}

int get_dep(int u , int l , int r ,int pos )  {
	if( l == r) return tr[u].dep  ;
	int mid =l + r >> 1 ;
	if( pos  <= mid ) return get_dep( tr[u].ls , l , mid , pos ) ;
	return get_dep( tr[u].rs , mid + 1,  r , pos) ; 
}

int find(int u ,int x ) {
	int fa = query( u , tr[u].l , tr[u].r , x ) ; 
	if( fa == x ) return fa ;
	return find(  u , fa ) ;
}

bool same( int u ,int a, int b) {
	return find( u , a ) == find( u ,b ) ;
}


void merge(int &u , int v , int x, int y ) {
	int px = find( v , x) , py = find( v , y ) ;
	if( px == py ) {  u = v ;return ;}
	int dx = get_dep( v , tr[v].l  ,tr[v].r , px ) , dy = get_dep( v ,tr[v].l  ,tr[v].r , py ) ; 
	if( dx  < dy ) swap( px , py ) , swap(  dx ,dy )  ;
	if( dx == dy ) {
		int rt  ; 
		modify( rt, v , tr[v].l , tr[v].r , py , px ,  dy )  ;
		modify( u , rt , tr[rt].l  ,tr[rt].r , px , px ,  dx + 1 ) ;
	}else {
		modify( u , v , tr[v].l , tr[v].r , py , px ,  dy )  ;
	}
	
	
}


int root[N] ; 

void solve() { 
	cin >> n >> m ;
	build( root[0] , 1 , n ) ; 
	for(int i =1; i <=m ; ++ i) {
		int op ; cin >> op;
		if( op ==1 ) {
			int a, b; cin >>a >>b ;
			merge( root[i] , root[i-1] , a ,b ) ; 
		}else if( op == 2 ) {
			cin >> k ; 
			root[i] = root[k] ;
		}else {
			root[i] = root[i-1] ; 
			int a, b;cin >>a >>b ;
			if( same( root[i] , a, b)) cout << 1 <<'\n';
			else cout << 0 <<'\n';
		}
	}
}	

int main(){ 	
	ios::sync_with_stdio(true);
	cin.tie( 0 ) ;
	int T;   T= 1;
	while(T-- ){	
		solve() ;  
   	}        
 	return  0 ;
}
