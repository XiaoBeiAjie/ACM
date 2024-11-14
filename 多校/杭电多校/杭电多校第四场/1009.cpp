#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n,m;cin>>n>>m;
    vector<string> s(n);
    vector<int> pos(n,-1);
    vector<vector<array<int,2>>> f(26);
    string p;cin>>p;
    for(int i=0;i<n;++i)
    {
        cin>>s[i];
        f[s[i][0]-'a'].push_back({i,1});
    }
    for(int i=0,t;i<m;++i)
    {
        if(p[i]>='0'&&p[i]<='9') continue;
        t=p[i]-'a';
        vector<vector<array<int,2>>> g(26);
        for(auto [x,y]:f[t])
        {
            if(y==(int)s[x].size()) pos[x]=i;
            else g[s[x][y]-'a'].push_back({x,y+1});
        }
        f[t].clear();
        for(int j=0;j<26;++j) for(auto &it:g[j]) 
            f[j].push_back(it);
    }
    vector<int> getans(m,0);
    for(int i=0;i<n;++i) 
    {
        //cout<<pos[i]<<' '<<i<<'\n';
        if(pos[i]==-1) continue;
        ++getans[pos[i]];
    }
    //for(int i=0;i<n;++i) cout<<pos[i]<<'\n';
    //0230 0231 0431 0631 0931 1131
    set<string> s1;
    set<string> s2;//_ 0
    set<string> s3;//_ 1-2
    set<string> s4;//_ 3-9
    set<string> s5;//- - 0
    set<string> s6;//- - 1-2
    set<string> s7;//- - 3
    set<string> s8;//- - - 0
    set<string> s9;//- - - 1
    set<string> s10;//- - - 2-9
    ll mx=0;
    for(int i=m-1;~i;--i)
    {
        mx+=(ll)s1.size()*(ll)getans[i];
        //if(getans[i]) cout<<mx<<'\n';
        if(p[i]>='a'&&p[i]<='z') continue;
        if(p[i]=='0')
        {
            //
            for(auto &it:s3)
            {
                string sp="";sp+=p[i];sp+=it;
                if(sp=="0230"||sp=="0231") continue;
                s1.insert(sp);
            }
            for(auto &it:s4)
            {
                string sp="";sp+=p[i];sp+=it;
                if(sp=="0631"||sp=="0931"||sp=="0431") continue;
                s1.insert(sp);
            }
            //
            for(auto &it:s5)
            {
                string sp="";sp+=p[i];sp+=it;
                s2.insert(sp);
            }
            for(auto &it:s6)
            {
                string sp="";sp+=p[i];sp+=it;
                s2.insert(sp);
            }
            for(auto &it:s7)
            {
                string sp="";sp+=p[i];sp+=it;
                s2.insert(sp);
            }
            //
            for(auto &it:s9)
            {
                string sp="";sp+=p[i];sp+=it;
                s5.insert(sp);
            }
            for(auto &it:s10)
            {
                string sp="";sp+=p[i];sp+=it;
                s5.insert(sp);
            }
            //
            string sp="";sp+=p[i];
            s8.insert(sp);
        }
        //----
        else if(p[i]=='1')
        {
            //
            for(auto &it:s2)
            {
                string sp="";sp+=p[i];sp+=it;
                s1.insert(sp);
            }
            for(auto &it:s3)
            {
                string sp="";sp+=p[i];sp+=it;
                if(sp=="1131") continue;
                s1.insert(sp);
            }
            //
            for(auto &it:s5)
            {
                string sp="";sp+=p[i];sp+=it;
                s3.insert(sp);
            }
            for(auto &it:s6)
            {
                string sp="";sp+=p[i];sp+=it;
                s3.insert(sp);
            }
            for(auto &it:s7)
            {
                string sp="";sp+=p[i];sp+=it;
                s3.insert(sp);
            }
            //
            for(auto &it:s8)
            {
                string sp="";sp+=p[i];sp+=it;
                s6.insert(sp);
            }
            for(auto &it:s9)
            {
                string sp="";sp+=p[i];sp+=it;
                s6.insert(sp);
            }
            for(auto &it:s10)
            {
                string sp="";sp+=p[i];sp+=it;
                s6.insert(sp);
            }
            //
            string sp="";sp+=p[i];
            s9.insert(sp);
        }
        //-----
        else if(p[i]=='2')
        {
            //
            for(auto &it:s5)
            {
                string sp="";sp+=p[i];sp+=it;
                s3.insert(sp);
            }
            for(auto &it:s6)
            {
                string sp="";sp+=p[i];sp+=it;
                s3.insert(sp);
            }
            for(auto &it:s7)
            {
                string sp="";sp+=p[i];sp+=it;
                s3.insert(sp);
            }
            //
            for(auto &it:s8)
            {
                string sp="";sp+=p[i];sp+=it;
                s6.insert(sp);
            }
            for(auto &it:s9)
            {
                string sp="";sp+=p[i];sp+=it;
                s6.insert(sp);
            }
            for(auto &it:s10)
            {
                string sp="";sp+=p[i];sp+=it;
                s6.insert(sp);
            }
            //
            string sp="";sp+=p[i];
            s10.insert(sp);
        }
        else if(p[i]=='3')
        {
            //
            for(auto &it:s5)
            {
                string sp="";sp+=p[i];sp+=it;
                s4.insert(sp);
            }
            for(auto &it:s6)
            {
                string sp="";sp+=p[i];sp+=it;
                s4.insert(sp);
            }
            for(auto &it:s7)
            {
                string sp="";sp+=p[i];sp+=it;
                s4.insert(sp);
            }
            //
            for(auto &it:s8)
            {
                string sp="";sp+=p[i];sp+=it;
                s7.insert(sp);
            }
            for(auto &it:s9)
            {
                string sp="";sp+=p[i];sp+=it;
                s7.insert(sp);
            }
            //
            string sp="";sp+=p[i];
            s10.insert(sp);
        }
        else
        {
            //
            for(auto &it:s5)
            {
                string sp="";sp+=p[i];sp+=it;
                s4.insert(sp);
            }
            for(auto &it:s6)
            {
                string sp="";sp+=p[i];sp+=it;
                s4.insert(sp);
            }
            for(auto &it:s7)
            {
                string sp="";sp+=p[i];sp+=it;
                s4.insert(sp);
            }
            //
            string sp="";sp+=p[i];
            s10.insert(sp);
        }
    }
    //for(auto &it:s1) cout<<it<<'\n';
    cout<<mx<<'\n';
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    //system("pause");
    return 0;
}
/*
1
4 16
abcd10313110ac10
ac
cc
abcdac
d
*/