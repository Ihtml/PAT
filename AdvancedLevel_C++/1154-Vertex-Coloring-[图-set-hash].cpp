/*
Q:给出一个图（先给出所有边，后给出每个点的颜色），
问是否满足：所有的边的两个点的颜色不相同
A:把所有边存起来，把所有点的颜色存起来（存的过程中放入set统计颜色个数），
枚举所有边检查是否每条边的两点个颜色是否相同，若全不相同，则输出颜色个数，否则输出No
*/
#include <iostream>
#include <set>
#include <vector>
using namespace std;
struct node {
    int t1, t2;
};
int main() {
    // 输入节点数、边数
    int n, m, k;
    cin >> n >> m;

    // 存储所有边的信息
    vector<node> v(m);
    for (int i = 0; i < m; i++)
        scanf("%d %d", &v[i].t1, &v[i].t2);

    // 查询次数
    cin >> k;
    while (k--) {
        // 存储节点的颜色信息
        int a[10009] = {0};
        bool flag = true;

        // 存储节点颜色的集合，用于统计颜色个数
        set<int> se;

        // 输入每个节点的颜色，并统计颜色个数
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            se.insert(a[i]);
        }

        // 检查每条边的两个节点的颜色是否相同
        for (int i = 0; i < m; i++) {
            if (a[v[i].t1] == a[v[i].t2]) {
                flag = false;
                break;
            }
        }

        // 输出结果
        if (flag)
            printf("%d-coloring\n", se.size());
        else
            printf("No\n");
    }

    return 0;
}