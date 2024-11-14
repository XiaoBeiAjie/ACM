#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 2e5 + 10;
double a[N];
void solve() {
    int n; cin >> n;
    vector<long long> w(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i];
    long long sum = 0;
    for (int i = 1; i <= n; i ++ ) 
        sum += w[i];
    long double t = (long double)sum / (n + 1);
    cout << fixed<<setprecision(9)<<t*2<<' ';
    for(int i=1;i<n;++i)
    {
        cout << fixed<<setprecision(9)<<t<<' ';
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}