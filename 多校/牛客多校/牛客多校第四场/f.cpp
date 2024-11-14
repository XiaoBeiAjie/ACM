#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;
using ll=long long;
#define endl "\n"
void solve() {
    ll n;cin>>n;
    ll x = sqrt(n) + (1e-9);
    ll y = n / x;
    ll tmpans = 9e18;
    if(x * y == n)
    {
        tmpans = min(tmpans, x + y + 1);
    }
    if((x & 1) || (y & 1)) 
    {
        if((n - x * y) & 1)
            tmpans = min(tmpans, x + y + 2);
        else   
            tmpans = min(tmpans, x + y + 3);
    }
    else
    {
        if(!((n - x * y) & 1))
            tmpans = min(tmpans, x + y + 2);
    }
    ll tmpx = x;   
    ll tmpy = y;
    x--;
    if(x == 0) x = 1;
    y = n / x;
    if(x * y == n)
    {
        tmpans = min(tmpans, x + y + 1);
    }
    if((x & 1) || (y & 1)) 
    {
        if((n - x * y) & 1)
            tmpans = min(tmpans, x + y + 2);
        else   
            tmpans = min(tmpans, x + y + 3);
    }
    else
    {
        if(!((n - x * y) & 1))
            tmpans = min(tmpans, x + y + 2);
    }
    x = tmpx;
    y = tmpy;
    y--;
    if(y == 0) y = 1;
    x = n / y;
    if(x * y == n)
    {
        tmpans = min(tmpans, x + y + 1);
    }
    if((x & 1) || (y & 1)) 
    {
        if((n - x * y) & 1)
            tmpans = min(tmpans, x + y + 2);
        else   
            tmpans = min(tmpans, x + y + 3);
    }
    else
    {
        if(!((n - x * y) & 1))
            tmpans = min(tmpans, x + y + 2);
    }
    cout << tmpans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    srand((unsigned)time(NULL));
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}