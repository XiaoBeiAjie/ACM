#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

ll xx1, xx2, yy1, yy2;
void solve() {
    cin >> xx1 >> yy1 >> xx2 >> yy2;
    long double tmp = sqrt((xx2 + xx1) * (xx2 + xx1) + (yy2 -  yy1) * (yy2 - yy1));
    long double tmp2 = sqrt((xx2 - xx1) * (xx2 - xx1) + (yy2 + yy1) * (yy2 + yy1));

    cout << fixed<<setprecision(11)<< min(tmp , tmp2) << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}