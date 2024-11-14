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
typedef pair<int, pair<PII ,int > > PIIII;
typedef pair<LL , LL> PLL ; 
typedef pair<LL ,int > PLI ;
typedef pair<int,char > PIC ; 
typedef unsigned long long ULL ;

const int N = 1e6+10,M = 6e5+10  ;
const LL mod = 1e9+7, INF = 1e12+10;
const double eps = 1e-7 ;



const ULL  P=  131 ;


int n , m   , k ;


struct rec{
	LL x1,x2,y1,y2 ; 
}a[N];


LL num[N] ; 

struct tree{
	int l ,r  ;
	int tag ; 
	int val ;
};

template<typename T>
class segTree{
	public :
		int size ;
		vector<T> tr;
	segTree( int _size) :size(_size) , tr( (_size+1)*8   ) { }
	segTree( ) : size(0) { }  
	segTree(const segTree &t) {  size = t.size ; tr= t.tr  ; }  
	~segTree( ) { tr.clear() ; }  
	
	void pushup(int x , int l  ,int r ){
		auto &fa = tr[x] , &left= tr[x<<1 ] , &right = tr[x<<1|1] ; 
		if( fa.tag) {
			fa.val =  num[r+1] - num[l] ; 
		}else {
			fa.val = left.val  + right.val ; 
		}
//		cout <<x <<" "<<fa.l <<" " <<fa.r<<" " << fa.tag  <<" " << fa.val <<" " << left.val <<" " <<right.val <<endl;
	}

	void build( int x ,int l ,int r) {
		tr[x] = { l ,r  ,  0 , 0}  ;
		if( l == r ) {
			return  ;
		}
		int mid = l + r  >> 1 ;
		build( x<<1 , l , mid ) ; build( x<<1 |1 , mid+ 1, r ) ; 
	}
	
	void update(int x ,int l, int r, int mx) {
		
		if( tr[x].l >= l && tr[x].r  <=r ) {
			tr[x].tag += mx ;
			pushup(x , tr[x].l , tr[x].r )   ;
			return ; 
		}
		int mid = tr[x].l + tr[x].r  >> 1 ;
		if( l <=mid ) update(x <<1 , l , r ,mx ) ;
		if( r > mid ) update( x<<1| 1, l , r,  mx ) ; 
		pushup(x , tr[x].l , tr[x].r )   ;
	}
	
	LL query(int x ,int l ,int r ) {
		return tr[x].val ;
		
	}
};

PIIII seg[N*2] ; 


void solve() { 
	cin >> n ;
	int cnt = 0 ;
	
	//�˴�Ϊ��������ɨ�裬��ֻ����ɢ��x���� ��Ȼ��y����������򼴿� 
	/*
	�ڳ������ʱ, �п��ܷ��ʵ�Ҷ�ӽڵ�, ������ return ��, ���Բ���Խ��.

	����ɨ������, ������Ҷ�ӽڵ�ʱ�޸����߶��������ֵ, ����Ҫ����һ�� push_up 
	���ʹ�����ǿ��ܷ��ʵ���������µĽڵ�
	�����Ѿ����ʵ�Ҷ�ӽڵ������¼��������ӽڵ�, ��Ϳ���������, ��������Ҫ���� 16n ����������Ķ���.

	*/
	for(int i = 1;   i<=n ; ++ i) {
		LL x1,x2,y1,y2;
		cin >>x1 >> y1 >>x2 >> y2 ;
		a[i] = { x1,x2,y1,y2} ; 
		num[++cnt] = x1 ; num[++cnt] = x2 ; 
	}
	sort( num+1  ,num + cnt + 1)  ;
	cnt = unique( num +1 ,num+cnt + 1) - num -1 ;
	map<LL,int> mp;
	for(int i =1;  i <=cnt ; ++ i ) mp[num[i]] =  i  ; 
	for(int i = 1;  i <=n ; ++ i) {
		a[i].x1 = mp[a[i].x1] ; a[i].x2 = mp[a[i].x2] ; 
		seg[i] = { a[i].y1 , { { a[i].x1 , a[i].x2 }  ,1}}  ;
		seg[i  + n ] = { a[i].y2 , { { a[i].x1 , a[i].x2 }  ,-1}}  ;
	}
	sort( seg + 1 , seg+1 +2*n ) ; 
	segTree<tree> sg( cnt + 1 ) ; 
	sg.build( 1 ,1 ,cnt  ) ;
	LL ans = 0 ;
//	cout <<endl;
//	
//	for(int i =1; i  <= cnt ; ++ i ) cout << num[i] <<" "  ;cout <<endl;
	
	for(int i =1; i < 2*n ; ++ i ) {
//		cout << i <<endl;
		int l = seg[i].y.x.x , r=  seg[i].y.x.y ,add = seg[i].y.y   ;
		// r-1 ����Ϊ�߶���ά�����ǵ�, ������Ҫ�����߶� 
		sg.update(1 , l ,r-1 , add ) ; 
		ans +=  1LL*(seg[i+1].x - seg[i].x ) *sg.query(  1, 1 ,cnt ) ;  
//		cout << i <<" " << seg[i].x <<" " << l  <<" " <<r  <<" " <<add <<" "<< sg.query( 1,1,cnt) <<" " << endl ; 
	}
	cout << ans <<endl; 

}	

int main(){ 	
	ios::sync_with_stdio(false);
	cin.tie( 0 ) ;
	int T;T  =1; 
	while(T-- ){	
		solve() ;  
   	}        
 	return  0 ;
}
