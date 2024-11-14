#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;
using ull=unsigned long long;
set<int> has;
set<int> wtf;
struct Acrobot
{
    int tot;
    vector<vector<int>> son,id;
    vector<int> fail,q,len;
    Acrobot(int sz)
    {
        son.resize(sz+1);
        fail.resize(sz+1,0);
        q.resize(sz+1,0);len.resize(sz+1,0);
        id.resize(sz+1);tot=0;
        for(int i=0;i<=sz;++i) son[i].resize(26,0);
    }
    void insert(string s,int p)
    {
        for(int l=s.length(),x=0,i=0,w;i<l;++i)
        {
            if(!son[x][w=s[i]-'a']) son[x][w]=++tot;
            x=son[x][w];
            if(i==l-1) 
            {
                id[x].push_back(p);
            }
        }
    }
    void make()
    {
        int h=1,t=0,i,x;fail[x]=-1;
        for(int i=0;i<26;++i) if(son[0][i]) q[++t]=son[0][i];
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
                if(!id[j].empty())
                {
                    //cout<<i+1<<' '<<id[j]<<'\n';
                    for(auto &it:id[j])
                    if(has.count(it))
                    {
                        wtf.insert(it);
                    }
                }
            }
        }
    }
};
void solve() {
    int n;cin>>n;
    string s,p;cin>>s>>p;
    mt19937_64 rnd(0);
    uniform_int_distribution<unsigned long long> make(0,(unsigned long long)1<<62);
    ull ans=0;wtf.clear();
    vector<ull> hsh(26);
    for(int i=0;i<26;++i) hsh[i]=make(rnd);
    for(auto &it:p) ans^=hsh[it-'a'];
    int lenn=p.length();
    Acrobot acr((int)1e5+10);
    has.clear();
    for(int i=1;i<=n;++i)
    {
        string op;cin>>op;
        acr.len[i]=op.length();acr.insert(op,i);
        op="";cin>>op;
        vector<ull> f((int)op.length()+1);f[0]=0;
        for(int j=1;j<=(int)op.length();++j)
        {
            f[j]=f[j-1]^hsh[op[j-1]-'a'];
            //cout<<f[j]<<' ';
            if(j>=lenn&&((f[j]^f[j-lenn])==ans)) has.insert(i); 
        } 
    }
    acr.make();
    //cout<<'\n';
    acr.find(s);
    bool tag=0;
    //for(auto &it:has) cout<<it<<' ';
    //cout<<'\n';
    for(auto &it:wtf)
    {
        if(tag) cout<<' ';
        tag=true;
        cout<<it;
    }
    if(tag)cout<<'\n';
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}