#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
typedef long long LL;

int n, m, w[N];
int tr[N];

int lowbit(int x) {
    return(x & (-x));
}
void update(int x,int d) {
    for (int i = x; i <= n; i += lowbit(i)) tr[i] += d;
}



int query(int x) {
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}

void solve() {
    cin >> n >> m;
    for(int i=1;i<=n;++i) tr[i]=0;
    unordered_map<int, vector<int>> mp;
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i], mp[w[i]].push_back(i);
    vector<array<int, 3>> seg;
    int ans = -0x3f3f3f3f, pre = 1;
    for (int i = 1; i <= m + 1; i ++ ) {
        if (mp.find(i) == mp.end()) {
            ans = mp.size() - i;
            break;
        }
        int last = 0;
        for (auto u : mp[i])
            seg.push_back({u, last, i}), last = u;
        if (last) seg.push_back({n + 1, last, i});

    }
    sort(seg.begin(), seg.end());
    map<int,int> vis1;
    for (auto [x, y, z] : seg) {
        for (int i = pre; i < x; ++i) {
            if (vis1.count(w[i]))
                update(vis1[w[i]], -1);
            vis1[w[i]] = i;
            update(i, 1);
        }
        pre = x;
        ans = max(ans, query(x - 1) - query(y) - z);
    }
    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}