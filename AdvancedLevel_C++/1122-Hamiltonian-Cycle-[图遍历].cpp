/*给出一个图，判断给定的路径是不是包含了图所有顶点的环*/
#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main() {
    int n, m, cnt, k, a[210][210] = {{0}};
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        a[t1][t2] = a[t2][t1] = 1;
    }
    cin >> cnt;
    while (cnt--) {
        cin >> k;
        vector<int> v(k);  // 用vector存储当前路径的顶点序列
        set<int> s;
        int flag1 = 1, flag2 = 1;
        for (int i = 0; i < k; i++) {
            cin >> v[i];
            s.insert(v[i]);  // 将顶点加入set中，检查是否有重复顶点
        }
        // s.size() != n：这部分条件检查路径中的顶点数是否等于图中的顶点数 n
        // k - 1 != n：这部分条件检查路径的长度（顶点数减去1）是否等于图中的顶点数 n
        // v[0] != v[k - 1]：这部分条件检查路径的起点和终点是否相同。
        if (s.size() != n || k - 1 != n || v[0] != v[k - 1])
            flag1 = 0;
        for (int i = 0; i < k - 1; i++)
            if (a[v[i]][v[i + 1]] == 0)
                flag2 = 0;  // 判断路径是否满足图的边的条件
        printf("%s", flag1 && flag2 ? "YES\n" : "NO\n");
    }
    return 0;
}
