#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 100010;
typedef long long LL;

int T;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n + 2);
    for (int i = 1; i <= n; i ++ ) cin >> v[i];
    v[0] = 0, v[n + 1] = n + 1;
    vector<pair<int, int>> ans;
    int cnt = 0;
    while (1) {
        int l = 0, r = n + 1;
        while (l <= n && v[l] == l) l ++;
        while (r > l && (v[r] == r || v[r] > v[l])) r --;
        if (l != r) sort(v.begin(), v.begin() + r + 1), cnt ++, ans.push_back({l, r});
        else break;
    }
    cout << cnt << endl;
    if (!cnt) return ;
    for (auto [x, y] : ans)
        cout << x << " " << y << endl;
}

int main(void) {
    scanf("%d", &T);
    while (T -- ) solve();
    system("pause");
    return 0;
}