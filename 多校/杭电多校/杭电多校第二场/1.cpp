#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    int cnt = 0;
    for(int l = 2 , r = n / 3  + 3, j = 1 ;  cnt < n ; l++ , r--, j++)
    {
        for(int i = l ; i <= r; i++)
        {
            cout << j << " " << i << endl, cnt ++;
            if(cnt == n) return ;
        }
            
        if(j == 1)
        {
            for(int i = 1 ; i <= n % 3 ; i++)
            {
                cout << j <<  " "  << n / 3  + 3 + i << endl , cnt ++;
                if(cnt == n) return ;
            }
                
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}