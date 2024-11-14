#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long LL;

void solve() {
    map<array<int,2>,queue<int>> f;
    f[{0,1}].push(1);
    f[{0,1}].pop();
    if(f.find({0,1})!=f.end()) cout<<"tjj\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}