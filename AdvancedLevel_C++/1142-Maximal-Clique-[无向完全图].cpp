/*判断是否是极大连通分量，即判断是否任意两边都相连；
之后判断是否是maximal，即遍历所有不在集合中的剩余的点，看是否存在一个点满足和集合中所有的结点相连，
最后如果都满足，那就输出Yes表示是Maximal clique */
#include <iostream>
#include <vector>
using namespace std;

int e[210][210];  // 邻接矩阵，用于表示图的边关系

int main() {
    int nv, ne, m, ta, tb, k;
    cin >> nv >> ne;  // 输入顶点数和边数

    // 构建邻接矩阵
    for (int i = 0; i < ne; i++) {
        cin >> ta >> tb;
        e[ta][tb] = e[tb][ta] = 1;  // 标记顶点 ta 和 tb 之间有边相连
    }

    cin >> m;  // 输入测试集合的数量
    for (int i = 0; i < m; i++) {
        cin >> k;          // 输入当前集合中的顶点数量
        vector<int> v(k);  // 存储当前集合的顶点

        int hash[210] = {0}, isclique = 1, isMaximal = 1;

        // 标记当前集合中的顶点
        for (int j = 0; j < k; j++) {
            scanf("%d", &v[j]);
            hash[v[j]] = 1;
        }

        // 判断当前集合是否是一个团（任意两个顶点都相连）
        for (int j = 0; j < k; j++) {
            if (isclique == 0)
                break;
            for (int l = j + 1; l < k; l++) {
                if (e[v[j]][v[l]] == 0) {
                    isclique = 0;
                    printf("Not a Clique\n");
                    break;
                }
            }
        }

        if (isclique == 0)
            continue;

        // 判断当前集合是否是极大团（不能再添加任何一个顶点使其成为团）
        for (int j = 1; j <= nv; j++) {
            if (hash[j] == 0) {
                for (int l = 0; l < k; l++) {
                    if (e[v[l]][j] == 0)
                        break;
                    if (l == k - 1)
                        isMaximal = 0;
                }
            }
            if (isMaximal == 0) {
                printf("Not Maximal\n");
                break;
            }
        }

        // 输出结果
        if (isMaximal == 1)
            printf("Yes\n");
    }

    return 0;
}
