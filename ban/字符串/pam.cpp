#include <bits/stdc++.h>
using namespace std;
using ll=long long;
struct PAM 
{
    int size,tot,last;
    vector<int> cnt,len,fail;
    vector<char> s;
    vector<vector<int>> tr;
    PAM(int sz)
    {
        cnt.resize(sz+1);tr.resize(26);
        for(int i=0;i<26;++i) tr[i].resize(sz+1);
        len.resize(sz+1);fail.resize(sz+1);
        s.resize(sz+1);
    }
    int node(int l)// 建立一个新节点，长度为 l
    {  
        size++;
        for(int i=0;i<26;++i) tr[i][size]=0;
        len[size]=l;
        fail[size]=cnt[size]=0;
        return size;
    }
    void init()// 初始化
    {  
        size=-1;last=0;
        s[tot=0]='$';
        node(0);node(-1);
        fail[0]=1;
    }
    int getfail(int x)// 找后缀回文
    {  
        while(s[tot-len[x]-1]!=s[tot]) x=fail[x];
        return x;
    }
    void add(char c)// 建树
    {  
        s[++tot]=c;
        int now=getfail(last);
        if(!tr[c][now]) 
        {
            int x=node(len[now]+2);
            fail[x]=tr[c][getfail(fail[now])];
            tr[c][now]=x;
        }
        last=tr[c][now];
        cnt[last]++;
    }
};
int main()
{
    string s;cin>>s;
    int n=s.size();s='$'+s;
    PAM pa(n*3);
    pa.init();
    for(int i=1;i<=n;++i)pa.add(s[i]-'a');
    for(int i=pa.size;i>=2;--i) 
    {
        pa.cnt[pa.fail[i]]+=pa.cnt[i];
    }
    ll ans=0;
    for(int i=2;i<=pa.size;++i)
    {
        //len为长度,cnt为数量,size为回文串数量
        ans=max(ans,1ll*pa.len[i]*pa.cnt[i]);
    }
    cout<<ans<<'\n';
}