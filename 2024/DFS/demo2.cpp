// Q:给定n个整数（可能有负数），从中选择k个数，使得这k个数之和恰好等于一个给定的整数X
// 如果有多种方案，选择平方和最大的方案
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 30;
// 序列A的n个数中选k个数使得和为x,最大平方和为maxSumSqu
int n, k, x, maxSumSqu = -1, A[maxn];
vector<int> temp, ans;  // temp存临时方案，ans存最终方案
void DFS(int index, int nowK, int sum, int sumSqu) {
    if (nowK == k && sum == x) {
        if (sumSqu > maxSumSqu) {  // 更新最优方案
            maxSumSqu = sumSqu;
            ans = temp;
        }
        return;
    }
    if (index == n || nowK > k || sum > x)
        return;  // 死胡同：已经处理完n个数，或者超过k个数，或者平方和超过x
    temp.push_back(A[index]);  // 分岔：选index号数
    DFS(index + 1, nowK + 1, sum + A[index], sumSqu + A[index] * A[index]);
    // 如果每个数可以被选多次
    // DFS(index, nowK + 1, sum + A[index], sumSqu + A[index] * A[index]);
    temp.pop_back();  // 分岔：不选index号数
    DFS(index + 1, nowK + 1, sum, sumSqu);
}
int main() {
    return 0;
}