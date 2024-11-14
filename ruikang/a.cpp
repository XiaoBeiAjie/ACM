#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long LL;

int a[4];
int b[4];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++ ) {
        int op, x;
        cin >> op >> x;
        if (op == 0) a[x] ++;
        else b[x] ++;
    }
    cout << a[1] << " " << a[2] << " " << a[3] << endl;
    cout << b[1] << " " << b[2] << " " << b[3] << endl;
    int f = 1;
    for (int i = 1; i <= 3; i ++ ) 
        if (a[i] == b[i]) continue;
        else {
            if (a[i] > b[i]) f = 1;
            else f = 0;
            break;
        } 
    cout << (f ? "The first win!" : "The second win!") << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}