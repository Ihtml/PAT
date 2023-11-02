/*分析：1.用数组arr标记两个人是否是朋友（邻接矩阵表示），用v标记所有人的同性朋友（邻接表表示）
2.对于一对想要在一起的A和B，他们需要先找A的所有同性朋友C，再找B的所有同性朋友D，当C和D两人是朋友的时候则可以输出C和D*/
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<int, bool> arr; // 使用unordered_map来标记两个人是否是朋友（邻接矩阵表示）

struct node {
    int a, b;
};

bool cmp(node x, node y) {
    // 自定义的排序函数，用于排序结果
    // 首先按a的升序排序，如果a相同，则按b的升序排序
    return x.a != y.a ? x.a < y.a : x.b < y.b;
}

int main() {
    int n, m, k;
    cin >> n >> m; // 输入总人数n和朋友关系数m

    vector<int> v[10000]; // 使用邻接表来标记所有人的同性朋友

    for (int i = 0; i < m; i++) {
        string a, b;
        cin >> a >> b; // 输入两位朋友的编号

        if (a.length() == b.length()) {
            // 如果这两位朋友的性别相同
            v[abs(stoi(a))].push_back(abs(stoi(b)); // 在同性朋友列表中添加这两位朋友
            v[abs(stoi(b))].push_back(abs(stoi(a));
        }
        arr[abs(stoi(a)) * 10000 + abs(stoi(b))] =
            arr[abs(stoi(b)) * 10000 + abs(stoi(a))] = true;
        // 使用邻接矩阵标记这两位朋友之间的关系
    }

    scanf("%d", &k); // 输入查询次数

    for (int i = 0; i < k; i++) {
        int c, d;
        cin >> c >> d; // 输入两位希望成为朋友的人的编号

        vector<node> ans; // 存储结果

        for (int j = 0; j < v[abs(c)].size(); j++) {
            for (int k = 0; k < v[abs(d)].size(); k++) {
                if (v[abs(c)][j] == abs(d) || abs(c) == v[abs(d)][k])
                    continue; // 如果C和D已经是朋友或者与自己匹配，则跳过
                if (arr[v[abs(c)][j] * 10000 + v[abs(d)][k]] == true)
                    ans.push_back(node{v[abs(c)][j], v[abs(d)][k]});
                // 如果C的同性朋友v[abs(c)][j]和D的同性朋友v[abs(d)][k]是朋友，则添加到结果中
            }
        }

        sort(ans.begin(), ans.end(), cmp); // 排序结果

        printf("%d\n", int(ans.size())); // 输出结果的数量
        for (int j = 0; j < ans.size(); j++)
            printf("%04d %04d\n", ans[j].a, ans[j].b); // 输出每对朋友的编号
    }

    return 0;
}
