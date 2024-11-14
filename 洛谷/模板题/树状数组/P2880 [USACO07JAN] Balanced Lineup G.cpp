#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

//树状数组
void solve() {
    int n, m;
    cin >> n >> m;
    constexpr int inf = 0x3f3f3f3f;
    vector<int> tr1(n + 1), tr2(n + 1, inf), w(n + 1);
    function<int(int)> lowbit = [&] (int x) {
        return x & -x;
    };
    function<void(int, int)> update1 = [&] (int x, int c) {
        for (int i = x; i <= n; i += lowbit(i)) 
            tr1[i] = max(tr1[i], c);
    };
    function<void(int, int)> update2 = [&] (int x, int c) {
        for (int i = x; i <= n; i += lowbit(i))
            tr2[i] = min(tr2[i], c);
    };
    function<int(int, int)> query1 = [&] (int l, int r) {
        if (r > l) {
            if (r - lowbit(r) > l) return max(tr1[r], query1(l, r - lowbit(r)));
            else return max(w[r], query1(l, r - 1));
        }
        return w[l];
    };
    function<int(int, int)> query2 = [&] (int l, int r) {
        if (r > l) {
            if (r - lowbit(r) > l) return min(tr2[r], query2(l, r - lowbit(r)));
            else return min(w[r], query2(l, r - 1));
        }
        return w[l];
    };
    for (int i = 1; i <= n; i ++ ) {
        cin >> w[i];
        update1(i, w[i]), update2(i, w[i]);
    }
    while (m -- ) {
        int l, r;
        cin >> l >> r;
        cout << query1(l, r) - query2(l, r) << "\n";
    }
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}