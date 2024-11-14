#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long LL;

void solve() {
    int n; cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i ++ ) {
        cin >> v[i];
        int x;
        for (int j = 1; j < v[i]; j ++ ) 
            cin >> x;
    }
    int ans = 0;
    sort(v.begin() + 1, v.end(), greater<int>());
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 20; ~j; j -- ) 
            if (v[i] & (1 << j))
                if (ans & (1 << j)) {
                    ans |= (1 << j + 1) - 1;
                    break;
                }   
                else {
                    v[i] ^= 1 << j; 
                    ans |= 1 << j;
                }
    }
    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}