#include<bits/stdc++.h>
using namespace std;
typedef int64_t i64;
typedef uint64_t u64; 
const int N=100100,L=64;
int main(){
	int n;
	cin>>n;
	bitset<N> bs;
	auto gt=[&]()->i64{
		i64 x=0;
		for (int i=N-1;i>=N-L;--i)
			x=x<<1|bs[i];
		return x;
	};
	auto st=[&](u64 x){
		for (int i=N-L;i<N;++i)
		{
			bs[i]=x&1;
			x>>=1;
		}
	};
	while (n--){
		i64 a;
		cin>>a;
		bs>>=1;
		bs[N-1]=bs[N-2];
		st(a+gt());
		if (!bs.any())
			cout<<'0';
		else if (bs[N-1])
			cout<<'-';
		else
			cout<<'+';
	}
}