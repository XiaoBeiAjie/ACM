#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n, k; cin >> n >> k;
    bool ans = true;
    vector<int> res1(n + 1), res2(n + 1), rk(n + 1);
    k --;
    for (int i = 0; i < n; i ++ ) 
        cin >> res1[i];
    int last = res1[0];
    if (k == 0) return cout << "Yes\n", void();
    k --;
    for (int i = 0; i < n; i ++ ) 
        cin >> res2[i];
    int cur = res2[0];
    int idx = 1, i = 1, j = 1;
    int t1, t2;
    while (i < n || j < n) {
        if (res1[i] == res2[j]) rk[idx ++] = res1[i ++], j ++;
        else if (res1[i] == cur) t1 = idx, rk[idx ++] = res1[i ++];
        else if (res2[j] == last) t2 = idx, rk[idx ++] = res2[j ++];
        else {
            ans = false;
            break;
        }
    }
    int cnt = 0;
    while (k -- ) {
        cin >> cur;
        int x;
        idx = 1;
        for (int i = 1; i < n; i ++ ) {
            if (rk[idx] == cur) idx ++;
            cin >> x;
            if (x == rk[idx]) idx ++;
            else if (!cnt && idx == min(t1, t2) && x == rk[idx + 1]) {
                swap(rk[t1], rk[t2]);
                idx ++;
            }
            else ans = false;;
        }
        cnt ++;
    }
    cout << (ans ? "Yes\n" : "No\n");
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}