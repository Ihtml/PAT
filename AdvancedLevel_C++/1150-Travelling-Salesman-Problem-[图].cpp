/*给出一条路径，判断这条路径是这个图的旅行商环路、简单旅行商环路还是非旅行商环路*/
// 如果给出的路径存在某两个连续的点不可达,或者第一个结点和最后一个结点不同,
// 或者这个路径没有访问过图中所有的点，它就不是一个旅行商环路(flag = 0)
#include <iostream>
#include <set>
#include <vector>
using namespace std;

// 图的邻接矩阵表示
int e[300][300];
// 图的顶点数和边数
int n, m;
// 待检查的路径数、最短路径和对应的路径编号
int k, ans = 99999999, ansid;
// 用于存储读取路径的顶点序列
vector<int> v;

// 检查路径是否为旅行商环路
void check(int index) {
    int sum = 0, cnt, flag = 1;
    // 读取路径长度
    scanf("%d", &cnt);
    set<int> s;
    vector<int> v(cnt);

    // 读取路径中的顶点
    for (int i = 0; i < cnt; i++) {
        scanf("%d", &v[i]);
        s.insert(v[i]);
    }

    // 检查路径的连通性
    for (int i = 0; i < cnt - 1; i++) {
        if (e[v[i]][v[i + 1]] == 0)
            flag = 0;
        sum += e[v[i]][v[i + 1]];
    }

    // 输出检查结果
    if (flag == 0) {
        printf("Path %d: NA (Not a TS cycle)\n", index);
    } else if (v[0] != v[cnt - 1] || s.size() != n) {
        printf("Path %d: %d (Not a TS cycle)\n", index, sum);
    } else if (cnt != n + 1) {
        printf("Path %d: %d (TS cycle)\n", index, sum);
        // 更新最短路径和对应的编号
        if (sum < ans) {
            ans = sum;
            ansid = index;
        }
    } else {
        printf("Path %d: %d (TS simple cycle)\n", index, sum);
        // 更新最短路径和对应的编号
        if (sum < ans) {
            ans = sum;
            ansid = index;
        }
    }
}

int main() {
    // 读取图的顶点数和边数
    scanf("%d%d", &n, &m);

    // 读取图的边信息
    for (int i = 0; i < m; i++) {
        int t1, t2, t;
        scanf("%d%d%d", &t1, &t2, &t);
        e[t1][t2] = e[t2][t1] = t;
    }

    // 读取待检查的路径数
    scanf("%d", &k);

    // 对每条路径进行检查
    for (int i = 1; i <= k; i++)
        check(i);

    // 输出最短路径信息
    printf("Shortest Dist(%d) = %d\n", ansid, ans);

    return 0;
}
