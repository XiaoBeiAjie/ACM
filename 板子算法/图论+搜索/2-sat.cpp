#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
long long read()
{
    char ch=getchar();
    long long a=0,x=1;
    while(ch<'0'||ch>'9')
    {
        if(ch=='-') x=-x;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        a=(a<<1)+(a<<3)+(ch-'0');
        ch=getchar();
    }
    return a*x;
}
const int N=4e6+5;
int n,m,a,b,x,y,tim,top,edge_sum,scc_sum;
int dfn[N],low[N],st[N],vis[N],scc[N],head[N];
struct node
{
    int to,next;
}A[N];
void add(int from,int to)
{
    edge_sum++;
    A[edge_sum].next=head[from];
    A[edge_sum].to=to;
    head[from]=edge_sum;
}
void tarjan(int u)
{
    dfn[u]=low[u]=++tim;
    st[++top]=u;
    vis[u]=1;
    for(int i=head[u];i;i=A[i].next)
    {
        int v=A[i].to;
        if(!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(vis[v]) low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u])
    {
        scc_sum++;
        while(st[top]!=u)
        {
            scc[st[top]]=scc_sum;
            vis[st[top]]=0;
            top--;
        }
        scc[st[top]]=scc_sum;
        vis[st[top]]=0;
        top--;
    }
}
int main()
{
	cin >> m >> n ; 
    for(int i=1;i<=m;i++)
    {
    	char o , p ;
    	cin >> o >> a >> p >> b ; 
   		if( o =='+' && p =='+') {
   			add( a  , b + n ) ;
   			add( b , a+ n ) ; 
		}
		if( o =='+' && p =='-') {
   			add( a , b) ;
   			add( b  + n , a + n   ) ; 
		}
		if( o =='-' && p =='+') {
			add( a + n , b + n  );
			add( b , a) ;    			
		}
		if( o =='-' && p =='-') {
   			add( a + n , b) ; 
   			add( b + n , a )  ; 
		}
    }
    for(int i=1;i<=2*n;i++) //对每个变量的每种取值进行tarjan 
    {
        if(!dfn[i]) tarjan(i);
    }
    for(int i=1;i<=n;i++)   //判断无解的情况 
    { 
        if(scc[i]==scc[i+n]) //同一变量的两种取值在同一强联通分量里,说明无解 
        {
            printf("IMPOSSIBLE\n");
            return 0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(scc[i]>scc[i+n]) cout<<"+ ";  //强联通分量编号越小 -> 拓扑序越大 -> 越优 
        else  cout<<"- ";
    }
    return 0;
}



//类模板：
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
 
const int N = 5e5+10,M = 5e5+10  ;
const LL mod = 1e9+7 , INF = 1e18+10;
const int inf =  1e8 ; 
const double eps = 1e-7 ;
const ULL  P=  131 ;



LL n , m  , k  ,S,T  ;
class Scc {
	public :
		int size ; 
		vector< vector<int> > adj ; 
		stack<int> stk ; 
		vector<int>  dfn , low ,id  ;
		vector<bool >  st ;
		vector< vector<int> > scc ;
		int timestop ,cnt ; 
	Scc( ):size( 0 ) { }
	Scc( int _size) : size(_size) , dfn(_size+1, 0 ) ,low(_size+1, 0 ) , id(_size+1 , 0) ,st( _size + 1, false) , adj(_size+1) ,scc(_size+1) ,timestop(0) ,cnt(0){}
	Scc( const Scc &_t) {
		size = _t.size ; stk = _t.stk ; dfn = _t.dfn ;low = _t.low;id = _t.id; 
		st = _t.st ; timestop = _t.timestop ; cnt = _t.cnt ; scc =_t.scc ;
	}
	~Scc( ) { dfn.clear( ) ; low.clear() ; id.clear() ; st.clear() ; scc.clear() ;while(!stk.empty()) stk.pop( ); } 
	void addedges(int a, int b ) {
		adj[a].push_back( b) ; 
	} 
	void run( ) {
		for(int i=1; i <=size; ++ i) if(!dfn[i]) tarjan( i)  ;
	}
	
	void tarjan(int u  ) {
		stk.push( u ) ; st[u] = true ;
		dfn[u] = low[u] = ++ timestop ; 
		for(auto son  : adj[u]) {
			if( !dfn[son]) {
				tarjan( son) ; 
				low[u] = min( low[u] ,low[son]) ;
			}else if( st[son]) low[u] =min( low[u] ,dfn[son]) ;
		}
		if( low[u] == dfn[u] ) {
			int v ;  
			++cnt ; 
			do{
				v = stk.top() ;  stk.pop() ; 
				id[v] = cnt ;
				scc[cnt].push_back( v) ;
				st[v] = false ;
			}while( v !=u )  ;
		}
	}
	
	bool same( int a, int b ) {
		return id[a] == id[b] ; 
	}
	
	int getsize(int x ) { return scc[x].size()  ;}
	
};
void solve() {
	cin >> m >> n ; 
	Scc sc( n *2) ; 
	while(m--){
		char o , p ; 
		int a ,b; cin >> o   >>a >>p >>b ; 
		if( o =='+' && p =='+') {
			sc.addedges( a , b + n ) ;
			sc.addedges( b , a + n ) ;
		}
		if( o =='+' && p =='-') {
			sc.addedges( a , b ) ;
			sc.addedges( b+n ,a + n ) ;
		}
		if( o =='-' && p =='+') {
   			sc.addedges( a + n , b + n  ) ;
			sc.addedges( b , a ) ;
		}
		if( o =='-' && p =='-') {
			sc.addedges( a + n , b ) ;
			sc.addedges( b + n , a ) ;
		}
	}
	sc.run() ; 
	for(int i =1; i <=n ; ++ i ) {
		if( sc.id[i] == sc.id[i+n]){
			cout<<"IMPOSSIBLE\n" ;
			return ;  
		}
	}	
	for(int i =1; i <=n ; ++ i) {
		if( sc.id[i] > sc.id[i+n]) cout<<"+ ";
		else cout<<"- " ;
	}
	cout <<'\n';
}

 
int main(){ 	
 
	ios::sync_with_stdio(true);
	cin.tie( 0 ) ;
	int T ; T= 1 ;
	while(T-- ){	
		solve() ;  
   	}        
 	return  0 ;
} 
