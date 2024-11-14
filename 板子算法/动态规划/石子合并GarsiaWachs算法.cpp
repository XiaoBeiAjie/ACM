#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
#define maxn 50010
#define inf 0x3f3f3f3f
const int mod=100003;

void read(int &x){
	int f=1;x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int n,w; long long ans=0; 
vector<long long> l; 
long long solu(){
	int k=l.size()-2,q=-1; 
	for(int i=0;i<l.size()-2;++i) if (l[i]<=l[i+2]) {k=i;break;}
	long long t=l[k]+l[k+1]; 
	l.erase(l.begin()+k);l.erase(l.begin()+k);
	for(int i=k-1;i>=0;--i) if (l[i]>t) {q=i; break;}
    l.insert(l.begin()+q+1,t); 
	return t; 
}
int main(){
	read(n); 
	for(int i=1;i<=n;++i) read(w),l.push_back(w); 
	for(int i=0;i<n-1;i++) ans+=solu(); 
	printf("%lld",ans); 
	return 0;
}
