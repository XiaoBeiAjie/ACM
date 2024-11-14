#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 100010;
typedef long long LL;

int T;
int n, m;
string s;
int cnt[N];

void solve() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < 26; i ++ ) cnt[i] = 0;
    cin >> s;
    s = " " + s;
    for (int i = 1; i <= n; i ++ ) 
        cnt[s[i] - 'A'] ++;
    int ans = 0;
    for (int i = 0; i < 7; i ++ ) 
        ans += max(0, m - cnt[i]);
    printf("%d\n", ans);
}

int main(void) {
    scanf("%d", &T);
    while (T -- ) solve();
    system("pause");
    return 0;
}