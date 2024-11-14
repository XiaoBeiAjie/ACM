#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main()
{
    int n,p;cin>>n>>p;
    vector<ll> inv(n+1);inv[1]=1;
    for(int i=2;i<=n;i++) inv[i]=p-(p/i*inv[p%i]%p)%p;//1~n的模p逆元
    //如果inv[i]表示i!的逆元
    //for(int i=n-1;i>=0;--i) inv[i]=inv[i+1]*(i+1)%p;
}