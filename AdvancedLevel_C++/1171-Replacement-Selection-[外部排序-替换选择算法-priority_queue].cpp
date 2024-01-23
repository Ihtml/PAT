#include <climits>  // 包含INT_MAX
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, m, idx, minMax = INT_MAX;
priority_queue<int, vector<int>, greater<int>> Q1, Q2;  // 最小堆优先队列。
int main() {
    cin >> n >> m;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        if (i <= m) {
            Q1.push(A[i]);
        }
    }
    idx = m + 1;
    while (Q1.size()) {
        minMax = Q1.top();  // 访问最高优先级元素。Q1中为最小元素
        cout << minMax;
        Q1.pop();  // 移除Q1队首元素，在优先队列中不使用 q.front()q.back()
        if (idx <= n) {
            if (A[idx] < minMax) {
                Q2.push(A[idx]);
            } else {
                Q1.push(A[idx]);
            }
            idx++;
        }
        if (Q1.size()) {
            cout << ' ';
        } else {
            swap(Q1, Q2);  // 交换Q1 Q2两个容器内的所有值
            cout << "\n";
        }
    }
    return 0;
}