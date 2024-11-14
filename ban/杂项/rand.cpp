#include <bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
int main()
{
    int n;cin>>n;
    mt19937_64 rnd(0);
    uniform_int_distribution<ull> make(0,(ull)1<<63);
    vector<ull> hsh(n);
    for(int i=0;i<n;++i) hsh[i]=make(rnd);
    for(int i=0;i<n;++i) cout<<hsh[i]<<'\n';
}