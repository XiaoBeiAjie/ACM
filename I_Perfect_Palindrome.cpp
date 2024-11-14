#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

bool mem1;

void solve() {
    string s;
    cin >> s;
    vector<int > ct(30 , 0);
    int len = s.length();
    for(int i = 0 ; i < len ; i ++)
        ct[s[i] - 'a'] ++;
    int maxx = 0;
    for(int i = 0 ; i < 26 ; i++)
        maxx = max(maxx , ct[i]);
    cout << len - maxx << endl;
}

bool mem2;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    cerr << fixed << setprecision(2) << "Memory : " << abs(&mem1 - &mem2) / 1024. / 1024. << "MB\n";
    #endif
    int T; cin >> T;
    while (T -- ) solve();
    #ifdef LOCAL
    cerr << "Time : " << clock() * 1000 / CLOCKS_PER_SEC << "MS\n";
    #endif
    return 0;
}