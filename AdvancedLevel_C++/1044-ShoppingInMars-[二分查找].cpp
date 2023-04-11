#include <iostream>
#include <vector>
using namespace std;
/*
Q:求⼀串的数字中连续的⼀段，使得这个连续的段内数字的和恰好等于所期望的值m。如果
不能找到恰好等于，就找让⾃自己付出最少的价格(总和必须⼤于等于所给值)的那段区间。求所有可
能的结果。
*/
vector<int> sum, resultArr;
int n, m;
void Func(int i, int& j, int& tempsum) {  // 二分查找
    int left = i, right = n;
    while (left < right) {
        int mid = (left + right) / 2;
        if (sum[mid] - sum[i - 1] >= m) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    j = right;
    tempsum = sum[j] - sum[i - 1];
}
int main() {
    cin >> n >> m;
    sum.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> sum[i];
        sum[i] += sum[i - 1];
    }
    int minans = sum[n];
    for (int i = 1; i <= n; i++) {
        int j, tempsum;
        Func(i, j, tempsum);
        if (tempsum > minans) {
            continue;
        }
    }
    return 0;
}