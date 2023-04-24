/*
Q:给出一棵带权树，找出所有权值之和为S的路径, 从大到小输出。
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct NODE {
    int w;
    vector<int> child;
};
vector<NODE> v;
vector<int> path;
int target;
void dfs(int index, int nodeNum, int sum) {
    if (sum > target) {
        return;
    }
    if (sum == target) {
        if (v[index].child.size() != 0) {  // 没有到达叶结点
            return;
        }
        for (int i = 0; i < nodeNum; i++) {  // 有多个叶结点
            printf("%d%c", v[path[i]].w, i != nodeNum - 1 ? ' ' : '\n');
            // 根结点是path[0]
        }
        return;
    }
    for (int i = 0; i < v[index].child.size(); i++) {
        int node = v[index].child[i];
        path[nodeNum] = node;  // 这里path从1开始
        dfs(node, nodeNum + 1, sum + v[node].w);
    }
}
int cmp(int a, int b) {
    return v[a].w > v[b].w;
}
int main() {
    int n, m, node, k;
    scanf("%d %d %d", &n, &m, &target);
    v.resize(n);
    path.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i].w);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &node, &k);
        v[node].child.resize(k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &v[node].child[j]);
        }
        sort(v[node].child.begin(), v[node].child.end(), cmp);
    }
    dfs(0, 1, v[0].w);
    return 0;
}