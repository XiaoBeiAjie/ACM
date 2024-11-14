#include <bits/stdc++.h>
using namespace std;
bool check(int mid)
{
    return true;
    return false;
}
int main()
{
    int l=1,r=2e9,ans;
    while(l<r)//最小解
    {
        int mid=(l+r)>>1;
        if(check(mid)) r=mid,ans=mid;
        else l=mid+1;
    }
    cout<<ans<<'\n';
}