#include<bits/stdc++.h>
using namespace std;
const int N=2000+7;
const long long mod=998244353;
long long fac[N],invfac[N];
long long qpow(long long x,long long y){
	long long res=1;
	for (;y;x=x*x%mod,y>>=1)
		if (y&1)
			res=res*x%mod;
	return res;
}
long long inv(long long x){
	return qpow(x,mod-2);
}
long long binnorm(int a,int b){
	if (a<0 || b<0)
		return 0;
	return fac[a+b]*invfac[a]%mod*invfac[b]%mod;
}
void solve( ) {
	int n;
	cin>>n;
	vector<array<long long,4>> v(n);
	for (int i=0;i<n;++i)
		cin>>v[i][0]>>v[i][1]>>v[i][2]>>v[i][3];
	map<long long,vector<pair<long long,int>>> p;
	for (int i=0;i<n;++i)
	{
		p[v[i][0]].push_back({v[i][1],0});
		p[v[i][0]].push_back({v[i][3],1});
		p[v[i][2]].push_back({v[i][1],2});
		p[v[i][2]].push_back({v[i][3],3});
	}
	vector<long long> sum(n+1);
	multiset<pair<long long,int>> st;
	long long lstx=0;
	for (auto [x,vy]:p){
		long long lsty=0;
		int cnt=0;
		for (auto y:st){
			sum[cnt]=(sum[cnt]+(y.first-lsty)*(x-lstx))%mod;
			if (y.second==0)
				++cnt;
			else
				--cnt;
			lsty=y.first;
		}
		for (auto y:vy){
			if (y.second<2)
				st.insert(y);
			else
				st.erase(st.find({y.first,y.second-2}));
		}
		lstx=x;
	}
	for (int k=1;k<=n;++k){
		long long ans=0;
		for (int i=1;i<=n;++i)
			ans=(ans+(binnorm(n-k,k)-binnorm(n-i-k,k)+mod)%mod*sum[i])%mod;
		ans=ans*inv(binnorm(n-k,k))%mod;
		cout<<ans<<endl;
	}
} 	
 
 
 
int main(){ 	
	for (int i=fac[0]=1;i<N;++i)
		fac[i]=fac[i-1]*i%mod;
	invfac[N-1]=inv(fac[N-1]);
	for (int i=N-1;i>0;--i)
		invfac[i-1]=i*invfac[i]%mod;
	ios::sync_with_stdio(false);
	cin.tie( 0 ) ;
	solve() ;  
}