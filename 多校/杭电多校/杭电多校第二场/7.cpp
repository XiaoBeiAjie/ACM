#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    string s;cin>>s;
    string cur="";
    int j;
    for(int i=0;i<(int)s.size();++i)
    {
        if(s[i]==':') {j=i+3;break;}
        cur+=s[i];
    }
    cout<<cur<<'\n';cur="";
    for(int i=j;i<(int)s.size();++i)
    {
        if(s[i]=='/') {j=i+1;break;}
        cur+=s[i];
    }
    cout<<cur<<'\n';cur="";
    while(j<(int)s.size())
    {
        cur="";
        for(int i=j;i<(int)s.size();++i)
        {
            if(s[i]=='/'){j=i+1;break;}
            cur+=s[i];
        }
        int cnt=0,mx=-1;
        for(int i=0;i<(int)cur.size();++i) 
        {
            cnt+=cur[i]=='=';
            if(cur[i]=='-') mx=i;
        }
        if(cnt==0) continue;
        string ans="";
        for(int i=0;i<(int)cur.size();++i)
        {
            if(cnt<=1)
            {
                if(i>mx) ans+=cur[i];
            }
            if(cur[i]=='=') --cnt;
        }
        if(!ans.empty()) cout<<ans<<'\n';
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