#include <algorithm>
#include <iostream>
using namespace std;
const int MAXV = 101;
const int MAXE = 10001;
// 边集定义
struct edge {
    int u, v;  // 边的两个顶点编号
    int cost;  // 边权
} E[MAXE];     // 最多有MAXE条边

bool cmp(edge a, edge b) {
    return a.cost < b.cost;
}
int father[MAXV];        // 并查集数组
int findFather(int x) {  // 并查集查询函数
    int a = x;
    while (x != father[x]) {
        x = father[x];
    }
    while (a != father[a]) {  // 路径压缩
        int t = a;
        a = father[a];
        father[t] = x;
    }
    return x;
}
int main() {
    int n, m;
    return 0;
}