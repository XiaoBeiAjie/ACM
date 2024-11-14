#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

ll a[N];
void solve() {
    int n ;
    cin >> n;
    for(int i = 1; i <= n ; i++)
        cin >> a[i];
    for(int i = 1; i <= n ; i++)
        cout << a[i];
    for(int i = 1 ; i <= n ; i++)
        cout << a[i];
    for(int i = 1; i <= n ; i++)   
        cout << a[i];
    for(int i = 1 ; i <= n ; i++)
        cout << a[i];
    
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}