#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long LL;

string L, R, ans;
int len_l, len_r;

int fun(int idx, bool lo, bool hi, int minn, int maxx, string &a) {
    if (idx == len_l) 
        return maxx - minn;
    if (!lo & !hi) {
        for (int i = idx; i < len_l; i ++ ) 
            a[i] = a[0];
        return maxx - minn;
    }
    int l = 0, r = 9;
    if (lo) l = L[idx] - '0';
    if (hi) r = R[idx] - '0';
    int diff = 10;
    for (int i = l; i <= r; i ++ ) {
        string b = a;
        b[idx] = char('0' + i);
        int res = fun(idx + 1, lo & (i == L[idx] - '0'), hi & (i == R[idx] - '0'), min(minn, i), max(maxx, i), b);
        if (res < diff) 
            diff = res, a = b;        
    }
    return diff;
}

void solve() {
    LL l, r;
    cin >> l >> r;
    L = to_string(l);
    R = to_string(r);
    len_l = L.size(), len_r = R.size();
    if (len_l < len_r) {
        ans.assign(len_l, '9');
        cout << ans << endl;
        return ;
    }
    ans.assign(len_l, '*');
    fun(0, 1, 1, 9, 0, ans);
    cout << ans <<endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}