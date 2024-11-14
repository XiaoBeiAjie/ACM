#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int m; cin >> m;
    int sum1 = 0, sum2 = 0;
    vector<int> mid;
    while (m -- ) {
        int n; cin >> n;
        int x;
        for (int i = 1; i <= n >> 1; i ++ ) 
            cin >> x, sum1 += x;
        if (n & 1) 
            cin >> x, mid.push_back(x);
        for (int i = 1; i <= n >> 1; i ++ ) 
            cin >> x, sum2 += x;
    }
    sort(mid.begin(), mid.end(), greater<int>());
    for (int i = 0; i < mid.size(); i ++ ) 
        if (i & 1) 
            sum2 += mid[i];
        else 
            sum1 += mid[i];
    cout << sum1 << " " << sum2 << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}