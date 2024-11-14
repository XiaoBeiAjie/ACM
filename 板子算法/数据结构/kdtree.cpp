#include <cstdio>
#include <algorithm>
#include <vector>
#define NMAX 500005
#define NUL -1
using namespace std;
int n;
vector<int> result;
struct Node {
    int IOid, x, y, left, right;// id、二叉树位置、坐标、子节点
}nodes[NMAX];
bool lessByX(const Node &node1, const Node &node2){return node1.x < node2.x;}
bool lessByY(const Node &node1, const Node &node2){return node1.y < node2.y;}
 
int buildTree(int left, int right, int depth){
    if (left>=right)
        return NUL;
    int mid = (right+left)>>1;
    if (depth % 2)
        sort(nodes+left, nodes+right, lessByY);
    else sort(nodes+left, nodes+right, lessByX);
    nodes[mid].left = buildTree(left, mid, depth +1 );
    nodes[mid].right = buildTree(mid+1, right, depth + 1);
    return mid;
}
void findNodes (int nowLoc, int xMin, int xMax, int yMin, int yMax, int depth) {
    int nowX = nodes[nowLoc].x;
    int nowY = nodes[nowLoc].y;
    if(nowX >= xMin && nowX <= xMax && nowY <= yMax && nowY >= yMin){
        result.push_back(nodes[nowLoc].IOid);
    }
    if(depth % 2) {
        if(nodes[nowLoc].left!=NUL && nowY >= yMin)
            findNodes(nodes[nowLoc].left, xMin, xMax, yMin, yMax, depth +1);
        if(nodes[nowLoc].right!=NUL && nowY <= yMax)
            findNodes(nodes[nowLoc].right, xMin, xMax, yMin, yMax, depth +1);
    } else {
        if(nodes[nowLoc].left!=NUL && nowX >= xMin)
            findNodes(nodes[nowLoc].left, xMin, xMax, yMin, yMax, depth +1);
        if(nodes[nowLoc].right!=NUL && nowX <= xMax)
            findNodes(nodes[nowLoc].right, xMin, xMax, yMin, yMax, depth +1);
    }
}
 
int main(){
    int xMin, xMax, yMin, yMax;
    short q;
    scanf("%d", &n);
    for (int i = 0;i<n;i++){
        scanf("%d%d", &nodes[i].x, &nodes[i].y);
        nodes[i].IOid = i;
    }
    int root = buildTree(0, n, 0);
    scanf("%d", &q);
    while (q--) {
        scanf("%d%d%d%d", &xMin, &xMax, &yMin, &yMax);
        findNodes(root, xMin, xMax, yMin, yMax, 0);
        sort(result.begin(), result.end());
        int length = result.size();
        for(int i=0;i<length;i++){
            printf("%d\n", result[i]);
        }
        result.clear();
        printf("\n");
    }
    return 0;
}

