#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct node {
    char op;
    i64 x, y;
    i64 x1, y1;
    i64 r;
    char c;
};

void solve() {
    int n; cin >> n;
    vector<node> w;
    function<char(int, int)> check = [&] (int x, int y) {
        for (int i = w.size() - 1; i >= 0; i -- ) {
            if (w[i].op == 'r') {
                if ((x - w[i].x) * (x - w[i].x) + (y - w[i].y) * (y - w[i].y) <= w[i].r * w[i].r) 
                    return w[i].c;
            }
            else if (w[i].op == 'c') {
                if (x >= w[i].x && x <= w[i].x1 && y >= w[i].y && y <= w[i].y1) 
                    return w[i].c;
            }
        }  
        return '.';          
    };
    for (int i = 1; i <= n; i ++ ) {
        string s; cin >> s;
        if (s[2] == 'r') {
            i64 x, y, r; cin >> x >> y >> r;
            char c; cin >> c;
            w.push_back({'r', x, y, 0, 0, r, c});
        }
        else if (s[2] == 'c') {
            i64 x, y, x_, y_;
            char c;
            cin >> x >> y >> x_ >> y_ >> c;
            w.push_back({'c', x, y, x_, y_, 0, c});
        }
        else {
            i64 x, y, x_, y_;
            cin >> x >> y >> x_ >> y_;
            for (int j = y_; j >= y; j -- ) {
                for (int i = x; i <= x_; i ++ )
                    cout << check(i, j);
                cout << "\n";
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}