#include <bits/stdc++.h>
using namespace std;
using ld=long double;
struct square
{
    vector<ld> x,y;
    square(int sz)
    {
        x.resize(sz+1,0);
        y.resize(sz+1,0);
    }
    ld getss(int sz)
    {
        ld res=0;
        for(int i=0;i<sz-1;++i) res+=x[i]*y[i+1]-x[i+1]*y[i];
        res+=x[sz-1]*y[0]-x[0]*y[sz-1];
        return fabs(res*0.5);
    }
};
int main()
{
    int n;cin>>n;square sq(n);
    for(int i=0;i<n;++i) cin>>sq.x[i]>>sq.y[i];
    cout<<fixed<<setprecision(2)<<sq.getss(n);
}