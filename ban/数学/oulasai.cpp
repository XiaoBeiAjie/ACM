#include <bits/stdc++.h>
using namespace std;
struct Oula
{
    vector<int> prim;
    vector<bool> vis;
    Oula(int siz)
    {
        vis.resize(siz+1,0);
        vis[1]=true;
        for(int i=2;i<(int)vis.size();++i)
        {
            if(!vis[i]) prim.push_back(i);
            for(auto &it:prim)
            {
                if(it*i>=(int)vis.size()) break;
                vis[it*i]=true;
                if(i%it==0) break;
            }
        }
    }
};
int main()
{
    int t;cin>>t;Oula ou(1e6+6);
    for(int i=0,x;i<t;++i)
    {
        cin>>x;
        if(ou.vis[x]) cout<<"not prime"<<'\n';
        else cout<<"prim"<<'\n';
    }
}