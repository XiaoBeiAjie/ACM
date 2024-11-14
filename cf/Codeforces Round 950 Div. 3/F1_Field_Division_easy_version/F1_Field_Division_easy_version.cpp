#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 100010;
typedef long long LL;

int T;
long long n, m, k;


void solve() {
    scanf("%d%d%d", &n, &m, &k);
    vector<pair<int,int>> p(k);
    for (int i=0;i<k;++i)
    {
        cin>>p[i].second>>p[i].first;
        p[i].second=n+1-p[i].second;
    }
    vector<int> rk(k);
    iota(rk.begin(),rk.end(),0);
    sort(rk.begin(),rk.end(),[&p](int i,int j){return p[i]<p[j];});
    long long sum=n*m;
    vector<int> ans(k);
    sum-=(n+1-p[rk[0]].second)*(m+1-p[rk[0]].first);
    pair<int,int> pos=p[rk[0]];
    ans[rk[0]]=1;
    for (int i=1;i<k;++i){
        if (p[rk[i]].second<pos.second){
            sum-=(pos.second-p[rk[i]].second)*(m+1-p[rk[i]].first);
            ans[rk[i]]=1;
            pos=p[rk[i]];
        }
    }
    cout<<sum<<endl;
    for (int i:ans)
        cout<<i<<' ';
    cout<<endl;
}

int main(void) {
    scanf("%d", &T);
    while (T -- ) solve();
    system("pause");
    return 0;
}