/*
一串数字序列中按给定数字和序列裁剪出最长的串
*/
#include <iostream>
#include <vector>
using namespace std;
int book[201], a[10001], dp[10001];
int main() {
    int n, m, l, x, num = 0, maxn = 0;
    cin >> n >> m;  // 共n种颜色 m个喜欢的颜色
    for (int i = 1; i <= m; i++) {
        cin >> x;
        book[x] = i;
    }
    cin >> l;
    for (int i = 0; i < l; i++) {
        cin >> x;
        if (book[x] >= 1) {  // 是喜欢的颜色
            a[num++] = book[x];
        }
    }
    for (int i = 0; i < num; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[i] >= a[j]) {  // 比较是否符合顺序
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxn = max(dp[i], maxn);
    }
    cout << maxn;
    return 0;
}