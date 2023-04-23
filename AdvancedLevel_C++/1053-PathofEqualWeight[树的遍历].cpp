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
    }
    return 0;
}