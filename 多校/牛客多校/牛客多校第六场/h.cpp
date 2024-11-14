#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    string s;cin>>s;
    int pos1=-1,pos2=-1,pre=-1;//5,4
    for(int i=0;i<(int)s.size();++i)
    {
        if(s[i]=='3')
        {
            if(pos1<=i-10&&pos2<=i-10)
            {
                return cout<<"invalid\n",void();
            }
        }
        else if(s[i]=='4')
        {
            if(pos1<=i-90)
            {
                return cout<<"invalid\n",void();
            }
            pos2=i;
        }
        else if(s[i]=='5')
        {
            if(pre==-1) pre=0;
            else if(pre==0) return cout<<"invalid\n",void();
            else pos1=i,pre=0;
        }
        else
        {
            if(pre==-1) pre=1;
            else if(pre==1) return cout<<"invalid\n",void();
            else pos1=i,pre=1;
        }

    }
    cout<<"valid\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}