#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

struct Hole {
    ll x, y, z;
};

void solve() {
    ll n, h, r;
    cin >> n >> h >> r;
    vector<int> p(n + 2);
    for (int i = 1; i <= n + 1; i ++ ) 
        p[i] = i;
    vector<Hole> hole(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> hole[i].x >> hole[i].y >> hole[i].z;
    function<int(int)> find = [&] (int x) {
        return x == p[x] ? x : p[x] = find(p[x]);
    };

    for (int i = 1; i <= n; i ++ ) {
        if (hole[i].z <= r) {
            int f = find(i);
            p[f] = 0;
        }
        if (hole[i].z >= h - r) {
            int f = find(i);
            p[f] = n + 1;
        } 
    }
    for (int i = 1; i <= n; i ++ ) 
        for (int j = i + 1; j <= n; j ++ ) {
            if ((hole[i].x - hole[j].x) * (hole[i].x - hole[j].x) + (hole[i].y - hole[j].y) * (hole[i].y - hole[j].y) + (hole[i].z - hole[j].z) * (hole[i].z - hole[j].z) > 4 * r * r)
                continue;
            int fi = find(i), fj = find(j);
            if (fi == fj) continue;
            p[fi] = fj;
        }
    if (find(0) == find(n + 1)) cout << "Yes\n";
    else cout << "No\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}