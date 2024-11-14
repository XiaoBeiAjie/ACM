#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long LL;

void solve() {
    vector<int> w;
    int x;
    while (cin >> x) w.push_back(x);
    vector<int> f1(w.size() + 1), f2(w.size() + 1, 0x3f3f3f3f);
    f1[1] = f2[1] = w[0];
    int len1 = 1, len2 = 1;
    for (int i = 1; i < w.size(); i ++ ) {
        if (f1[len1] >= w[i]) f1[++ len1] = w[i];
        else f1[upper_bound(f1.begin() + 1, f1.begin() + len1 + 1, w[i], greater<int>()) - f1.begin()] = w[i];
        if (f2[len2] < w[i]) f2[++ len2] = w[i];
        else f2[lower_bound(f2.begin() + 1, f2.begin() + len2 + 1, w[i]) - f2.begin()] = w[i];
    }
    cout << len1 << endl << len2 << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}