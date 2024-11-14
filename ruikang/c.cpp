#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long LL;

int cnt, l;
vector<int> a(5);

int level(vector<int> a) {
    sort(a.begin(), a.end());
    if (a[0] == a[4]) return 8;
    if (a[0] == a[3] || a[1] == a[4]) return 7;
    if ((a[0] == a[2] && a[3] == a[4]) || (a[0] == a[1] && a[2] == a[4])) return 6;
    if (a[0] == 2 && a[1] == 3 && a[2] == 4 && a[3] == 5 && a[4] == 6) return 5;
    if (a[0] == 1 && a[1] == 2 && a[2] == 3 && a[3] == 4 && a[4] == 5) return 4;
    if ((a[0] == a[2]) || (a[1] == a[3]) || (a[2] == a[4])) return 3;
    if ((a[0] == a[1] && a[2] == a[3]) || (a[0] == a[1] && a[4] == a[3]) 
        || (a[2] == a[1] && a[4] == a[3])) return 2;
    if ((a[0] == a[1]) 
        || (a[1] == a[2])
        || (a[2] == a[3])
        || (a[3] == a[4])) return 1;
    return 0;
}

void dfs(int idx, vector<int> &b, int k) {
    if (idx == 5) {
        if (level(b) > l) cnt ++;
        return ;
    }
    if ((k >> idx) & 1) 
        for (int i = 1; i <= 6; i ++ ) {
            b[idx] = i;
            dfs(idx + 1, b, k);
            b[idx] = a[idx];
        } 
    else dfs(idx + 1, b, k);                
}

int num(int k) {
    int res = 0;
    while (k) {
        if (k & 1) res ++;
        k >>= 1;
    }
    return res;
}

int qmi(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

void solve() {
    for (auto & it : a) 
        cin >> it;
    sort(a.begin(), a.end());
    l = level(a);
    int ansc = 0, fz = 0, fm = 1;
    for (int k = 1; k < (1 << 5); k ++ ) {
        vector<int> b = a;
        cnt = 0;
        dfs(0, b, k);
        int t = num(k);
        int rm = qmi(6, t), rz = cnt;
        int rg = __gcd(rm, rz);
        rz /= rg, rm /= rg;
        if (rz * fm > fz * rm) ansc = t, fz = rz, fm = rm;
        else if (rz * fm == fz * rm && t < ansc) ansc = t, fz = rz, fm = rm;
    }
    cout << ansc << " " << fz << " " << fm << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}