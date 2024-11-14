#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    string s;cin>>s;
    string p="";
    for(int i=0;i<8;i+=2)
    {
        p+=s[i];
    }
    string pp="";
    for(int i=0;i<4;i+=2) pp+=p[i];
    vector<int> cnt(4,0);
    
    if(pp[0]==pp[1]) cout<<pp[0]<<'\n';
    else 
    {
        int cnt0=0,cnt1=0;
        for(int i=0;i<8;++i)
        {
            if(s[i]==pp[0]) ++cnt0;
            else if(s[i]==pp[1]) ++cnt1;
        }
        if(cnt0==cnt1) cout<<'N'<<'\n';
        else if(cnt0>cnt1) cout<<pp[0]<<'\n';
        else cout<<pp[1]<<'\n';
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