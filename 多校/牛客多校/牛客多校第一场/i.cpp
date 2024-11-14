#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
typedef long long ll;

void solve() {
    int n,m;cin>>n>>m;
    vector<string> s(n);
    for(int i=0;i<n;++i) cin>>s[i];
    vector<vector<vector<int>>> f(n,vector<vector<int>> (m,vector<int>(4,-1)));
    int q;cin>>q;
    auto inv=[&](int pre,char ch)->int
    {
        if(pre==0)
        {
            if(ch=='-') return 1;
            else if(ch=='|') return 0;
            else if(ch=='/') return 3;
            else return 2;
        }
        else if(pre==1)
        {
            if(ch=='-') return 0;
            else if(ch=='|') return 1;
            else if(ch=='/') return 2;
            else return 3;
        }
        else if(pre==2)
        {
            if(ch=='-') return 2;
            else if(ch=='|') return 3;
            else if(ch=='/') return 1;
            else return 0;
        }
        else
        {
            if(ch=='-') return 3;
            else if(ch=='|') return 2;
            else if(ch=='/') return 0;
            else return 1;
        }
    };
    vector<array<int,3>> road;
    set<array<int,2>> vis;
    stack<int> nmb;
    int xx,yy,zz,cnt,pos;bool gh=0;
    auto dfs=[&](auto self,int x,int y,int fg)->void
    {
        if(x==xx&&y==yy&&fg==zz&&gh) return;
        gh=1;
        if(f[x][y][fg]>-1) 
        {
            cnt=f[x][y][fg];
            return;
        }
        if(fg==0)
        {
            if(x-1<0) 
            {
                f[x][y][fg]=0;
                if(fg!=inv(fg,s[x][y])) cnt=1;
                else cnt=0;
                return;
            }
            else 
            {
                ++pos;
                if(fg!=inv(fg,s[x-1][y])&&!vis.count({x-1,y})) vis.insert({x-1,y}),nmb.push(pos);
                road.push_back({x,y,fg});
                self(self,x-1,y,inv(fg,s[x-1][y]));
            }
        }
        else if(fg==1)
        {
            if(x+1>=n) 
            {
                f[x][y][fg]=0;
                if(fg!=inv(fg,s[x][y])) cnt=1;
                else cnt=0;
                return;
            }
            else 
            {
                ++pos;
                if(fg!=inv(fg,s[x+1][y])&&!vis.count({x+1,y})) vis.insert({x+1,y}),nmb.push(pos);
                road.push_back({x,y,fg});
                self(self,x+1,y,inv(fg,s[x+1][y]));
            }
        }
        else if(fg==2)
        {
            if(y-1<0) 
            {
                f[x][y][fg]=0;
                if(fg!=inv(fg,s[x][y])) cnt=1;
                else cnt=0;
                return;
            }
            else 
            {
                ++pos;
                if(fg!=inv(fg,s[x][y-1])&&!vis.count({x,y-1})) vis.insert({x,y-1}),nmb.push(pos);
                road.push_back({x,y,fg});
                self(self,x,y-1,inv(fg,s[x][y-1]));
            }
        }
        else
        {
            if(y+1>=m) 
            {   
                f[x][y][fg]=0;
                if(fg!=inv(fg,s[x][y])) cnt=1;
                else cnt=0;
                return;
            }
            else
            {
                ++pos;
                if(fg!=inv(fg,s[x][y+1])&&!vis.count({x,y+1})) vis.insert({x,y+1}),nmb.push(pos);
                road.push_back({x,y,fg});
                self(self,x,y+1,inv(fg,s[x][y+1]));
            }
        }

    };
    //0,shang;1,xia;2,zuo;3,you
    string sr;
    for(int i=0;i<q;++i)
    {
        cin>>xx>>yy>>sr;--xx;--yy;gh=0;pos=0;
        while(!nmb.empty()) nmb.pop();
        vis.clear();road.clear();cnt=-1;
        if(sr[0]=='a') 
        {
            zz=0;
            if(f[xx][yy][0]==-1) 
            {
                ++pos;
                road.push_back({xx,yy,0});
                dfs(dfs,xx,yy,0);
            }
            reverse(road.begin(),road.end());
            if(cnt==-1)
            {
                cnt=vis.size();
                for(auto [x11,y11,z11]:road)
                {
                    f[x11][y11][z11]=cnt;
                }
            }
            else
            {
                for(auto [x11,y11,z11]:road)
                {
                    f[x11][y11][z11]=cnt;
                    if(!nmb.empty()&&pos==nmb.top())
                    {
                        ++cnt;nmb.pop();
                    }
                    --pos;
                }
            }
            cout<<f[xx][yy][0]<<'\n';
        }
        else if(sr[0]=='b') 
        {
            zz=1;
            if(f[xx][yy][1]==-1) 
            {
                ++pos;
                road.push_back({xx,yy,1});
                dfs(dfs,xx,yy,1);
            }
            reverse(road.begin(),road.end());
            if(cnt==-1)
            {
                cnt=vis.size();
                for(auto [x11,y11,z11]:road)
                {
                    f[x11][y11][z11]=cnt;
                }
            }
            else
            {
                for(auto [x11,y11,z11]:road)
                {
                    f[x11][y11][z11]=cnt;
                    if(!nmb.empty()&&pos==nmb.top())
                    {
                        ++cnt;nmb.pop();
                    }
                    --pos;
                }
            }
            cout<<f[xx][yy][1]<<'\n';
        }
        else if(sr[0]=='l') 
        {
            zz=2;
            if(f[xx][yy][2]==-1) 
            {
                ++pos;
                road.push_back({xx,yy,2});
                dfs(dfs,xx,yy,2);
                //cout<<"c\n";
            }
            reverse(road.begin(),road.end());
            if(cnt==-1)
            {
                cnt=vis.size();
                for(auto [x11,y11,z11]:road)
                {
                    f[x11][y11][z11]=cnt;
                }
            }
            else
            {
                for(auto [x11,y11,z11]:road)
                {
                    f[x11][y11][z11]=cnt;
                    if(!nmb.empty()&&pos==nmb.top())
                    {
                        ++cnt;nmb.pop();
                    }
                    --pos;
                }
            }
            cout<<f[xx][yy][2]<<'\n';
        }
        else 
        {
            zz=3;
            if(f[xx][yy][3]==-1) 
            {
                ++pos;
                road.push_back({xx,yy,3});
                dfs(dfs,xx,yy,3);
            }
            reverse(road.begin(),road.end());
            if(cnt==-1)
            {
                cnt=vis.size();
                for(auto [x11,y11,z11]:road)
                {
                    f[x11][y11][z11]=cnt;
                }
            }
            else
            {
                for(auto [x11,y11,z11]:road)
                {
                    cout<<x11+1<<' '<<y11+1<<' '<<z11<<' ';
                    f[x11][y11][z11]=cnt;
                    cout<<cnt<<'\n';
                    if(!nmb.empty()&&pos==nmb.top())
                    {
                        ++cnt;nmb.pop();
                    }
                    --pos;
                }
            }
            cout<<f[xx][yy][3]<<'\n';
        }
        //cout<<"yes\n";
    }
}

int main(void) {
    //ios::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    int T=1; //cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}