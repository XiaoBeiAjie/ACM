#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> cnta(n + 1), cntb(n + 1);
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> a[i], cnta[a[i]] ++;
    for (int i = 1; i <= n; i ++ ) 
        cin >> b[i], cntb[b[i]] ++;
    int len = k << 1;
    k <<= 1;
    vector<int> ansa, ansb;
    int cnt = 0;
    for (int i = 1; i <= n; i ++ ) {
        if (cnta[i] == 2) 
            ansa.push_back(i), ansa.push_back(i), cnt += 2;
        if (cnt == k) break;
    }
    cnt = 0;
    for (int i = 1; i <= n; i ++ ) {
        if (cntb[i] == 2) 
            ansb.push_back(i), ansb.push_back(i), cnt += 2;
        if (cnt == k) break;
    }
    k -= cnt;
    for (int i = 1; i <= n; i ++ ) {
        if (1 == cntb[i] && cnta[i] == 1) 
            ansa.push_back(i), ansb.push_back(i), k -- ;
        if (!k) break;
    }
    for (int i = 0; i < len; i ++ ) 
        cout << ansa[i] << " \n"[i == len - 1];
    for (int i = 0; i < len; i ++ )
        cout << ansb[i] << " \n"[i == len - 1];
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}