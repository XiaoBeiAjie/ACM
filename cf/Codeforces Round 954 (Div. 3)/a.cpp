#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 100010;
typedef long long LL;

int T;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << max({a, b, c}) - min({a, b, c}) << endl;;
}

int main(void) {
    scanf("%d", &T);
    while (T -- ) solve();
    system("pause");
    return 0;
}