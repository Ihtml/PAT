/*
Q:用n个硬币买价值为m的东西，输出使用方案，使得正好几个硬币加起来价值为m。
从小到大排列，输出最小的那个排列方案
A:
首先读取输入的硬币个数n和目标价值m，然后读取每个硬币的面值。接下来对硬币面值进行降序排序，以便从大到小遍历硬币。
使用动态规划的思想，通过填充dp数组和choice数组来记录状态和选择。dp数组表示达到不同价值时的最大面值和，choice数组用于记录选择的硬币方案。
在遍历硬币和目标价值的过程中，使用双重循环。外层循环遍历硬币，内层循环从目标价值m开始递减，表示要支付的价格。
在内层循环中，判断当前硬币面值w[i]是否可以选择。如果选择当前硬币，那么当前状态的最大面值和dp[j]就等于dp[j
- w[i]] + w[i]，表示选择了当前硬币后的最大面值和。
在选择硬币时，同时记录选择的方案到choice数组中。如果选择了当前硬币，那么choice[i][j]为true，表示选择了第i个硬币。
最后，判断dp[m]是否等于目标价值m。如果不等于m，则表示无法凑出目标价值，输出"No
Solution"。如果dp[m]等于m，则表示成功凑出了目标价值，根据choice数组回溯得到最小的排列方案。
回溯的过程是从最后一个硬币开始，根据choice数组的记录判断是否选择该硬币。如果选择了该硬币，则将其加入到最小排列方案中，并将目标价值减去当前硬币的面值。然后继续向前回溯，直到回溯结束。
最后，按照从小到大的顺序输出最小排列方案，即为所求的结果。
*/
#include <algorithm>
#include <iostream>
#include <vector>
    using namespace std;

int dp[10005];  // 动态规划数组，存储达到不同价值时的最大面值和
int w[10005];             // 存储硬币面值的数组
bool choice[10005][105];  // 记录选择方案的二维数组

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
    }

    sort(w + 1, w + n + 1, cmp);  // 将硬币面值按照从大到小的顺序排序

    for (int i = 1; i <= n; i++) {  // 遍历n个不同的硬币
        for (int j = m; j >= w[i];
             j--) {  // 从目标价值m开始递减，表示要支付的价格
            if (dp[j] <= dp[j - w[i]] + w[i]) {  // 根据状态转移方程做出选择
                choice[i][j] = true;             // 记录选择
                dp[j] = dp[j - w[i]] + w[i];  // 更新dp数组
            }
        }
    }

    if (dp[m] != m) {
        cout << "No Solution";  // 无解的情况
    } else {
        vector<int> arr;
        int v = m, index = n;
        while (v > 0) {  // 根据choice数组回溯得到最小排列方案
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
            cout << arr[i];  // 输出最小排列方案
        }
    }

    return 0;
}