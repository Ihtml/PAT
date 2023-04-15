/*
一串数字序列中按给定数字和序列裁剪出最长的串
按照最⻓下降⼦序列的方式做，对于从前到后的每一个i，如果它前⾯面的所有的j，找到了一个j的下标
book[j]⽐book[i]小，此时就更新dp[i]使它 = max(dp[i], dp[j] +1);
并且同时再每⼀次遍历完成一次j后更新maxn的值为长度的最⼤值，最后输出maxn
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
/*
Sample Input:
6
523156
12 2 2 4 1 5 5 6 3 1 1 5 6
Sample Output:
7
*/