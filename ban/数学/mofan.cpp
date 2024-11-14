#include <bits/stdc++.h>
using namespace std;
struct Mofan
{
    vector<int> mu,prime;
    vector<bool> vis;
    Mofan(int sz)
    {
        mu.resize(sz+1,0);vis.resize(sz+1,0);
        vis[1]=1;mu[1]=1;
        for(int i=2;i<=sz;++i) 
        {
            if(!vis[i]) mu[i]=-1,prime.push_back(i);
            for(int j=0;j<(int)prime.size()&&i*prime[j]<=sz;++j)
            {
                mu[i*prime[j]]=-mu[i];
                vis[i*prime[j]]=1;
                if(i%prime[j]==0) 
                {
                    mu[i*prime[j]]=0;
                    break;
                }
            }
        }
    }
};
int main()
{
    int n;cin>>n;Mofan mof(n);
}
