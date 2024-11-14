#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long LL;

int T;
struct node
{
    int first,second;
    bool operator<(const node &op)
    {
        if(first==op.first) return second>op.second;
        return first<op.first;
    }
};
void solve() {
    
}

int main(void) {
    T=1;
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while (T -- ) solve();
    system("pause");
    return 0;
}