#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
#define pb push_back
#define mp make_pair
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
__gnu_pbds::tree<pair<int,int>, __gnu_pbds::null_type,less<pair<int,int>>,
                __gnu_pbds::rb_tree_tag,
                __gnu_pbds::tree_order_statistics_node_update>
    trr;
/*
insert(x)：向树中插入一个元素 x，返回 std::pair<point_iterator, bool>。
erase(x)：从树中删除一个元素/迭代器 x，返回一个 bool 表明是否删除成功。
order_of_key(x)：返回 x 以 Cmp_Fn 比较的排名。
find_by_order(x)：返回 Cmp_Fn 比较的排名所对应元素的迭代器。
lower_bound(x)：以 Cmp_Fn 比较做 lower_bound，返回迭代器。
upper_bound(x)：以 Cmp_Fn 比较做 upper_bound，返回迭代器。
join(x)：将 x 树并入当前树，前提是两棵树的类型一样，不相交，如果相交抛出异。x 树被删除。
split(x,b)：以 Cmp_Fn 比较，小于等于 x 的属于当前树，其余的属于 b 树。
empty()：返回是否为空。
size()：返回大小。
*/
int main() 
{
    int cnt=0;
    trr.insert(mp(1,cnt++));
    trr.insert(mp(5,cnt++));
    trr.insert(mp(4,cnt++));
    trr.insert(mp(3,cnt++));
    trr.insert(mp(2,cnt++));
    //树上元素 {{1,0},{2,4},{3,3},{4,2},{5,1}}
    auto it=trr.lower_bound(mp(2,0));
    trr.erase(it);
    //树上元素 {{1,0},{3,3},{4,2},{5,1}}
    auto it2=trr.find_by_order(1);
    cout<<(*it2).first<<endl;
    //输出排名 0 1 2 3 中的排名 1 的元素的 first:1
    int pos=trr.order_of_key(*it2);
    cout<<pos<<endl;
    // 输出排名
    decltype(trr) newtr;
    trr.split(*it2, newtr);
    for(auto i=newtr.begin();i!=newtr.end();++i) 
    {
        cout<<(*i).first<<' ';
    }
    cout<<endl;
    //{4,2},{5,1} 被放入新树
    trr.join(newtr);
    for(auto i=trr.begin();i!=trr.end();++i) cout<<(*i).first<<' ';
    cout<<endl;
    cout<<newtr.size()<<endl;
    // 将 newtr 树并入 trr 树，newtr 树被删除。
}