#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i];
    sort(w.begin(), w.end());
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; i ++ ) 
        if (w[i] & 1) cnt1 ++;
        else cnt2 ++;
    if (!cnt1 || !cnt2) cout << "0\n";
    else {
        
        int idx = n;
        while (!(w[idx] & 1)) idx --;
        ll res = w[idx];
        for (int i = 1; i <= n; i ++ ) 
            if (!(w[i] & 1)) {
                if (w[i] < res) res += w[i];
                else {
                    cout << cnt2 + 1 << "\n";
                    return ;
                }
            } 
        
        cout << cnt2 << "\n";  
        
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}