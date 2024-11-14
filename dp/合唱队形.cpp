#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long LL;

int n;
int w[N];
int l[N], r[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i ++ ) 
        l[i] = r[i] = 1;
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i];
    for (int i = 1; i <= n; i ++ ) 
        for (int j = 1; j < i; j ++ ) 
            if (w[i] > w[j]) l[i] = max(l[i], l[j] + 1);
    for (int i = n; i; i -- ) 
        for (int j = n; j > i; j -- ) 
            if (w[i] > w[j]) r[i] = max(r[i], r[j] + 1);
    int ans = 0;
    for (int i = 1; i <= n; i ++ ) 
        ans = max(ans, l[i] + r[i] - 1);
    cout << n - ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}