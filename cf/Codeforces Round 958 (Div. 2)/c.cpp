#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long LL;

vector<LL> mi(64);

int num(LL n) {
    int res = 0;
    for (LL i = 63; i >= 0; i -- ) 
        if (n & (1LL << i)) 
            mi[++ res] = i;
    
    return res;
}

void solve() {
    LL n;
    cin >> n;
    int res = num(n);
    if (res == 1) return cout << 1 << endl << n << endl, void();
    cout << res + 1 << endl;
    for (int i = 1; i <= res; i ++ ) 
        cout << n - (1LL << mi[i]) << " ";
    cout << n << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}