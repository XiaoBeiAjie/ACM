#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long LL;

int n, m, k;
string s;
int cnt[30];
char ans[30];

void solve() {
    cin >> n >> k >> m;
    cin >> s;
    s = " " + s;    
    set<int> st;
    int idx = 0;
    char last;
    for (int i = 1; i <= m; i ++ ) {
        if (st.find(s[i] - 'a') == st.end()) st.insert(s[i] - 'a'), last = s[i];
        if (st.size() == k) st.clear(), ans[++ idx] = s[i];
    }
    if (idx < n) {
        cout << "No" << endl;
        for (int i = 0; i < k; i ++ ) 
            if (st.find(i) == st.end()) {
                for (int j = 1; j <= idx; j ++ ) 
                    cout.put(ans[j]);
                for (int j = idx; j < n; j ++ ) 
                    cout.put('a' + i);
                cout << endl;
                return ;
            }
                
    } else cout << "Yes" << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}