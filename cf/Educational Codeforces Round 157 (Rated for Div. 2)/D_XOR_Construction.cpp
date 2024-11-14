#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
typedef long long ll;

int idx;
int tr[N << 1][2];

void insert(int x) {
    int p = 0;
    for (int i = 30; i >= 0; i -- ) {
        int c = (x >> i) & 1;
        if (!tr[p][c])
            tr[p][c] = ++ idx;
        p = tr[p][c];
    }
}

int query(int x) {
    int p = 0, res = 0;
    for (int i = 30; i >= 0; i -- ) {
        int c = (x >> i) & 1;
        if (tr[p][c ^ 1]) {
            p = tr[p][c ^ 1];
            res += 1 << i;
        }  
        else 
            p = tr[p][c];
    }
    return res;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 1; i < n; i ++ ) {
        cin >> a[i], a[i] ^= a[i - 1];
        insert(a[i]);
    }   
    for (int i = 0; i < n; i ++ ) {
        if (query(i) >= n) continue;
        cout << i << " ";
        for (int j = 1; j < n; j ++ ) 
            cout << (i ^ a[j]) << " \n"[j == n - 1];
        return ;
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