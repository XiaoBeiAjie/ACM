#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 4010;
typedef long long LL;

typedef pair<int,int> PII;

set<PII> se;
int T;

int a[N],b[N];
int ans[N][N];
string s[N];
int n;
int cnt;
PII tmp[N];
void solve() {
    cin >> n;
    for(int i = 0 ; i < n; i++)
        cin >> s[i];
    for(int i = 0; i < n ; i++)
        cin >> a[i];
    for(int j = 0; j < n; j ++)
        cin >> b[j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(s[i][j] == '+') a[i]--, b[j]--,ans[i][j] = 1;

    for(int i = 0; i < n ; i++) 
    {
        if(b[i]<0) tmp[cnt++] = {b[i], i};
        if(b[i]>0) return cout<<"No\n",void();
    }
    for(int i = 0; i < n ; i++) 
        if(a[i] > 0) return cout<<"No\n",void();
    for(int i = 0; i < n; i++)
    {
        sort(tmp, tmp + cnt);
        if(a[i] == 0) continue;
        for(int j = 0; j < cnt ; j++)
        {
            
            if(tmp[j].first == 0) {cnt = j;break;}
            tmp[j].first++;
            a[i]++;
            if(s[i][tmp[j].second] == '+') ans[i][tmp[j].second] = 0;
            else ans[i][tmp[j].second] = 1;
            if(a[i] == 0) break;
        }
        if(a[i] != 0) return cout << "No" << '\n', void();
    }
    for(int i = 0; i < cnt ; i++) if(tmp[i].first != 0) return cout << "No" << '\n', void();
    cout << "Yes" << '\n';
    for(int i = 0; i < n ; i++)
    {
        for(int j = 0; j < n; j ++)
            cout << ans[i][j];
        cout << '\n';
    }
        

}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    T = 1;
    while (T -- ) solve();
    //system("pause");
    return 0;
}