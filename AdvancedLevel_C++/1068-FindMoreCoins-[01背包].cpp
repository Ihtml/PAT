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
bool cmp(int a, int b) {
    return a > b;
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
    }
    sort(w + 1, w + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= w[i]; j--) {
            if (dp[j] <= dp[j - w[i]] + w[i]) {
                choice[i][j] = true;
                dp[j] = dp[j - w[i]] + w[i];
            }
        }
    }
    if (dp[m] != m) {
        cout << "No Solution";
    } else {
        vector<int> arr;
        int v = m, index = n;
        while (v > 0) {
            if (choice[index][v] == true) {
                arr.push_back(w[index]);
                v -= w[index];
            }
            index--;
        }
        for (int i = 0; i < arr.size(); i++) {
            if (i != 0) {
                cout << " ";
            }
            cout << arr[i];
        }
    }
    return 0;
}