/*
题目大意：给一棵树，在树根出货物的价格为p，
从根结点开始每往下走一层，该层的货物价格将会在父亲结点的价格上增加r%，
求所有叶子结点的最高价格，以及这个价格的叶子结点个数。
*/

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int n, maxdepth = 0, maxnum = 0, temp, root;
vector<int> v[100010];  // 二维数组

void dfs(int index, int depth) {
    if (v[index].size() == 0) {  // 如果当前节点是叶子结点
        if (maxdepth == depth) {
            maxnum++;  // 叶子结点深度与当前最大深度相同，叶子结点数量加一
        }
        if (maxdepth < depth) {
            maxdepth = depth;  // 更新最大深度
            maxnum = 1;        // 重置叶子结点数量
        }
        return;
    }
    for (int i = 0; i < v[index].size(); i++) {
        dfs(v[index][i], depth + 1);  // 递归地遍历当前结点的子节点
    }
}

int main() {
    double p, r;
    // n-供应商数量 p-根节点价格 r-价格提升比例
    scanf("%d %lf %lf", &n, &p, &r);

    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        if (temp == -1) {
            root = i;  // 记录根节点的索引
        } else {
            v[temp].push_back(i);  // 将当前结点添加为父节点的子节点
        }
    }

    dfs(root, 0);  // 从根节点开始进行深度优先搜索
    // 计算最终价格和叶子结点数量
    double finalPrice = p * pow(1 + r / 100, maxdepth);
    printf("%.2f %d", finalPrice, maxnum);
    return 0;
}
