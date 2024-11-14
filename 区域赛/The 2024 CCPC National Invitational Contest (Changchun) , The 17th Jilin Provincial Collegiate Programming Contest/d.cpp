#include <bits/stdc++.h>
using namespace std;
#define double long double
const int N = 100010;
int T;
void solve() {
    int n,k;cin>>n>>k;
    vector<array<int,2>> a(n);
    for(int i=0;i<n;++i) cin>>a[i][0]>>a[i][1];
    int p;
    set<int> s;set<double> ss;
    for(int i=1;i<n;++i)
    {
        int cnt=1;
        if(a[i][0]==a[0][0])
        {
            s.clear();s.insert(a[i][0]);
            for(int j=1;j<n&&cnt<=k;++j)
            {
                if(a[j][0]==a[i][0]) continue;
                if(!s.count(a[j][0])) s.insert(a[j][0]),++cnt;
            }
            if(cnt==k)
            {
                p=i;break;
            }
        }
        else if(a[i][1]==a[0][1])
        {
            s.clear();s.insert(a[i][1]);
            for(int j=1;j<n&&cnt<=k;++j)
            {
                if(a[j][1]==a[i][1]) continue;
                if(!s.count(a[j][1])) s.insert(a[j][1]),++cnt;
            }
            if(cnt==k)
            {
                p=i;break;
            }
        }
        else
        {
            ss.clear();
            double k=(a[p][1]-a[i][1])/(double)(a[p][0]-a[i][0]);
            double b=a[p][1]-k*a[p][0];
            ss.insert(b);
            for(int j=1;j<n&&cnt<=k;++j)
            {
                if(j==i) continue;
                b=a[j][1]-k*a[j][0];
                if(!ss.count(b)) ss.insert(b),++cnt;
            }
            if(cnt==k)
            {
                p=i;
            }
        }
    }
    if(a[0][0]==a[p][0])
    {
        unordered_map<int,vector<int>> ans;
        for(int i=0;i<n;++i) ans[a[i][0]].push_back(i+1);
        for(auto &it:ans)
        {
            cout<<it.second.size()<<' ';
            for(auto &it1:it.second) cout<<it1<<' ';
            cout<<'\n';
        }
    }
    else if(a[0][1]==a[p][1])
    {
        unordered_map<int,vector<int>> ans;
        for(int i=0;i<n;++i) ans[a[i][1]].push_back(i+1);
        for(auto &it:ans)
        {
            cout<<it.second.size()<<' ';
            for(auto &it1:it.second) cout<<it1<<' ';
            cout<<'\n';
        }
    }
    else
    {
        unordered_map<double,vector<int>> ans;
        double k=(a[p][1]-a[0][1])/(double)(a[p][0]-a[0][0]);
        double b;
        for(int i=0;i<n;++i)
        {
            b=a[i][1]-k*a[i][0];
            ans[b].push_back(i+1);
        }
        for(auto &it:ans)
        {
            cout<<it.second.size()<<' ';
            for(auto &it1:it.second) cout<<it1<<' ';
            cout<<'\n';
        }
    }

}

int main(void) {
    //scanf("%d", &T);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    T=1;
    while (T -- ) solve();
    system("pause");
    return 0;
}