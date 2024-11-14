#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define pf push_front
#define ep emplace_back
#define ef emplace_front
#define len(a) *(&a+1)-a  
#define int long long
#define ld long double
#define mod 998244353
#define stoi stoll
#define all(ls) ls.begin(),ls.end()
#define allr(ls) ls.rbegin(),ls.rend()
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
 
using namespace std;

using namespace __gnu_pbds;

template<typename type>using ordered_set=tree<type,null_type,less<type>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename type>using ordered_multiset=tree<type,null_type,less_equal<type>,rb_tree_tag,tree_order_statistics_node_update>;

struct custom_hash{
	static uint64_t splitmix64(uint64_t x){
		x+=0x9e3779b97f4a7c15;
		x=(x^(x>>30))*0xbf58476d1ce4e5b9;
		x=(x^(x>>27))*0x94d049bb133111eb;
		return x^(x>>31);
	}
	size_t operator()(uint64_t x) const{
		static const uint64_t FIXED_RAnDOM=chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x+FIXED_RAnDOM);
	}
};

void solve(){
  int n,x,cnt=0;
  cin>>n>>x;
  vector<vector<int>>divisors(n+1);
  for(int i=1;i<=n;i++){
  	for(int j=i;j<=n;j+=i){
  		divisors[j].pb(i);
  		// cout<<i<<" ";
  	}
  	// cout<<endl;
	}
	// cout<<endl;
	for(int i=1;i<=n;i++){
		int a=divisors[i].size();
		for(int j=0;j<a;j++){
			int rev=divisors[i][divisors[i].size()-j-1];
			int pos=min(x-divisors[i][j]-rev,(n-i)/(divisors[i][j]+rev));
			cnt+=max(0LL,pos);
			// cout<<rev<<endl;
		}
		// cout<<endl;
	}
	cout<<cnt<<endl;
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	// freopen("talent.in","r",stdin);
	// freopen("talent.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}