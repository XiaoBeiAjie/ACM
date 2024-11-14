#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    string s;
    int i=-1,j=-1,ii=-1,jj=-1;
    int n,m;cin>>n>>m;
    for(int k=0;k<n;++k)
    {
        string s;cin>>s;
        for(int kk=0;kk<m;++kk)
        {
            if(s[kk]=='x')
            {
                if(i==-1) i=k;
                ii=k;
                if(j==-1) j=kk;
                jj=kk; 
            }
        }
    }
    //cout<<i<<' '<<ii<<' '<<j<<' '<<jj<<'\n';
    //return;
    int dx=ii-i+1,dy=jj-j+1;
    
    int gd=__gcd(dx,dy);
    dx/=gd;dy/=gd;
    for(i=0;i<dx;++i)
    {
        for(j=0;j<dy;++j)
        {
            cout<<'x';
        }
        cout<<'\n';
    }

}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1; //cin >> T;
    while (T -- ) solve();
    return 0;
}