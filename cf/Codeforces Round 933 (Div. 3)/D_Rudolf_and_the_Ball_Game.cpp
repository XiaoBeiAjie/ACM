#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, m, x; cin >> n >> m >> x;
    set<int> f;
    f.insert(-- x);
    while (m -- ) {
        int r; char op;
        cin >> r >> op;
        set<int> g;
        if (op == '?') {
            for (auto idx : f) {
                if (g.find((idx + r) % n) == g.end()) 
                    g.insert((idx + r) % n);
                if (g.find((idx - r + n) % n) == g.end())
                    g.insert((idx - r + n) % n);
            }
        }
        else if (op == '0') {
            for (auto idx : f) 
                if (g.find((idx + r) % n) == g.end()) 
                    g.insert((idx + r) % n);
        }  
        else if (op == '1') {
            for (auto idx : f)
                if (g.find((idx - r + n) % n) == g.end())
                    g.insert((idx - r + n) % n);
        }
            
        f = move(g);
    }
    cout << f.size() << "\n";
    for (auto u : f) 
        cout << u + 1 << " ";
    cout << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}