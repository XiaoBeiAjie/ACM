#include <bits/stdc++.h>
using namespace std;
struct Point 
{
    double x,y,ang;
    Point operator-(const Point& p)const {return {x-p.x,y-p.y,0};}
    double dis(Point p2) 
    {
        return sqrt((x-p2.x)*(x-p2.x)+(y-p2.y)*(y-p2.y));
    }
    double cross(Point p2) 
    { 
        return x*p2.y-y*p2.x; 
    }
};
struct baozi
{
    int n;
    vector<Point> v;
    vector<int> ans;
    baozi(int n):n(n),v(n){}
    void getans()
    {
        for(int i=1;i<n;++i)
        {
            if(v[i].y<v[0].y||(fabs(v[i].y-v[0].y)<1e-12&&v[i].x<v[0].x)) 
            {
                swap(v[0],v[i]);
            }
        }
        Point p=v[0];
        for(int i=1;i<n;++i) v[i].ang=atan2(v[i].y-p.y,v[i].x-p.x);
        sort(v.begin()+1,v.end(),[&](Point a,Point b)//以p为源点的极角排序
        {return fabs(a.ang-b.ang)<1e-12?p.dis(a)<p.dis(b):a.ang<b.ang;});
        ans.push_back(0);
        for(int i=1;i<n;++i)
        {
            while(1<(int)ans.size())
            {
                p=v[ans[(int)ans.size()-1]]-v[ans[(int)ans.size()-2]];
                if(p.cross(v[i]-v[ans[(int)ans.size()-1]])<0) ans.pop_back();
                else break;
            }
            ans.push_back(i);
        }
    }
};
int main() 
{
    int n;cin>>n;baozi bao(n);
    for(int i=0;i<n;++i) cin>>bao.v[i].x>>bao.v[i].y;
    bao.getans();
    for(auto &it:bao.ans)//凸包点集
        cout<<bao.v[it].x<<' '<<bao.v[it].y<<'\n';
}