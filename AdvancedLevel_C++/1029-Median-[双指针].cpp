#include <limits.h>
#include <iostream>
using namespace std;

const int maxn = 200005;
int n, m, a1[maxn], a2[maxn], cnt = 0, i, j, ans;
int k[maxn];

int main() {
    // 输入数组 a1 的大小和元素
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &a1[i]);
    }

    // 输入数组 a2 的大小和元素
    scanf("%d", &m);
    for (i = 1; i <= m; i++) {
        scanf("%d", &a2[i]);
    }

    // 计算中位数的位置
    int target = (n + m + 1) / 2;
    i = 1, j = 1;

    // 合并有序数组，找到中位数
    while (i <= n && j <= m) {
        ans = a1[i] <= a2[j] ? a1[i++] : a2[j++];
        if (++cnt == target)
            break;
    }

    // 处理剩余元素
    if (i <= n && cnt < target) {
        ans = a1[i + target - cnt - 1];
    } else if (j <= m && cnt < target) {
        ans = a2[j + target - cnt - 1];
    }

    // 输出结果
    printf("%d", ans);
    return 0;
}

int main1() {
    int n, m, temp, count = 0;
    cin >> n;

    // 输入数组 k 的元素
    for (int i = 1; i <= n; i++) {
        scanf("%d", &k[i]);
    }

    // 设置 k[n+1] 为最大值，用于比较
    k[n + 1] = INT_MAX;

    cin >> m;
    int midpos = (n + m + 1) / 2, i = 1;

    // 合并有序数组，找到中位数
    for (int j = 1; i <= n && j <= m; j++) {
        scanf("%d", &temp);
        while (k[i] <= temp) {
            count++;
            if (count == midpos) {
                cout << k[i];
                return 0;
            }
            i++;
        }
        count++;
        if (count == midpos) {
            cout << temp;
            return 0;
        }
    }

    // 处理剩余元素
    while (count < midpos) {
        count++;
        if (count == midpos) {
            cout << k[i];
            return 0;
        }
        i++;
    }
}
