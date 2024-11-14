#include <bits/stdc++.h>
using namespace std;
struct Mana
{
    string s;
    vector<int> f,g;
    Mana(string ss)
    {
        s=ss;f.resize(2*ss.size()+3);
        g.resize(2*ss.size()+3);f[0]=0;
    }
    void Manacher() 
    {
        string ps="$";ps+='#';
        for(auto &it:s) ps+=it,ps+='#';
        ps+='@';
        int i,r,p,m=ps.size();
        for(r=p=0,f[1]=1,i=2;i<m;++i)
        {
            for(f[i]=r>i?min(r-i,f[2*p-i]):1;ps[i-f[i]]==ps[i+f[i]];f[i]++);
            if(i+f[i]>r) r=i+f[i],p=i;
        }
        for(i=0;i<m;++i) g[i]=0;
        for(i=2;i<m;++i) g[i-f[i]+1]=max(g[i-f[i]+1],i+1);
        for(i=1;i<=m;++i) g[i]=max(g[i],g[i-1]);
        for(i=2;i<m-1;i+=2) cout<<g[i]-i<<' ';//以i开头maxlen
    }
};
int main()
{
    string s;cin>>s;
    Mana man(s);
    man.Manacher();
}