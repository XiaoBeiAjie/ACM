#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long LL;

void solve() {
    int n; cin >> n;
    vector<int> a(2 * n + 1);
    vector<vector<int>> q(n + 1);
    vector<int> cnt(n + 1);
    vector f(2 * n + 1, vector<int> (2 * n + 1));
    for (int i = 1; i <= 2 * n; i ++ )
        cin >> a[i], q[a[i]].push_back(i);
    int ans = 0;
    for (int len = 2; len <= 2 * n; len ++ ) {
        set<int> gg;
        for(int i=1;i<=n;++i) cnt[i]=0;
        for(int i=1;i<=len;++i) {
            ++ cnt[a[i]];
            if(cnt[a[i]] == 2) gg.insert(a[i]);
        }
        for (int l = 1; l + len - 1 <= 2 * n; l ++ ) {
            int r = l + len - 1;
            if (a[l] == a[r]) {
                f[l][r] = a[l] * len;
                for(auto &it:gg) {
                    int ll = q[it][0], rr = q[it][1];
                    f[l][r] = max(f[l][r], f[ll][rr] + a[l] * (len - (rr - ll + 1))); 
                }
            }
            ans = max(ans, f[l][r]);
            -- cnt[a[l]];
            if(cnt[a[l]] == 1) gg.erase(a[l]);
            if(l+len <= 2*n) {
                ++ cnt[a[l + len]];
                if(cnt[a[l+len]]==2) gg.insert(a[l+len]);
            }
        }
    }
    for (int l = 1; l <= 2 * n; l ++ ) {
        for (int r = 1; r <= 2 * n; r ++ )
            cerr << f[l][r] << " ";
        cerr << endl;
    }
    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}