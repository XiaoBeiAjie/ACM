#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n;
    string s;
    string t = "chuan";
    cin >> n >> s;
    int cnt = 0, idx = 0;
    while (idx < s.size() && s.find(t, idx) != -1) 
        cnt ++, idx = s.find(t, idx) + 5;
        
    
    cout << cnt << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}