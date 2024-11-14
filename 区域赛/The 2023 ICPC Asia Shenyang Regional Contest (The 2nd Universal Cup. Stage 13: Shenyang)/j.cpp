#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 100010;
typedef long long LL;

int T;

void solve() {
    int n;
    cin >> n;
    vector<int> d(n + 1);
    for (int i = 1; i < n; i ++ ) {
        int a, b;
        cin >> a >> b;
        d[a] ++, d[b] ++;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i ++ ) 
        if (d[i] > 1) cnt ++;
    if (!cnt) cout << "Bob";
    else cout << (cnt & 1 ? "Bob" : "Alice") << endl;  
}

int main(void) {
    T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}