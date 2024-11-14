#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 100010;
typedef long long LL;

int T;
int n, w[N];
int f[N][4];

bool P(int x) {
    for (int i = 2; i <= x / i; i ++ ) 
        if (x % i == 0) return false;
    return true;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> w[i];
    for (int i = 1; i <= n; i ++ ) 
        for (int j = 0; j < 4; j ++ ) 
            f[i][j] = 0x3f3f3f3f;
    f[1][0] = 0;
    f[1][1] = (w[1] != 1);
    f[1][2] = f[1][3] = 1;
    for (int i = 2; i <= n; i ++ ) {
        // 不变
        if (P(w[i] + w[i - 1])) f[i][0] = f[i - 1][0];
        f[i][0] = min(f[i][0], f[i - 1][2 + (w[i] & 1)]);
        if (P(w[i] + 1)) f[i][0] = min(f[i][0], f[i - 1][1]);
        //变1
        f[i][1] = min(f[i - 1][1], f[i - 1][3]) + 1;
        if (P(w[i - 1] + 1)) f[i][1] = min(f[i - 1][0] + 1, f[i][1]);
        //变奇数
        if (w[i - 1] & 1 ^ 1) f[i][2] = f[i - 1][0] + 1;
        f[i][2] = min(f[i][2], f[i - 1][3] + 1);
        //变偶数
        if (w[i - 1] & 1) f[i][3] = f[i - 1][0] + 1;
        f[i][3] = min({f[i][3], f[i - 1][2] + 1, f[i - 1][1] + 1});
    } 
    std::cout << min({f[n][0], f[n][1], f[n][2], f[n][3]}) << endl;
}

int main(void) {
    T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}