// 枚举从n个数中选择k个数的所有方案
// 有n件物品，每件物品重量w[i]价值c[i],
// 选出若干件放入一个容量为V的背包中，让背包中物品价值和最大，求最大价值
#include <iostream>
using namespace std;
const int maxn = 30;
int n, V, maxValue = 0;
int w[maxn], c[maxn];
void DFS0(int index, int sumW, int sumC) {
    if (index == n) {
        if (sumW <= V && sumC > maxValue) {
            maxValue = sumC;
        }
        return;
    }
    DFS0(index + 1, sumW, sumC);
    DFS0(index + 1, sumW + w[index], sumC + c[index]);
}
void DFS(int index, int sumW, int sumC) {
    if (index == n) {  // 死胡同,已经完成对n件物品的选择
        return;
    }
    DFS(index + 1, sumW, sumC);  // 岔路一：不选当前物品
    if (sumW + w[index] <= V) {  // 剪枝: 加入当前物品后总重量小于V才能继续
        if (sumC + c[index] > maxValue) {
            maxValue = sumC + c[index];
        }  // 岔路二：选择当前物品
        DFS(index + 1, sumW + w[index], sumC + c[index]);
    }
}
int main() {
    cin >> n >> V;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    DFS(0, 0, 0);
    cout << maxValue;
    return 0;
}