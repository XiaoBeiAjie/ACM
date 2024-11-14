#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n;cin>>n;
    vector<bool> vis(n,0);
    vector<array<int,2>> a(n);
    vector<array<int,2>> ans;
    map<int,int> cnt;
    for(int i=0;i<n;++i)
    {
        cin>>a[i][0]>>a[i][1];
        if(a[i][0]==a[i][1])
        {
            vis[i]=1;
            ++cnt[a[i][0]];
        }
    }
    priority_queue<array<int,2>,vector<array<int,2>>,less<array<int,2>>> pt;
    for(auto &it:cnt)
    {
        array<int,2> cur={it.second,it.first};
        pt.push(cur);
    }
    int pre=-1,pos=0;
    while(!pt.empty())
    {
        auto cur=pt.top();pt.pop();
        if(cur[1]==pre)
        {
            if(!pt.empty())
            {
                auto cur1=pt.top();pt.pop();
                ans.push_back({cur1[1],cur1[1]});
                pre=cur1[1];
                if(cur1[0]>1) pt.push({cur1[0]-1,cur1[1]});
                pt.push(cur);
            }
            else
            {
                while(pos<n&&(vis[pos]||a[pos][0]==pre||a[pos][1]==pre)) ++pos;
                if(pos==n) return cout<<"No\n",void();
                vis[pos]=1;ans.push_back(a[pos++]);
                pt.push(cur);
            }
        }
        else
        {
            ans.push_back({cur[1],cur[1]});
            if(cur[0]>1) pt.push({cur[0]-1,cur[1]});
            pre=cur[1];
        }
    }
    cout<<"Yes\n";
    while(pos<n)
    {
        while(pos<n&&vis[pos]) ++pos;
        if(pos<n)
        {
            vis[pos]=1;
            if(a[pos][0]==pre) swap(a[pos][0],a[pos][1]);
            ans.push_back({a[pos][0],a[pos][1]});
            pre=a[pos][0];
            ++pos;
        }
    }
    for(auto [x,y]:ans)
    {
        cout<<x<<' '<<y<<'\n';
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1; //cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}