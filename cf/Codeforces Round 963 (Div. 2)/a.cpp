#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int cnta = 0, cntb = 0, cntc = 0, cntd = 0;
    for (int i = 0; i < 4 * n; i ++ ) {
        if (s[i] == 'A' && cnta < n) 
            cnta ++;
        else if (s[i] == 'B' && cntb < n)
            cntb ++;
        else if (s[i] == 'C' && cntc < n)
            cntc ++;
        else if (s[i] == 'D' && cntd < n)
            cntd ++;
    }
        
    //cerr << cnta << " " << cntb << " " << cntc << " " << cntd << "\n";
    cout << cnta + cntb + cntc + cntd << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}