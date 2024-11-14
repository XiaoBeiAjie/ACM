#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1), c(n + 1);
    ll sum = 0;
    for (int i = 1; i <= n; i ++ ) 
        cin >> a[i], sum += a[i];
    for (int i = 1; i <= n; i ++ ) 
        cin >> b[i];
    for (int i = 1; i <= n; i ++ ) 
        cin >> c[i];
   
    ll base = (sum + 2) / 3;
    ll res1 = 0, idx1 = 0, res2 = 0, idx2 = 0, res3 = 0, idx3 = 0;
    // a b c
    idx1 = 0, res1 = 0;
    for (int i = 1; i <= n; i ++ ) {
        res1 += a[i];
        if (res1 >= base) {
            idx1 = i;
            break;
        }
    }
    if (idx1) {
        idx2 = 0, res2 = 0;
        for (int i = idx1 + 1; i <= n; i ++ ) {
            res2 += b[i];
            if (res2 >= base) {
                idx2 = i;
                break;
            }
        }
        if (idx2) {
            idx3 = 0, res3 = 0;
            for (int i = idx2 + 1; i <= n; i ++ ) {
                res3 += c[i];
                if (res3 >= base) {
                    idx3 = i;
                    break;
                }
            }
            if (idx3) {
                cout << 1 << " " << idx1 << " " << idx1 + 1 << " " << idx2 << " " << idx2 + 1 << " " << n << "\n";
                return ;            
            }
        }
    }

    // a c b

    idx1 = 0, res1 = 0;
    for (int i = 1; i <= n; i ++ ) {
        res1 += a[i];
        if (res1 >= base) {
            idx1 = i;
            break;
        }
    }
    if (idx1) {
        idx3 = 0, res3 = 0;
        for (int i = idx1 + 1; i <= n; i ++ ) {
            res3 += c[i];
            if (res3 >= base) {
                idx3 = i;
                break;
            }
        }
        if (idx3) {
            idx2 = 0, res2 = 0;
            for (int i = idx3 + 1; i <= n; i ++ ) {
                res2 += b[i];
                if (res2 >= base) {
                    idx2 = i;
                    break;
                }
            }
            if (idx2) {
                cout << 1 << " " << idx1 << " " << idx3 + 1 << " " << n << " " << idx1 + 1 << " " << idx3 << "\n";
                return ;            
            }
        }
    }

    // b a c
    idx2 = 0, res2 = 0;
    for (int i = 1; i <= n; i ++ ) {
        res2 += b[i];
        if (res2 >= base) {
            idx2 = i;
            break;
        }
    }
    if (idx2) {
        idx1 = 0, res1 = 0;
        for (int i = idx2 + 1; i <= n; i ++ ) {
            res1 += a[i];
            if (res1 >= base) {
                idx1 = i;
                break;
            }
        }
        if (idx1) {
            idx3 = 0, res3 = 0;
            for (int i = idx1 + 1; i <= n; i ++ ) {
                res3 += c[i];
                if (res3 >= base) {
                    idx3 = i;
                    break;
                }
            }
            if (idx3) {
                cout << idx2 + 1 << " " << idx1 << " " << 1 << " " << idx2 << " " << idx1 + 1 << " " << n << "\n";
                return ;            
            }
        }
    }

    // b c a
    idx2 = 0, res2 = 0;
    for (int i = 1; i <= n; i ++ ) {
        res2 += b[i];
        if (res2 >= base) {
            idx2 = i;
            break;
        }
    }
    if (idx2) {
        idx3 = 0, res3 = 0;
        for (int i = idx2 + 1; i <= n; i ++ ) {
            res3 += c[i];
            if (res3 >= base) {
                idx3 = i;
                break;
            }
        }
        if (idx3) {
            idx1 = 0, res1 = 0;
            for (int i = idx3 + 1; i <= n; i ++ ) {
                res1 += a[i];
                if (res1 >= base) {
                    idx1 = i;
                    break;
                }
            }
            if (idx1) {
                cout << idx3 + 1 << " " << n << " " << 1 << " " << idx2 << " " << idx2 + 1 << " " << idx3 << "\n";
                return ;            
            }
        }
    }

    // c a b
    idx3 = 0, res3 = 0;
    for (int i = 1; i <= n; i ++ ) {
        res3 += c[i];
        if (res3 >= base) {
            idx3 = i;
            break;
        }
    }
    if (idx3) {
        idx1 = 0, res1 = 0;
        for (int i = idx3 + 1; i <= n; i ++ ) {
            res1 += a[i];
            if (res1 >= base) {
                idx1 = i;
                break;
            }
        }
        if (idx1) {
            idx2 = 0, res2 = 0;
            for (int i = idx1 + 1; i <= n; i ++ ) {
                res2 += b[i];
                if (res2 >= base) {
                    idx2 = i;
                    break;
                }
            }
            if (idx2) {
                cout << idx3 + 1 << " " << idx1 << " " << idx1 + 1 << " " << n << " " << 1 << " " << idx3 << "\n";
                return ;            
            }
        }
    }

    // c b a
    idx3 = 0, res3 = 0;
    for (int i = 1; i <= n; i ++ ) {
        res3 += c[i];
        if (res3 >= base) {
            idx3 = i;
            break;
        }
    }
    if (idx3) {
        idx2 = 0, res2 = 0;
        for (int i = idx3 + 1; i <= n; i ++ ) {
            res2 += b[i];
            if (res2 >= base) {
                idx2 = i;
                break;
            }
        }
        if (idx2) {
            idx1 = 0, res1 = 0;
            for (int i = idx2 + 1; i <= n; i ++ ) {
                res1 += a[i];
                if (res1 >= base) {
                    idx1 = i;
                    break;
                }
            }
            if (idx1) {
                cout << idx2 + 1 << " " << n << " " << idx3 + 1 << " " << idx2 << " " << 1 << " " << idx3 << "\n";
                return ;            
            }
        }
    }
    cout << "-1\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}