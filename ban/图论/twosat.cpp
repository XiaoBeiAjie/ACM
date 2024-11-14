#include <bits/stdc++.h>
using namespace std;
struct TwoSat 
{
    int n;
    vector<vector<int>> e;
    vector<bool> ans;
    TwoSat(int n):n(n),e(2*n),ans(n){}
    //加析取条件(u,v),f,g代表x,y是否为非,f=1代表x为非
    void addClause(int u,bool f,int v,bool g) 
    {
        e[2*u+!f].push_back(2*v+g);
        e[2*v+!g].push_back(2*u+f);
    }
    //找是否有合法解
    bool satisfiable() 
    {
        vector<int> id(2*n,-1),dfn(2*n,-1),low(2*n,-1);
        vector<int> stk;
        int now=0,cnt=0;
        function<void(int)> tarjan = [&](int u) 
        {
            stk.push_back(u);
            dfn[u]=low[u]=now++;
            for(auto v:e[u]) 
            {
                if(dfn[v]==-1) 
                {
                    tarjan(v);
                    low[u]=min(low[u],low[v]);
                } 
                else if(id[v]==-1) 
                {
                    low[u]=min(low[u],dfn[v]);
                }
            }
            if(dfn[u]==low[u]) 
            {
                int v;
                do 
                {
                    v=stk.back();
                    stk.pop_back();
                    id[v]=cnt;
                }while(v!=u);
                ++cnt;
            }
        };
        for(int i=0;i<2*n;++i) if(dfn[i]==-1) tarjan(i);
        for (int i=0;i<n;++i) 
        {
            if(id[2*i]==id[2*i+1]) return false;
            ans[i]=id[2*i]>id[2*i+1];
        }
        return true;
    }
    //返回一种 (x1,...,xn) 的合法解
    vector<bool> answer() {return ans;}
};
int main()
{
    int n,m;cin>>n>>m;TwoSat ts(n);
    for(int i=0,x,y;i<m;++i)
    {
        cin>>x>>y;
        //加析取条件(u,v),它们的符号分别为f,g,f=1代表u为非
        ts.addClause(x,1,y,1);//a[x]和a[y]不能同时为0
        ts.addClause(x,0,y,0);//a[x]和a[y]不能同时为1
    }
    //找是否有合法解
    if(!ts.satisfiable()) cout<<-1<<'\n';
    else
    {
        //返回合法解
        auto ans=ts.answer();
        for(auto it:ans) cout<<it<<' ';
    }
}