#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    string s;cin>>s;
    for(int i=0;i<(int)s.size();++i)
    {
        if(s[i]!='v'&&s[i]!='a') return cout<<"No\n",void();
    }
    if(s[0]!='a'||s[(int)s.size()-1]!='a') return cout<<"No\n",void();
    string cur="";
    for(int i=0;i<(int)s.size();++i)
    {
        char it=s[i];
        cur+=it;
        if(it=='a'&&(i+1==(int)s.size()||s[i+1]=='a'))
        {
            if(cur!="ava"&&cur!="avava") return cout<<"No\n",void();
            cur.clear();
        } 
        if(cur=="avava")
        {
            cur.clear();
        }
        if(cur.length()>5) return cout<<"No\n",void();
    }
    if(cur!="ava") cout<<"No\n";
    else cout<<"Yes\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}