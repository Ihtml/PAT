/*
提供一棵树，在树根处货物的价格为p，从根结点开始每往下一层，该层货物价格将会在父亲结点的价格上增加r%。
求叶子结点出能获得的最低价格以及能提供最低价格的叶子结点数
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> v[100005];  // 用于存储树的结构，v[i]表示结点i的子结点的编号集合
// mindepth用于记录叶子结点的最小深度，minnum用于记录拥有最小价格的叶子结点数
int mindepth = 99999999, minnum = 1;  
// 深度优先搜索函数，计算叶子结点的最小深度以及拥有最小价格的叶子结点数
void dfs(int index, int depth) {
    // 若当前深度超过最小深度，直接返回，无需继续搜索
    if (mindepth < depth) {
        return;
    }

    // 若当前结点是叶子结点
    if (v[index].size() == 0) {
        // 若当前深度与最小深度相等，则拥有最小价格的叶子结点数加1
        if (mindepth == depth) {
            minnum++;
        }
        // 若当前深度比最小深度小，则更新最小深度，并重置拥有最小价格的叶子结点数为1
        else if (mindepth > depth) {
            mindepth = depth;
            minnum = 1;
        }
    }

    // 对当前结点的所有子结点进行递归搜索
    for (int i = 0; i < v[index].size(); i++) {
        dfs(v[index][i], depth + 1);
    }
}

int main() {
    int n, k, c;
    double p, r;
    // 输入n为结点数，p为根结点货物价格，r为每层增长的百分比
    scanf("%d %lf %lf", &n, &p, &r);  

    // 输入每个结点的子结点信息，构建树的结构
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &c);
            v[i].push_back(c);
        }
    }

    // 深度优先搜索，计算叶子结点的最小深度以及拥有最小价格的叶子结点数
    dfs(0, 0);

    // 计算拥有最低价格的叶子结点的价格，并输出结果
    printf("%.4lf %d", p * pow(1 + r / 100, mindepth), minnum);
    return 0;
}