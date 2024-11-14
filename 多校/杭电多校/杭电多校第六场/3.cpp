#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n;cin>>n;
    vector<int> ans;
    string s;cin>>s;
    for(int ii=0;ii<1;++ii)
    {
        int x=0,y=0,ss=ii;//0,1,2,3
        set<array<int,2>> vis;
        bool tag=true;
        for(auto &it:s)
        {
            if(vis.count({x,y})) {tag=0;break;}
            vis.insert({x,y});
            //cout<<x<<' '<<y<<'\n';
            if(it=='S')
            {
                if(ss==0) ++y;
                else if(ss==1) ++x;
                else if(ss==2) --y;
                else --x;
                
            }
            else if(it=='L')
            {
                --ss;if(ss==-1) ss=3;
                if(ss==0) ++y;
                else if(ss==1) ++x;
                else if(ss==2) --y;
                else --x;
            }
            else
            {
                ++ss;if(ss==4) ss=0;
                if(ss==0) ++y;
                else if(ss==1) ++x;
                else if(ss==2) --y;
                else --x;
            }
        }
        //cout<<x<<' '<<y<<' '<<ss<<'\n';
        //if(ss==0) ++y;
        //else if(ss==1) ++x;
        //else if(ss==2) --y;
        //else --x;
        if(!tag) ans.push_back(-1);
        else if(x==0&&y==0&&ss==ii) ans.push_back(1);
        else ans.push_back(0);
        //cout<<"***\n";
    }
    sort(ans.begin(),ans.end());
    cout<<*ans.rbegin()<<'\n';
} 

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}