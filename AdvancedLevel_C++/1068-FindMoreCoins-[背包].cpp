/*
 Q:用n个硬币买价值为m的东西，输出使用方案，使得正好几个硬币加起来价值为m。
 从小到大排列，输出最小的那个排列方案
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int dp[10005], w[10005];
bool choice[10005][105];
int w[10005];
bool cmp(int a, int b){return a > b;}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
    }
    sort(w+1, w+n+1, cmp);
    return 0;
}