#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 100010;
typedef long long LL;

int T;
int n, m;
int w[N];
string s1, s2;

void solve() {
    cin >> n >> m;
    cin >> s1;
    for (int i = 1; i <= m; i ++ ) 
        cin >> w[i];
    cin >> s2;
    sort(w + 1, w + 1 + m);
    sort(s2.begin(), s2.end());
    for (int i = 1, j = 0; i <= m; i ++ ) 
        if (w[i] == w[i - 1]) continue;
        else s1[w[i] - 1] = s2[j ++]; 
    cout << s1 << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}