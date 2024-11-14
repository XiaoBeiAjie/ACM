#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n), hp_a(n), b(m), hp_b(m);
    for (int i = 0; i < n; i ++ ) 
        cin >> a[i], hp_a[i] = a[i];
    for (int j = 0; j < m; j ++ ) 
        cin >> b[j], hp_b[j] = b[j];
    long double cnt_a = 0, cnt_b = 0, cnt = 0;
    int ca = n, cb = m;
    vector<int> st_a(n), st_b(m);
    constexpr int inf = 0x3f3f3f3f;
    function<void(int, long double)> dfs = [&] (int t, long double f) {
        if (!ca && !cb) return cnt += f, void();
        if (ca && !cb) return cnt_a += f, void();
        if (!ca && cb) return cnt_b += f, void();
        if (t) {
            int minn = inf, idx1 = 0;
            for (int i = 0; i < n; i ++ ) {
                if (hp_a[i] <= 0) continue;
                if (minn > st_a[i]) minn = st_a[i], idx1 = i;
            }
            for (int j = 0; j < m; j ++ ) {
                if (hp_b[j] <= 0) continue;
                st_a[idx1] ++;
                hp_b[j] -= a[idx1];
                if (hp_b[j] <= 0) cb --;
                hp_a[idx1] -= b[j];
                if (hp_a[idx1] <= 0) ca --;
                dfs(t ^ 1, f * 1.0 / (cb + (hp_b[j] <= 0)));
                if (hp_a[idx1] <= 0) ca ++;
                hp_a[idx1] += b[j];
                if (hp_b[j] <= 0) cb ++;
                hp_b[j] += a[idx1];
                st_a[idx1] --;
            }
        }
        else {
            int minn = inf, idx2 = 0;
            for (int j = 0; j < m; j ++ ) {
                if (hp_b[j] <= 0) continue;
                if (minn > st_b[j]) minn = st_b[j], idx2 = j;
            }
            for (int i = 0; i < n; i ++ ) {
                if (hp_a[i] <= 0) continue;
                st_b[idx2] ++;
                hp_a[i] -= b[idx2];
                if (hp_a[i] <= 0) ca --;
                hp_b[idx2] -= a[i];
                if (hp_b[idx2] <= 0) cb --;
                dfs(t ^ 1, f * 1.0 / (ca + (hp_a[i] <= 0)));
                if (hp_b[idx2] <= 0) cb ++;
                hp_b[idx2] += a[i];
                if (hp_a[i] <= 0) ca ++;
                hp_a[i] += b[idx2];
                st_b[idx2] --;
            }
        }
    };
    if (n > m) dfs(1, 1);
    else if (n < m) dfs(0, 1);
    else dfs(1, 0.5), dfs(0, 0.5);
    cout << fixed << setprecision(12) << cnt_a << " " << cnt_b << " " << cnt << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}