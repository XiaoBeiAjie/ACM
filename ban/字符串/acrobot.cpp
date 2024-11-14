#include <bits/stdc++.h>
using namespace std;
struct Acrobo
{
    int tot;
    vector<vector<int>> son;
    vector<int> fail,q,len,id;
    Acrobo(int sz)
    {
        son.resize(sz+1);fail.resize(sz+1);
        q.resize(sz+1);len.resize(sz+1);
        id.resize(sz+1);tot=0;
        for(int i=0;i<sz+1;++i)
        {
            son[i].resize(26,0);
        }
    }
    void insert(string s,int p)
    {
        for(int l=s.length(),x=0,i=0,w;i<l;++i)
        {
            if(!son[x][w=s[i]-'a']) son[x][w]=++tot;
            x=son[x][w];
            if(i==l-1) id[x]=p;
        }
    }
    void make()
    {
        int h=1,t=0,i,x;fail[0]=-1;
        for(i=0;i<26;++i) if(son[0][i]) q[++t]=son[0][i];
        while(h<=t) for(x=q[h++],i=0;i<26;++i)
        {
            if(son[x][i]) fail[son[x][i]]=son[fail[x]][i],q[++t]=son[x][i];
            else son[x][i]=son[fail[x]][i];
        }
    }
    void find(string s)
    {
        for(int l=s.length(),x=0,i=0,w,j;i<l;++i)
        {
            x=son[x][w=s[i]-'a'];
            for(j=x;j;j=fail[j])
            {
                if(id[j]) cout<<i+1<<':'<<id[j]<<'\n';
            }
        }
    }
};
int main()
{
    int n,m;cin>>n>>m;
    Acrobo acr((int)1e6);
    string s;
    for(int i=1;i<=n;++i) 
    {
        cin>>s;
        acr.len[i]=s.length();
        acr.insert(s,i);
    }
    acr.make();
    while(m--) cin>>s,acr.find(s);
}