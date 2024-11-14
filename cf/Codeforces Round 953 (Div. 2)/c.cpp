#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
typedef long long LL;

int T;

void solve() {
	LL n, k;
	cin >> n >> k;
	if (k & 1) return cout << "No\n", void();
	int l = 1, r = n;
	k /= 2;
	vector<int> ans(n + 1);
	while (l < r && k >= (r - l)) {
		ans[l] = r, ans[r] = l;
		k -= (r - l);
		l ++, r --;
	}
	if (k && l + k <= r) ans[l] = l + k, ans[l + k] = l, k = 0;
	if (k) return cout << "No\n", void();
	cout << "Yes\n";
	for (int i = 1; i <= n; i ++ ) 
		if (ans[i]) cout << ans[i] << " ";
		else cout << i << " ";
	cout << endl; 
}

int main (void) {
	cin >> T;
	while (T -- ) solve();
	return 0;
}