/*
一串数字序列中按给定数字和序列裁剪出最长的串
*/
#include <iostream>
#include <vector>
using namespace std;
int book[201], a[10001], dp[10001];
int main() {
    int n, m, l, x, num = 0, maxn = 0;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x;
        book[x] = i;
    }
    cin >> l;
    for (int i = 0; i < 1; i++) {
        cin >> x;
        if (book[x] >= 1) {
            a[num++] = book[x];
        }
    }

    return 0;
}