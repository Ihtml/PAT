/*通过邻接表的方式表示图，然后对于每个查询，检查查询的节点是否构成了图中的边。
如果存在构成边的情况，输出 "No"，否则输出 "Yes"。*/
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int main() {
    int n, m, a, b;
    scanf("%d %d", &n, &m);

    // 使用 map 存储每个点的邻接点集合
    map<int, set<int>> mp;

    // 输入每条边的信息，并构建邻接表
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        mp[a].insert(b);
        mp[b].insert(a);
    }

    // 处理每个查询
    for (int i = 0; i < m; i++) {
        int num, flag = 0;
        scanf("%d", &num);

        // 临时存储当前查询的节点
        vector<int> temp(num);

        // book 数组标记当前查询的节点是否存在
        vector<int> book(1000001);

        // 输入当前查询的节点，并标记 book 数组
        for (int j = 0; j < num; j++) {
            scanf("%d", &temp[j]);
            book[temp[j]] = 1;
        }

        // 检查当前查询的节点是否构成了图中的边
        for (int j = 0; j < num; j++) {
            int t = temp[j];
            if (mp[t].size() != 0) {
                for (auto it = mp[t].begin(); it != mp[t].end(); it++) {
                    if (book[*it]) {
                        flag = 1;
                        break;
                    }
                }
            }

            if (flag) {
                printf("No\n");
                break;
            }
        }

        // 如果没有找到构成边的情况，输出 "Yes"
        if (flag == 0) {
            printf("Yes\n");
        }
    }

    return 0;
}
