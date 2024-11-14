#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline void print(__int128 x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9)
        print(x/10);
    putchar(x%10+'0');
}
void solve() {
    int n;cin>>n;
    string s,p;cin>>s>>p;
    __int128 t1=0,t2=0;
    __int128 ans=0;
    for(int i=0;i<n/2;++i) t1=t1*10+s[i]-'0';
    for(int i=n/2;i<n;++i) t2=t2*10+s[i]-'0';
    __int128 tmp1=sqrtl(t1)+(long double)1e-30,tmp2=sqrtl(t2)+(long double)1e-30;
    if(tmp1*tmp1==t1) ans-=tmp2+1;
    if(tmp1*tmp1==t1&&tmp2*tmp2==t2) ++ans;
    if(1)
    {
        --t1;t2=0;
        for(int i=n/2;i<n;++i) t2=t2*10+9;
        tmp1=sqrtl(t1)+(long double)1e-30;
        tmp2=sqrtl(t2)+(long double)1e-30;
        ++tmp2;++tmp1;
        ans-=tmp2*tmp1;
    }
    t1=0;t2=0;
    for(int i=0;i<n/2;++i) t1=t1*10+p[i]-'0';
    for(int i=n/2;i<n;++i) t2=t2*10+p[i]-'0';
    tmp1=sqrtl(t1)+(long double)1e-30,tmp2=sqrtl(t2)+(long double)1e-30;
    if(tmp1*tmp1==t1) ans+=tmp2+1;
    if(1)
    {
        --t1;t2=0;
        for(int i=n/2;i<n;++i) t2=t2*10+9;
        tmp1=sqrtl(t1)+(long double)1e-30;
        tmp2=sqrtl(t2)+(long double)1e-30;
        ++tmp2;++tmp1;
        ans+=tmp2*tmp1;
    }
    print(ans);
}
 
int main(void) {
    //ios::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    int T=1; //cin >> T;
    while (T -- ) solve();
    return 0;
}