#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 200010;
typedef long long LL;

int T;
int n;
int a[N], b[N];
bool l[N], r[N];

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

void solve() {
    scanf("%d", &n);
    a[0] = 1;
    for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
    for (int i = 1; i < n; i ++ ) b[i] = gcd(a[i], a[i + 1]);
    b[n] = 0x3f3f3f3f;
    for (int i = 1; i <= n; i ++ ) l[i] = r[i] = 0;
    l[1] = 1, r[n] = 1, r[n - 1] = 1;
    for (int i = 2; i <= n; i ++ ) 
        l[i] = l[i - 1] && (b[i - 1] >= b[i - 2]);
    for (int i = n - 2; i; i -- ) 
        r[i] = r[i + 1] && (b[i] <= b[i + 1]);
    if (r[2] || l[n - 1]) return puts("YES"), void();
    bool f = 0;
    for (int i = 2; i < n; i ++ ) 
        if (l[i - 1] && r[i +  1] && gcd(a[i - 1], a[i + 1]) <= b[i + 1] && b[i - 2] <= gcd(a[i - 1], a[i + 1])) 
            return puts("YES"), void();
    puts("NO");
        
}

int main(void) {
    scanf("%d", &T);
    while (T -- ) solve();
    system("pause");
    return 0;
}