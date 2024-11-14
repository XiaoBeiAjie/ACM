#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 100010;
typedef long long LL;

int T;

void solve() {
    int a, b;
    cin >> a >> b;
    int cnt = 0;
    while (a != 3) {
        if (a == 2 || b == 2) cnt += 2;
        else cnt ++;
        a ++;
    }
    cout << cnt << endl;
}

int main(void) {
    T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}