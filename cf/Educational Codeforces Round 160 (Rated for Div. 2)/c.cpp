#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int m; cin >> m;
    vector<int> cnt(30);
    while (m -- ) {
        int op, x;
        cin >> op >> x;
        if (op == 1) 
            cnt[x] ++;
        else {
            int res = 0;
            bool f = true;
            for (int i = 0; i <= 29; i ++ ) {
                res >>= 1;
                res += cnt[i];
                if (x & (1 << i)) 
                    if (res) 
                        res --;
                    else 
                        f = false;
                    
            }
            cout << (f ? "Yes\n" : "No\n");
        }
        
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}