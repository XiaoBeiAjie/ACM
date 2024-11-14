#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<ll> f;
    int cnt = 0;
    f[0] = 0x3f3f3f3f;
    for(int i=0;i<n;++i)
    {
        int x;cin>>x;
        if(x>2) 
        {
            ++cnt;
            f.push_back((x-1)/2);
        }
    }
    sort(f.begin(), f.end());
    reverse(f.begin(), f.end());
    int sum = 0;
    for (int i = f.size() - 1; i >= l; i -- ) 
        sum += f[i];
    int idx = 1, ans;
    for (int i = l - 1; i >= 0; i -- ) 
        if (f[i] >= sum / idx) {
            ans = sum / idx;
            break;
        }
        else idx ++, sum += f[i];
    int ned=(n-r+r-l-1)/(r-l);
    if (ans >= ned) cout << "Yes\n";
    else cout << "No\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}