#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> dv(11);
    for (int i = 1; i <= 10; i ++ ) 
        cin >> dv[i];
    vector<array<int, 2>> w(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i][0] >> w[i][1];
        
}   

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}