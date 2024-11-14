#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    vector<string> s(3);
    vector<vector<string>> g(4,vector<string>(2));
    set<string> hav;
    for(int i=0;i<3;++i) cin>>s[i],hav.insert(s[i]);
    for(int i=0;i<4;++i) for(int j=0;j<2;++j) cin>>g[i][j],hav.insert(g[i][j]);
    vector<string> card;
    auto dinv=[&](int x)->string
    {
        string res="";
        if(x>=2&&x<=9) res+=(char)(x+'0');
        else if(x==10) res+='T';
        else if(x==11) res+='J';
        else if(x==12) res+='Q';
        else if(x==13) res+='K';
        else res+='A';
        return res;
    };
    for(int i=2;i<=14;++i)
    {
        for(int j=1;j<=4;++j)
        {
            string cc=dinv(i);
            if(j==1) cc+='H';
            else if(j==2) cc+='D';
            else if(j==3) cc+='C';
            else cc+='S';
            if(!hav.count(cc)) card.push_back(cc);
        }
    }
    int st;cin>>st;
    //for(auto &it:card) cout<<it<<'\n';
    //cout<<card.size()<<'\n';
    //return;
    string ans="None";
    int cnt=0,res=0;
    auto inv=[&](char ch)->int
    {
        if(ch>='2'&&ch<='9') return ch-'0';
        else if(ch=='T') return 10;
        else if(ch=='J') return 11;
        else if(ch=='Q') return 12;
        else if(ch=='K') return 13;
        else return 14;
    };
    auto get=[&](vector<string> pq)->int
    {
        bool tag=true;
        vector<int> t;
        t.push_back(inv(pq[0][0]));
        for(int i=1;i<5;++i) 
        {
            if(pq[i][1]!=pq[i-1][1]) tag=false;
            t.push_back(inv(pq[i][0]));
        }
        sort(t.begin(),t.end());
        if(tag)//tong hua
        {
            if(t[0]==10) return 1e9;//huang jia tong hua shun
            else 
            {
                if(t[4]==14) t[4]=1;
                sort(t.begin(),t.end());
                if(t[4]-t[0]==4) return 9e8+t[4];//tong hua shun
                else//tong hua
                {
                    if(t[0]==1) t[0]=14;
                    sort(t.begin(),t.end());
                    return 6e8+t[4]*50625+t[3]*3375+t[2]*225+t[1]*15+t[0];
                }
            }
        } 
        else
        {
            if(t[0]==t[3])//si tiao
            {
                return 8e8+t[0]*50+t[4];
            }
            else if(t[1]==t[4])//si tiao
            {
                return 8e8+t[1]*50+t[0];
            }
            else if(t[0]==t[2]&&t[3]==t[4])//hu lu
            {
                return 7e8+t[0]*50+t[3];
            }
            else if(t[0]==t[1]&&t[2]==t[4])//hu lu
            {
                return 7e8+t[2]*50+t[0];
            }
            else
            {
                if(t[0]==10&&t[1]==11&&t[2]==12&&t[3]==13&&t[4]==14) return 5e8+14;//shun zi
                if(t[4]==14)
                {
                    for(int i=4;~i;--i) if(t[i]==14) t[i]=1;
                    sort(t.begin(),t.end());
                    bool tag=true;
                    for(int i=1;i<5&&tag;++i) if(t[i]!=t[i-1]) tag=false;
                    if(tag) return 5e8+t[4];//shun zi
                    for(int i=0;i<5;++i) if(t[i]==1) t[i]=14;
                    sort(t.begin(),t.end());
                }
                if(t[0]==t[2]) return 4e8+t[0]*225+t[4]*15+t[3];//san tiao
                else if(t[1]==t[3]) return 4e8+t[1]*225+t[4]*15+t[0];//san tiao
                else if(t[2]==t[4]) return 4e8+t[2]*225+t[1]*15+t[0];//san tiao
                else if(t[0]==t[1]&&t[2]==t[3]) return 3e8+t[2]*225+t[0]*15+t[4];//liang dui
                else if(t[0]==t[1]&&t[3]==t[4]) return 3e8+t[4]*225+t[0]*15+t[2];//liang dui
                else if(t[1]==t[2]&&t[3]==t[4]) return 3e8+t[4]*225+t[1]*15+t[0];//liang dui
                else if(t[0]==t[1]) return 2e8+t[0]*3375+t[4]*225+t[3]*15+t[2];//dui zi
                else if(t[1]==t[2]) return 2e8+t[1]*3375+t[4]*225+t[3]*15+t[0];//dui zi
                else if(t[2]==t[3]) return 2e8+t[2]*3375+t[4]*225+t[1]*15+t[0];//dui zi
                else if(t[3]==t[4]) return 2e8+t[3]*3375+t[2]*225+t[1]*15+t[0];//dui zi
                else t[4]*50625+t[3]*3375+t[2]*225+t[1]*15+t[0];// else
            }
        }
    };
    auto check=[&](string a1,string a2)->void
    {
        vector<string> p=s;p.push_back(a1);p.push_back(a2);
        vector<int> val(4,0);
        for(int i=0;i<4;++i)
        {
            for(int j1=0;j1<5;++j1)
            {
                for(int j2=j1+1;j2<5;++j2)
                {
                    for(int j3=j2+1;j3<5;++j3)
                    {
                        vector<string> cur=g[i];
                        cur.push_back(p[j1]);cur.push_back(p[j2]);cur.push_back(p[j3]);
                        val[i]=max(get(cur),val[i]);
                    }
                }
            }
        }
        int mx=*max_element(val.begin(),val.end());
        if(mx==val[st]) ++cnt;
    };  
    for(int i1=0;i1<(int)card.size();++i1)
    {
        for(int i2=i1+1;i2<(int)card.size();++i2)
        {
            //check(card[i1],card[i2]);
        }
    }
    res=cnt;
    for(int i=0;i<3;++i)
    {
        for(int j=0;j<4;++j)
        {
            for(int k=0;k<2;++k)
            {
                cnt=0;swap(s[i],g[j][k]);
                for(int i1=0;i1<(int)card.size();++i1)
                {
                    for(int i2=i1+1;i2<(int)card.size();++i2)
                    {
                        check(card[i1],card[i2]);
                    }
                }
                string pp="";
                if(s[i]<g[j][k])
                {
                    pp+=s[i];pp+=" ";pp+=g[j][k];
                }
                else
                {
                    pp+=g[j][k];pp+=" ";pp+=s[i];
                }
                if(cnt==res) 
                {
                    if(ans!="None"&&pp<ans) ans=pp;
                }
                else if(cnt>res) res=cnt,ans=pp;
                swap(s[i],g[j][k]);
            }
        }
    }
    for(int i=0;i<4;++i)
    {
        for(int ii=i+1;ii<4;++ii)
        {
            for(int j=0;j<2;++j)
            {
                for(int jj=0;jj<2;++jj)
                {
                    string t1=g[i][j],t2=g[ii][jj];
                    g[i][j]=t2;g[ii][jj]=t1;
                    cnt=0;
                    for(int i1=0;i1<(int)card.size();++i1)
                    {
                        for(int i2=i1+1;i2<(int)card.size();++i2)
                        {
                            //cout<<card[i1]<<' '<<card[i2]<<'\n';
                            check(card[i1],card[i2]);
                        }
                    }
                    string pp="";
                    if(t1<t2)
                    {
                        pp+=t1;pp+=" ";pp+=t2;
                    }
                    else
                    {
                        pp+=t2;pp+=" ";pp+=t1;
                    }
                    if(cnt==res) 
                    {
                        if(ans!="None"&&pp<ans) ans=pp;
                    }
                    else if(cnt>res) res=cnt,ans=pp;
                    g[i][j]=t1;g[ii][jj]=t2;
                    
                }
            }
        }
    }
    cout<<ans<<'\n';
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}