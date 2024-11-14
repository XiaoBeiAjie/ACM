#include <bits/stdc++.h>
using namespace std;
struct Kmp
{
    string s,p;
    vector<int> nxt;
    Kmp(string ss,string pp)
    {
        s=ss;p=pp;
        nxt.resize(s.size());
    }
    void kmp()
    {
        int i,j,n=s.size(),m=p.size();
        for(nxt[0]=j=-1,i=1;i<n;nxt[i++]=j)
        {
            while(~j&&s[j+1]!=s[i]) j=nxt[j];
            if(s[j+1]==s[i]) ++j;
        }
        for(i=0;i<n;++i) cout<<nxt[i]+1<<' ';//前i个字符最长公共前后缀
        cout<<'\n';
        for(j=-1,i=0;i<m;++i)
        {
            while(~j&&s[j+1]!=p[i]) j=nxt[j];
            if(s[j+1]==p[i]) ++j;
            if(j==n-1) cout<<i+1<<' ',j=nxt[j];//匹配成功位置(末尾)
        }
    }
};
int main()
{
    string s,p;cin>>s>>p;
    Kmp km(s,p);//p中找s
    km.kmp();
}