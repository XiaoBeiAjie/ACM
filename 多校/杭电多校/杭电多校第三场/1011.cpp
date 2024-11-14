#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n; cin >> n;
    ll miny = 0x3f3f3f3f, maxy = -0x3f3f3f3f;
    ll minx = 0x3f3f3f3f, maxx = -0x3f3f3f3f;
    ll eminx = 0x3f3f3f3f, emaxx = -0x3f3f3f3f;
    ll wminx = 0x3f3f3f3f, wmaxx = -0x3f3f3f3f;
    ll sminy = 0x3f3f3f3f, smaxy = -0x3f3f3f3f;
    ll nminy = 0x3f3f3f3f, nmaxy = -0x3f3f3f3f;
    for (int i = 1; i <= n; i ++ ) {
        ll x, y;
        char d;
        cin >> x >> y >> d;
        if (d == 'E' || d == 'W') {
            maxy = max(maxy, y), miny = min(miny, y);
            if (d == 'E')
                emaxx = max(emaxx, x), eminx = min(eminx, x);
            else 
                wminx = min(wminx, x), wmaxx = max(wmaxx, x);
        }
        else {
            maxx = max(maxx, x), minx = min(minx, x);
            if (d == 'N')
                nminy = min(nminy, y), nmaxy = max(nmaxy, y);
            else 
                sminy = min(sminy, y), smaxy = max(smaxy, y);
        }
    }
    vector<ll> t;
    t.push_back(0);
    t.push_back(max(maxx - emaxx, 0ll));
    t.push_back(max(0ll, wminx - minx));
    t.push_back(max((wminx - emaxx + 1) / 2 , 0ll));
    t.push_back(max((wminx - emaxx) / 2 , 0ll));
    t.push_back(max((wminx - eminx + 1) / 2 , 0ll));
    t.push_back(max((wminx - eminx) / 2 , 0ll));
    t.push_back(max((wmaxx - emaxx + 1) / 2 , 0ll));
    t.push_back(max((wmaxx - emaxx) / 2 , 0ll));
    t.push_back(max((wmaxx - eminx + 1) / 2 , 0ll));
    t.push_back(max((wmaxx - eminx) / 2 , 0ll));

    t.push_back(max(maxy - nmaxy, 0ll));
    t.push_back(max(0ll, sminy - miny));
    t.push_back(max((sminy - nmaxy + 1) / 2 , 0ll));
    t.push_back(max((sminy - nmaxy) / 2 , 0ll));
    t.push_back(max((sminy - nminy + 1) / 2 , 0ll));
    t.push_back(max((sminy - nminy) / 2 , 0ll));
    t.push_back(max((smaxy - nmaxy + 1) / 2 , 0ll));
    t.push_back(max((smaxy - nmaxy) / 2 , 0ll));
    t.push_back(max((smaxy - nminy + 1) / 2 , 0ll));
    t.push_back(max((smaxy - nminy) / 2 , 0ll));
    ll ans = LLONG_MAX;
    for (auto tt : t) {
        ll dmx = max({maxx, wmaxx - tt, emaxx + tt});
        ll dnx = min({minx, wminx - tt, eminx + tt});
        ll dmy = max({maxy, smaxy - tt, nmaxy + tt});
        ll dny = min({miny, sminy - tt, nminy + tt});
        ans = min(2 * (dmx - dnx) + 2 * (dmy - dny), ans);
    }
    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}