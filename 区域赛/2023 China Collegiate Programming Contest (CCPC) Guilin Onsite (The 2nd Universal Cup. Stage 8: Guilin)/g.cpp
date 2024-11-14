#include <bits/stdc++.h>
using namespace std;




int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    auto solve=[]()
    {
        string ans="",s;cin>>s;int cnt=0;
        for(int i=0;i<(int)s.size();++i)
        {
            if(s[i]=='(') ans+='(',++cnt;
            else
            {
                if(!cnt) ans+=')';
                else
                {
                    --cnt;ans+=')';
                }
            }
        }
        if(cnt)ans="impossible";
        cout<<ans<<'\n';

    };
    int t;cin>>t;
    while(t--)
    solve();
}