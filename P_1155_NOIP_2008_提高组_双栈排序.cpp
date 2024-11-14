#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n; 
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i];
    vector<int> mn(n + 2);
    mn[n + 1] = n + 1;
    for (int i = n; i; i -- ) 
        mn[i] = min(mn[i + 1], w[i]);
    vector e(n + 1, vector<int>());
    for (int i = 1; i <= n; i ++ ) 
        for (int j = i + 1; j <= n; j ++ ) 
            if (w[i] < w[j] && mn[j + 1] < w[i])
                e[i].push_back(j), e[j].push_back(i);
    vector<int> col(n + 1);
    
    function<void()> fun = [&] () {
        for (int i = 1; i <= n; i ++ ) {
            if (!col[i]) {
                queue<int> q;
                col[i] = 1;
                q.push(i);
                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    for (auto v : e[u]) {
                        if (col[v]) {
                            if (col[v] == col[u]) {
                                cout << "0\n";
                                exit(0);
                            }
                            continue;
                        }
                        col[v] = 3 ^ col[u];
                        q.push(v);
                    }
                }
            }
        }
    };
    fun();
    int cur = 0;
    vector<stack<int>> stk(3);
    function<bool(int)> check = [&] (int id) {
        if (stk[id].empty() || stk[id].top() != cur + 1) return false;
        return true;
    };
    function<void(int)> p = [&] (int id) {
        cur ++;
        stk[id].pop();
        cout << (id == 1 ? "b " : "d ");
    };
    for (int i = 1; i <= n; i ++ ) {
        int id = col[i];
        cerr << col[i] << " \n"[i == n];
        if (id == 2) 
            while (check(1)) p(1);
        while (!stk[id].empty() && stk[id].top() < w[i]) {
            if (!check(id)) p(3 ^ id);
            else p(id);
        }
        if (id == 2) 
            while (check(1)) p(1);
        stk[id].push(w[i]);
        cout << (id == 1 ? "a " : "c "); 
    }
    while (!stk[1].empty())
        if (!check(1)) p(2);
        else p(1);
    while (!stk[2].empty())
        p(2);
    cout << "\n";
        
    
}

int main (void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}