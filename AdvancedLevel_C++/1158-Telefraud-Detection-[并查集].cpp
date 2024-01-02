#include <iostream>
#include <vector>
using namespace std;
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

    return 0;
}