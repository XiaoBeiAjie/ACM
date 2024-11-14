#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

bool mem1;

void solve() {
    int n;
    cin >> n;
    vector<int > a(n + 2);
    for(int i = 0 ; i < n  ; i ++)
        cin >> a[i];
    int cnt = 0;
    int fz = 1  , fm = 1;
    for(int i = 0 ; i < n ; i++)
    {
        if(a[i] == 0)
        {
            if(fm == 1)
            {
                fz++;
                fm++;
            }
            else 
            {
                cnt++;
                fm--;
            }
        }
        else if(a[i] == -1)
        {
            if(fm == 1)
            {
                if(cnt == 0)
                {
                    cout << -1 << endl;
                    return ;
                }
                else
                {
                    cnt--;
                    fm++;
                    fz++;
                    fm++;
                    fm--;
                }
            }
            else
                fm--;
        }
        else
        {
            fz++;
            fm++;
        }
    }
    //cerr << fz << ' ' << fm << endl;
    int tmp = __gcd(fz , fm);
    cout << fz / tmp << ' ' << fm / tmp << endl;
}

bool mem2;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    cerr << fixed << setprecision(2) << "Memory : " << abs(&mem1 - &mem2) / 1024. / 1024. << "MB\n";
    #endif
    int T; cin >> T;
    while (T -- ) solve();
    #ifdef LOCAL
    cerr << "Time : " << clock() * 1000 / CLOCKS_PER_SEC << "MS\n";
    #endif
    return 0;
}