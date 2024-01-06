#include <iostream>
#include <vector>
using namespace std;
int p[1001];
int Find(int a) {
    if (p[a] != a) {
        return p[a] = Find(p[a]);  // 路径压缩
    }
    return a;
}
void Union(int a, int b) {
    int f1 = Find(a), f2 = Find(b);
    if (f1 < f2) {
        p[f2] = f1;
    } else {
        p[f1] = f2;
    }
}
int main() {
    // sc中存储短通话的人数，rec中存储短通话收到回电的人数,su中保存嫌疑人的编号
    int k, n, m, c, r, d, record[1001][1001];
    // 不用 int sc(1001), rec(1001), mark(1001);声明，避免潜在的错误
    vector<int> su, sc(1001), rec(1001), mark(1001);
    
    // 初始化并查集的父节点数组
    for (int i = 1; i <= 1000; i++)
        p[i] = i;
    cin >> k >> n >> m;
    // 输入总人数 k，节点数 n，短通话记录数 m
    for (int i = 0; i < m; i++) {
        cin >> c >> r >> d;
        record[c][r] += d;
    }
    // 遍历每个节点，统计短通话收发情况，找出嫌疑人
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (record[i][j] && record[i][j] <= 5) {
                sc[i]++;
                if (record[j][i]) {
                    rec[i]++;
                }
            }
        }
        // 判断是否为嫌疑人，符合条件则加入嫌疑人列表
        if (sc[i] > k && (rec[i] * 5 <= sc[i])) {
            su.push_back(i);
        }
    }
    if (su.empty()) {
        cout << "None";
        return 0;
    }
    // 对嫌疑人列表进行遍历，合并具有通话关系的嫌疑人
    for (int i = 0; i < su.size(); i++) {
        for (int j = i + 1; j < su.size(); j++) {
            if (record[su[i]][su[j]] && record[su[j]][su[i]]) {
                Union(su[i], su[j]);
            }
        }
    }
    for (int i = 0; i < su.size(); i++) {
        if (mark[i]) {
            continue;
        }
        cout << su[i];
        for (int j = i + 1; j < su.size(); j++) {
            if (Find(su[i]) == Find(su[j])) {
                cout << ' ' << su[j];
                mark[j] = 1;
            }
        }
        cout << "\n";
    }
    return 0;
}