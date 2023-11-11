#include <iostream>
#include <vector>
using namespace std;

// 判断是否是素数
bool isPrime(int a) {
    if (a < 5) {
        if (a == 2 || a == 3) {
            return true;
        }
        return false;
    }
    if (a % 6 != 1 && a % 6 != 5) {
        return false;
    }
    for (int i = 5; i * i <= a; i += 6) {
        if (a % i == 0 || a % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int max, n, m, key;
    cin >> max >> n >> m;

    // 寻找大于等于 max 的下一个素数
    while (!isPrime(max)) {
        max++;
    }

    vector<int> v(max);

    // 插入 n 个数到哈希表
    for (int i = 0; i < n; i++) {
        cin >> key;
        int flag = 0;

        // 使用平方探测法解决冲突
        for (int i = 0; i <= max - 1; i++) {
            int pos = (key + i * i) % max;
            if (v[pos] == 0) {
                flag = 1;
                v[pos] = key;
                break;
            }
        }

        // 如果无法插入，输出提示
        if (!flag) {
            printf("%d cannot be inserted.\n", key);
        }
    }

    int ctn = 0;

    // 查询 m 个数在哈希表的位置
    for (int i = 0; i < m; i++) {
        cin >> key;
        for (int j = 0; j <= max; j++) {
            ctn++;
            int pos = (key + j * j) % max;

            // 如果找到了目标数或者遇到了空位置，停止查找
            if (v[pos] == key || v[pos] == 0)
                break;
        }
    }

    // 输出平均查找次数
    printf("%.1f", ctn * 1.0 / m);

    return 0;
}