#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    int res = n, cnt = 0;
    if (!k) return cout << "0\n", void();
    k += n;
    while (k > 0) {
        cnt ++;
        k -= res;
        if (!(cnt & 1)) res --;
    }
    cout << cnt - 1 << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}