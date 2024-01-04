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
    int k, n, m, c, r, d, sc[1001], rec[1001], record[1001][1001];
    vector<int> su;
    cin >> k >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> c >> r >> d;
        record[c][r] += d;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (record[i][j] && record[i][j] <= 5) {
                sc[i]++;
                if (record[j][i]) {
                    rec[i]++;
                }
            }
        }
        if (sc[i] > k && rec[i] * 5 <= sc[i]) {
            su.push_back(i);
        }
    }
    if (su.empty()) {
        cout << "None";
        return 0;
    }
    for (int i = 0; i < su.size(); i++) {
        for (int j = i + 1; j < su.size(); j++) {
            if (record[su[i]][su[j]] && record[su[j]][su[i]]) {
                Union(su[i], su[j]);
            }
        }
    }

    return 0;
}