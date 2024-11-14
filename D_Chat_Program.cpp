#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define ll long long
bool mem1;
const int N = 4e5 + 10;
ll k , m , c ,d;
ll n;
ll a[N];
ll tr[N];
ll tmp[N];
ll cnt[N];
ll la[N];
ll pre[N];
bool check(ll mid)
{
    for(int i = 1 ; i <= n ; i++)
        cnt[i] = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        if(i <= m) tmp[i] = a[i] + c + (i - 1) * d;
        else tmp[i] = a[i];
    }
    la[n + 1] = 0;
    for(int i = n ; i >= 1 ; i--)
        la[i] = la[i + 1] + (ll)(tmp[i] >= mid);
    for(int i = 1 ; i <= m ; i++)
    {
        if(tmp[i] >= mid)
        {
            ll tt;
            tt = (tmp[i] - mid) / d;
            cnt[i]++;
            cnt[m + tt + 1]--;
        }
        pre[i] = pre[i - 1] + cnt[i];
        if(pre[i] + la[i + 1] >= mid) return true;
    }
    for(int i = m + 1 ; i <= n ; i++)
    {
        tmp[i] += c + (m - 1) * d;
        if(tmp[i] >= mid) 
        {
            ll tt;
            tt = (tmp[i] - mid) / d;
            cnt[i]++;
            cnt[i + tt + 1]--;
        }
        pre[i] = pre[i - 1] + cnt[i];
        if(pre[i] + la[i + 1] >= mid) return true;
    }
    return false;
}
void solve() {
    cin >> n >> k >> m >> c >> d;
    for(int i = 1 ; i <= n ; i++)
        cin >> a[i];
    ll l = 0 , r = 1e17;
    while(l < r)
    {
        ll mid = (l +  r + 1) >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;

}

bool mem2;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    cerr << fixed << setprecision(2) << "Memory : " << abs(&mem1 - &mem2) / 1024. / 1024. << "MB\n";
    #endif
    int T = 1; 
    while (T -- ) solve();
    #ifdef LOCAL
    cerr << "Time : " << clock() * 1000 / CLOCKS_PER_SEC << "MS\n";
    #endif
    return 0;
}