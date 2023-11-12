#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    // 用于存储每个人的说法，下标表示人的编号，值表示说谎与否（1表示说谎，-1表示不说谎）
    vector<int> v(n + 1);

    // 输入每个人的说法
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    // 遍历所有可能的两个人的组合
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            // lie 数组用于存储说谎的人的编号
            vector<int> lie;

            // flag 数组用于标记每个人是否说谎
            vector<int> flag(n + 1, 1);

            // 假设第 i 和 j 个人说谎
            flag[i] = flag[j] = -1;

            // 判断每个人的说法是否与标记一致
            for (int k = 1; k <= n; k++) {
                if (v[k] * flag[abs(v[k])] < 0) {
                    lie.push_back(k);
                }
            }

            // 如果存在两个说谎的人，并且这两个人说的话相互矛盾
            if (lie.size() == 2 && (flag[lie[0]] + flag[lie[1]]) == 0) {
                cout << i << " " << j;
                return 0;
            }
        }
    }

    // 如果没有找到解决方案
    cout << "No Solution";
    return 0;
}
