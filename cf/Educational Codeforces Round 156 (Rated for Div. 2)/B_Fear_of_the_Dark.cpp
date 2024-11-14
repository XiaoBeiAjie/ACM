#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    ll x, y;
    cin >> x >> y;
    ll nx, ny;
    cin >> nx >> ny;
    ll mx, my;
    cin >> mx >> my;
    if (!x && !y) return cout << "0\n", void();
    long double ans1 = sqrtl((nx - mx) * (nx - mx) + (ny - my) * (ny - my));
    bool f1 = false, f2 = false;
    double res1 = sqrtl((x - nx) * (x - nx) + (y - ny) * (y - ny)), res2 = sqrtl((x - mx) * (x - mx) + (y - my) * (y - my));
    long double ans2 = min(res1, res2);
    if (ans2 == res1) f1 = true;
    res1 = sqrtl(nx * nx + ny * ny), res2 = sqrtl(mx * mx + my * my);
    long double ans3 = min(res1, res2);
    if (ans3 == res1) f2 = true;
    if (f1 ^ f2) cout << fixed << setprecision(15) << max({ans1 / 2.0, ans2, ans3}) << "\n";
    else cout << fixed << setprecision(15) << max({ans2, ans3}) << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}