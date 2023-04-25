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

vector<NODE> v;            // 存储树的节点信息
vector<int> path;          // 存储当前搜索路径上的节点权值
vector<vector<int> > ans;  // 存储所有满足条件的路径

int target;  // 目标路径权值之和

// DFS搜索
void dfs(int index, int sum) {
    if (sum > target) {  // 如果当前路径权值之和已经大于目标权值，则直接返回
        return;
    }
    if (sum == target &&
        v[index]
            .child
            .empty()) {  // 如果当前路径权值之和等于目标权值，并且当前节点是叶子节点，则说明找到一条满足条件的路径
        ans.push_back(path);  // 将该路径添加到结果集中
        return;
    }
    for (int i = 0; i < v[index].child.size();
         i++) {  // 对当前节点的每个子节点进行DFS搜索
        int node = v[index].child[i];
        path.push_back(v[node].w);   // 将子节点的权值加入到路径中
        dfs(node, sum + v[node].w);  // 递归搜索子节点
        path.pop_back();  // 回溯，将子节点的权值从路径中删除
    }
}

int main() {
    int n, m, node, k;
    cin >> n >> m >> target;  // 输入节点数、边数和目标路径权值之和
    v.resize(n);              // 调整树的大小为n
    path.reserve(n);  // 为path预分配n的大小，避免多次扩容带来的时间浪费
    for (int i = 0; i < n; i++) {
        cin >> v[i].w;  // 输入每个节点的权值
    }
    for (int i = 0; i < m; i++) {
        cin >> node >> k;  // 输入当前节点编号和它的子节点数量
        v[node].child.resize(k);  // 调整当前节点的子节点数为k
        for (int j = 0; j < k; j++) {
            cin >> v[node].child[j];  // 输入当前节点的子节点编号
        }
    }
    path.push_back(v[0].w);  // 将根节点的权值加入到路径中
    dfs(0, v[0].w);          // 从根节点开始DFS搜索
    // greater<vector<int>>() 会将两个 vector 进行比较，返回 true 表示第一个
    // vector 的元素之和大于第二个 vector 的元素之和，否则返回 false。
    sort(ans.begin(), ans.end(),
         greater<vector<int> >());  // 将结果集按照字典序从大到小的顺序排序
    // 从大到小的顺序，先比较第一个元素，如果相等则比较第二个元素，以此类推。
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i][0];  // 输出该路径的第一个节点的权值
        for (int j = 1; j < ans[i].size(); j++) {
            cout << " " << ans[i][j];  // 输出该路径的其他节点的权值
        }
        cout << endl;
    }
    return 0;
}

/*
Q:给出一棵带权树，找出所有权值之和为S的路径, 从大到小输出。
A：以下解法存在错误
*/
// #include <algorithm>
// #include <iostream>
// #include <vector>
// using namespace std;
// struct NODE {
//     int w;
//     vector<int> child;
// };
// vector<NODE> v;
// vector<int> path;
// int target;
// void dfs0(int index, int nodeNum, int sum) {
//     if (sum > target) {
//         return;
//     }
//     if (sum == target) {
//         if (v[index].child.size() != 0) {  // 没有到达叶结点
//             return;
//         }
//         for (int i = 0; i < nodeNum; i++) {  // 有多个叶结点
//             printf("%d%c", v[path[i]].w, i != nodeNum - 1 ? ' ' : '\n');
//             // 根结点是path[0]
//         }
//         return;
//     }
//     for (int i = 0; i < v[index].child.size(); i++) {
//         int node = v[index].child[i];
//         path[nodeNum] = node;  // 这里path从1开始
//         dfs0(node, nodeNum + 1, sum + v[node].w);
//     }
// }
// int cmp0(int a, int b) {
//     //
//     排序只能保证每个结点的所有子节点是按照顺序排序的，这在所有子节点的值不同时并不会产生问题。
//     // 但是如果子节点有相同值就会遇到问题。
//     return v[a].w > v[b].w;
// }
// int main0() {
//     int n, m, node, k;
//     scanf("%d %d %d", &n, &m, &target);
//     v.resize(n);
//     path.resize(n);
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &v[i].w);
//     }
//     for (int i = 0; i < m; i++) {
//         scanf("%d %d", &node, &k);
//         v[node].child.resize(k);
//         for (int j = 0; j < k; j++) {
//             scanf("%d", &v[node].child[j]);
//         }
//         sort(v[node].child.begin(), v[node].child.end(), cmp0);
//     }
//     dfs0(0, 1, v[0].w);
//     return 0;
// }