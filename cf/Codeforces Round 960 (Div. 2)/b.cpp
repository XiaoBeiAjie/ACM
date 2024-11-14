#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> ans(n + 1);
    for (int i = y; i <= x; i ++ ) 
        ans[i] = 1;
    int cnt = 0;
    int a[] = {-1, 1};
    for (int i = y - 1; i; i -- ) {
        ans[i] = a[cnt & 1];
        cnt ++;
    }
    cnt = 0;
    for (int i = x + 1; i <= n; i ++ ) {
        ans[i] = a[cnt & 1];
        cnt ++;
    }
    for (int i = 1; i <= n; i ++ ) 
        cout << ans[i] << " ";
    cout << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}