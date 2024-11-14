#include <bits/stdc++.h>
using namespace std;
struct st
{
    vector<vector<int>> f;
    vector<int> Logn;
    int logn;
    st(int siz)
    {
        logn=1;while(logn<=siz) logn<<=1;
        f.resize(siz+1);Logn.resize(siz+1);
        Logn[1]=0;Logn[2]=1;Logn[0]=0;
        for(int i=3;i<=siz;++i) Logn[i]=Logn[i/2]+1;
        for(int i=0;i<=siz;++i) f[i].resize(logn+1,0);
        for(int i=1;i<=siz;++i) cin>>f[i][0];
        for(int j=1;j<=logn;++j)
        {
            for(int i=1;i+(1<<j)-1<=siz;++i)
            {
                f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
            }
        }
    }
    int query(int l,int r)
    {
        int s=Logn[r-l+1];
        return max(f[l][s],f[r-(1<<s)+1][s]);
    }
};
int main() 
{
    int n,m;cin>>n>>m;st st(n);
    for(int i=1,x,y;i<=m;++i) cin>>x>>y,cout<<st.query(x,y)<<'\n';//[x,y]最大值
}