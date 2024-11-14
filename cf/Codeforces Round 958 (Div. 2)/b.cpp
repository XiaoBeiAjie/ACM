#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    string w;
    cin >> w;
    w = " " + w;
    int last = 2, cnt0 = 0, cnt1 = 0;
    for (int i = 1; i <= n; i ++ ) {
        if (w[i] == '0' && last != 0) 
            last = 0, cnt0 ++;
        else if (w[i] == '1') 
            last = 1, cnt1 ++;
    }
    cout << (cnt1 > cnt0 ? "Yes" : "No") << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}