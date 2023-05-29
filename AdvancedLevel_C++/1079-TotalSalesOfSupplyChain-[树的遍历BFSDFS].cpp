/*
题目大意：给一棵树，在树根出货物的价格为p，
从根结点开始每往下走一层，该层的货物价格将会在父亲结点的价格上增加r%，
给出每个叶结点的货物量，求他们的价格之和
*/

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// 定义树节点结构体
struct node {
    double data;        // 节点的货物量
    vector<int> child;  // 子节点的索引
};

vector<node> v;  // 树的存储
double ans = 0.0, p, r;  // 累计的价格之和，根节点的价格，价格增加的百分比

// 深度优先搜索函数
void dfs(int index, int depth) {
    // 如果当前节点是叶子节点，则累计价格
    if (v[index].child.size() == 0) {
        ans += v[index].data * pow(1 + r, depth);
        return;
    }

    // 遍历当前节点的子节点
    for (int i = 0; i < v[index].child.size(); i++) {
        // 递归地对每个子节点进行深度优先搜索
        dfs(v[index].child[i], depth + 1);
    }
}

int main() {
    int n, k, c;
    scanf("%d %lf %lf", &n, &p, &r);  // 输入树的节点数、根节点价格p、价格增加的百分比r
    r = r / 100;  // 将百分比转换为小数
    v.resize(n);  // 调整树的存储大小

    // 输入每个节点的信息
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);  // 输入当前节点的子节点个数k
        if (k == 0) {
            scanf("%lf", &v[i].data);  // 如果没有子节点，输入当前节点的货物量
        } else {
            for (int j = 0; j < k; j++) {
                scanf("%d", &c);  // 输入当前节点的每个子节点的索引
                v[i].child.push_back(c);
            }
        }
    }

    dfs(0, 0);                // 从根节点开始进行深度优先搜索
    printf("%.1f", ans * p);  // 输出累计的价格之和
    return 0;
}
