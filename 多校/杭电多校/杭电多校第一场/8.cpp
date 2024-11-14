#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long LL;

LL qmi(LL a, LL b) {
    LL res = 1;
    while (b) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void solve() {
    LL n, k;
    cin >> n >> k;
    int cnt = 0;
    for (int i = 0; i < k; i ++ ) 
        if (n & (1 << i)) cnt ++;
    cout << qmi(2, 4 * k) / qmi(4, k) * qmi(3, cnt)  << '\n';
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}