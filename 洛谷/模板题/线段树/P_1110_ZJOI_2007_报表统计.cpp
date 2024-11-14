#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    priority_queue<int, vector<int>, greater<int>> q;
    multiset<int> mst, qst;
    vector<array<int, 2>> v(n + 1);
    constexpr int inf = 0x3f3f3f3f;
    mst.insert(-inf), mst.insert(inf);
    for (int i = 1; i <= n; i ++ ) {
        int x; cin >> x;
        auto it = mst.lower_bound(x);
        q.push(min(*it - x, x - *prev(it)));
        mst.insert(x);
        v[i][0] = v[i][1] = x;
        if (i != 1) qst.insert(abs(v[i][0] - v[i - 1][1])); 
    }
    function<void()> insert = [&] () {
        int x, k;
        cin >> x >> k;
        if (x != n) {
            qst.erase(qst.find(abs(v[x][1] - v[x + 1][0])));
            qst.insert(abs(v[x + 1][0] - k));
        }     
        qst.insert(abs(v[x][1] - k));
        v[x][1] = k;
        auto it = mst.lower_bound(k);
        q.push(min(*it - k, k - *prev(it)));
        mst.insert(k);
    };
    while (m -- ) {
        string op; cin >> op;
        if (op[4] == 'R') 
            insert();
        else if (op[4] == 'G') 
            cout << *qst.begin() << "\n";
        else 
            cout << q.top() << "\n";
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}