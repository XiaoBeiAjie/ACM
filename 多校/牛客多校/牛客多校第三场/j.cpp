#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

int pos[N];
int val[N];
int dpa[N];
int dpb[N];
bool st[N];
int dpa2[N];
int dpa3[N];
void solve() {
    int n , a , b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    while(s.length() < n + (2 * a - 1) + 10) s += s;
    s = " " + s;
    cout << s << endl;
    for(int i = 1 ; i <= n + (2 * a - 1) + 10 ; i++)
    {
        dpa[i] = (s[i] == '1') + dpa[i - 1];
        dpb[i] = (s[i] == '0') + dpb[i - 1];
    }
    int m = n + (2 * a - 1) + 10+1;
    for(int i = 1 ; i <= n; i++)
    {
        int tmpa = lower_bound(dpa + i, dpa + m, dpa[i - 1] + a) - dpa;
        int tmpb = lower_bound(dpb + i, dpb + m, dpb[i - 1] + a) - dpb;
        if(tmpa < tmpb) val[i] = 1 , pos[i] = (tmpa) % n + 1;
        else val[i] = 0, pos[i] = (tmpb) % n + 1;
    }
    int tt = 1;
    vector<int > vtmp;
    int sz;
    while(!st[tt])
    {
        st[tt] = 1;
        dpa2[sz + 1] = dpa2[sz] + dpa2[tt];
        vtmp.push_back(tt);
        sz ++;
        tt = pos[tt];
    }
    int tmpva = dpa[n] - dpa[tt - 1];
    int tmpvb = dpb[n] - dpb[tt - 1];
    
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}