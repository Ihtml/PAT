#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct node {
    int poptime;   // 队首的人出队时间
    int endtime;   // 队尾的人结束时间
    queue<int> q;  // 当前排队队列
};                 // 一个node表示一个窗口
int main() {
    int n, m, k, q, index = 1;
    // n个窗口 每个窗口排队m人 有k个用户需要服务 求q个人的服务结束时间
    scanf("%d%d%d%d", &n, &m, &k, &q);
    vector<int> time(k + 1), result(k + 1);
    for (int i = 1; i <= k; i++) {
        scanf("%d", &time[i]);  // k个人 每人需要服务的时间
    }
    vector<node> window(n + 1);
    vector<bool> sorry(k + 1, false);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (index <= k) {
                window[j].q.push(time[index]);
                if (window[j].endtime >= 540) {
                    sorry[index] = true;
                }
                window[j].endtime += time[index];
                if (i == 1) {
                    window[j].poptime = window[j].endtime;
                }
                result[index] = window[j].endtime;
                index++;
            }
        }
    }

    return 0;
}