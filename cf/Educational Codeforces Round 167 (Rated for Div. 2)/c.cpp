#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
typedef long long LL;

int n;
int a[N], b[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    for (int i = 1; i <= n; i ++ ) cin >> b[i];
    int c1 = 0, c2 = 0, cc = 0, ss = 0;
    for (int i = 1; i <= n; i ++ ) 
        if (a[i] == 1 && b[i] != 1) c1 ++;
        else if (a[i] != 1 && b[i] == 1) c2 ++;
        else if (a[i] == 1 && b[i] == 1) cc ++;
        else if (a[i] == -1 && b[i] == -1) ss ++;
    if (c1 > c2) swap(c1, c2);
    //cout << c1 << "!!" << c2 << " " << cc << " " << ss << endl;
    if (cc >= c2 - c1) cc -= (c2 - c1), c1 = c2;
    else c1 += cc, cc = 0;
    c1 = c1 + cc / 2;
    c2 = c2 + cc - cc / 2;
    //cout << c1 << " !!" << c2 << endl;
    if (ss >= c2 - c1) ss -= (c2 - c1), c2 = c1;
    else c2 -= ss, ss = 0;
    c1 = c1 - ss / 2;
    c2 = c2 - ss + ss / 2;
    cout << min(c1, c2) << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}