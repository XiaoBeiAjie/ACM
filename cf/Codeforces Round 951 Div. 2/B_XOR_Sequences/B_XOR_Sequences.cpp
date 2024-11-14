#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 100010;
typedef long long LL;

int T;
LL c[32];
void solve() {
    LL x, y;
    cin >> x >> y;
    for (int i = 0; i < 32; i ++ ) 
        if ((x & (1LL << i)) ^ (y & (1LL << i))) return cout << c[i] << endl, void();
       
}

int main(void) {
    scanf("%d", &T);
    c[0] = 1;
    for (int i = 1; i < 32; i ++ ) c[i] = c[i - 1] << 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}