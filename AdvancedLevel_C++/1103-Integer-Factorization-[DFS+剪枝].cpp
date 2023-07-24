/*
给三个正整数N、K、P，将N表示成K个正整数（可以相同，递减排列）的P次方和，
如果有多种方案，选择底数n1 +…+nk最大的方案，
如果还有多种方案，选择底数序列的字典序最大的方案
*/
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int n, k, p, maxFacSum = -1;
vector<int> v, ans, tempAns;
// 回溯搜索函数
void dfs(int index, int tempSum, int tempK, int facSum) {
    // 达到选取k个数的条件
    if (tempK == k) {
        // 符合条件且总和为n，且p次方数的和大于之前的最大值
        if (tempSum == n && facSum > maxFacSum) {
            ans = tempAns;
            maxFacSum = facSum;
        }
        return;
    }
    // 回溯搜索
    while (index >= 1) {
        // 当前数的p次方数值仍然小于等于n，继续搜索
        if (tempSum + v[index] <= n) {
            tempAns[tempK] = index;  // 将当前数的索引记录在tempAns中
            dfs(index, tempSum + v[index], tempK + 1, facSum + index);  // 递归搜索下一个数
        }
        if (index == 1)
            return;  // 递归边界条件，避免无限循环
        index--;     // 尝试下一个数的索引
    }
}
int main() {
    scanf("%d%d%d", &n, &k, &p);
    int temp = 0, index = 1;
    while (temp <= n) {
        v.push_back(temp);
        temp = pow(index, p);
        index++;
    }
    tempAns.resize(k);

    return 0;
}