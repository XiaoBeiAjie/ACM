#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n, m; cin >> n >> m;
	vector<int> st(n + 1);
	for (int i = 1; i <= m; i ++ ) {
		int x; cin >> x;
		st[x] = 1;
	}
	vector e(n + 1, vector<int>());
	for (int i = 1; i < n; i ++ ) {
		int u, v; cin >> u >> v;
		e[u].push_back(v); e[v].push_back(u);
	}
	vector<int> siz(n + 1);
	i64 ans = 0;
	function<void(int, int)> dfs = [&] (int u, int fa) {
		for (auto v : e[u]) {
			if (v == fa) continue;
			dfs(v, u);
			siz[u] += siz[v];
 		}
		if (st[u]) {
			ans += (siz[u] + 1) >> 1;
			if (siz[u] % 2) st[fa] = 1;
			siz[u] = 0;
		} 
		else siz[u] ++;
	};
	for (int i = 1; i <= n; i ++ ) 
		if (st[i]) {
			dfs(i, 0);
			break;
		}
	cout << ans << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while (T -- ) solve();
	return 0;
}