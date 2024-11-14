#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> w(n + 1);
    for (int i = 1; i <= n; i ++ ) {
        int a, b;
        cin >> a >> b;
        w[i] = {a, b};
    }
    int nl = 1, pl = 0, nr = 1, pr = 0;
    for (int i = 1; i <= n; i ++ ) {
        int l = w[i].first, r = w[i].second;
        int cl = 0x3f3f3f3f, cr = 0x3f3f3f3f;
        cl = min(cl, abs(nl - r) + (r - l) + pl);
        cl = min(cl, abs(nr - r) + (r - l) + pr);
        cr = min(cr, abs(nl - l) + (r - l) + pl);
        cr = min(cr, abs(nr - l) + (r - l) + pr);
        pl = cl, pr = cr, nl = l, nr = r;
        //cout << l << " " << pl << " " << r << " " << pr << "\n";
    }
    cout << min(pl + n - nl, pr + n - nr) + n - 1 << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}