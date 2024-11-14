#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N = 1010;
typedef long long ll;
int n , m , hp, dmp;
char s[N][N];
void init()
{
    s[0][0] = s[0][m + 1]  = s[n + 1][0] = s[n + 1][m + 1] = '+';
    for(int i = 1; i <= m; i++)
        s[0][i] = s[n + 1][i] = '-';
    for(int i = 1; i <= n; i++)
        s[i][0] = s[i][m + 1] = '|';
}
void plie(int j , char c)
{
    for(int i = 1 ; i <= n ;i++)
        s[i][j] = c;
}
void solve() {
    cin >> n >> m >> hp >> dmp;
    init();
    int tmp = hp / m;
    int tt = hp / m;
    if(tmp == 0)
    {
        for(int i = 1 ; i <= m ;i++)
            plie(i, ' ');
    }
    else
    {
        tmp = tmp % 5;
        for(int i = 1 ; i <= m ; i++)
            plie(i , 'A' + (tmp + 4) % 5);
    }
    int now = hp % m;
    tt++;
    for(int i = 1; i <= now; i++)
        plie(i, 'A' + (tt + 4) % 5);
    int cnt = 0;
    int i = now;
    while(dmp != 0 && cnt != m)
    {
        if(i == 0) i = m;
        plie(i , '.');
        cnt ++;
        dmp--;
        i--;
        
    }
    for(int i = 0 ; i <= n + 1; i++)
    {
        for(int j = 0 ; j <= m + 1; j++)
            cout << s[i][j];
        cout << endl;
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