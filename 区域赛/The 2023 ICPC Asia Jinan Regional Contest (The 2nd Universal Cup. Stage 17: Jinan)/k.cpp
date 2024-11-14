#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long LL;

int T;

void solve() {
    LL n, k;
    cin >> n >> k;
    vector<LL> v(n + 1);
    for (int i = 1; i <= n; i ++ ) cin >> v[i], v[i] -= i;
    multiset<LL> s, b;
    s.insert(v[1]);
    LL s1 = v[1], s2 = 0;
    int ans = 1;
    for (int l = 1, r = 1; l <= n; l ++ ) {
        r = max(l + 1, r);
        while (r <= n) {
            if (v[r] > *s.rbegin()) {
                b.insert(v[r]);
                s2 += v[r];
                if ((LL)b.size() > (LL)s.size()) 
                {
                    s.insert(*b.begin());
                    s2 -= *b.begin();
                    s1 += *b.begin();
                    b.erase(b.begin());
                    
                }
            }
            else {
                s.insert(v[r]);
                s1 += v[r];
                if ((LL)s.size() - (LL)b.size() > 1) {
                    b.insert(*s.rbegin());
                    s1 -= *s.rbegin();
                    s2 += *s.rbegin();
                    s.erase(s.find(*s.rbegin()));
                }
            }
            LL mid1, mid2;
            if ((LL)s.size() != (LL)b.size()) mid2 = mid1 = *s.rbegin();
            else mid1 = (*s.rbegin()+*b.begin())/2, mid2 = (*b.begin()+*s.rbegin()+1)/2;
            if (k >= min((mid1 * (LL)s.size() - s1 + s2 - mid1 * (LL)b.size()),  (mid2 * (LL)s.size() - s1 + s2 - mid2 * (LL)b.size()))) r ++;
            else break;
        }
        ans = max(r - l, ans);
        if (v[l] <= *s.rbegin()) {
            s.erase(s.find(v[l]));
            s1 -= v[l];
            if ((LL)s.size() < (LL)b.size()) {
                s.insert(*b.begin());
                s2 -= *b.begin();
                s1 += *b.begin();
                b.erase(b.begin());
            }
        }
        else {
            b.erase(b.find(v[l]));
            s2 -= v[l];
            if ((LL)s.size() - (LL)b.size() > 1){
                b.insert(*s.rbegin());
                s2 += *s.rbegin();
                s1 -= *s.rbegin();
                s.erase(s.find(*s.rbegin()));
            }
        }
    }
    std::cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> T;
    while (T -- ) solve();
    //multiset<LL> s;multiset<LL> b;
    //s.insert(1);
    //cout<<b.size()-s.size()<<'\n';
    system("pause");
    return 0;
}