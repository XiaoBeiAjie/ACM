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
    vector<int> v(n + 10);
    int minn = 0x3f3f3f3f;
    for (int i = 1; i <= n; i ++ ) cin >> v[i];
    for (int i = 1; i < n; i ++ ) minn = min(max(v[i], v[i + 1]), minn);
    printf("%d\n", minn - 1);
}

int main(void) {
    scanf("%d", &T);
    while (T -- ) solve();
    system("pause");
    return 0;
}