#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n, m; cin >> n >> m;
	int t0, t1, t2;
	cin >> t0 >> t1 >> t2;
	vector e(n + 1, vector<array<int, 3>>());
	while (m -- ) {
		int u, v, l1, l2;
		cin >> u >> v >> l1 >> l2;
		e[u].push_back({v, l1, l2});
		e[v].push_back({u, l1, l2});
	}
	vector<int> f(n + 1, -1);
	priority_queue<array<int, 2>> q;
	q.push({t0, n});
	while (!q.empty()) {
		auto [t, u] = q.top();
		q.pop();
		if (~f[u]) continue;
		f[u] = t;
		for (auto [v, l1, l2] : e[u]) {
			int nt = -1;
			nt = max(nt, min(t, t1) - l1);
			if (t - l1 >= t2) 
				nt = max(nt, t - l1);
			nt = max(nt, t - l2);
			if (nt >= 0) 
				q.push({nt, v});
		}
	}
	cout << f[1] << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T; cin >> T;
	while (T -- ) solve();
	return 0;
}