#include <iostream>
#include <stack>
#define lowbit(i) ((i) & (-i))  // 宏定义lowbit(i)
const int maxn = 100010;        // 数组c的大小
using namespace std;

int c[maxn];   // 树状数组，存储每个数字出现的次数
stack<int> s;  // 栈，存储输入的数字

// 更新树状数组
void update(int x, int v) {
    for (int i = x; i < maxn; i += lowbit(i)) {  // 从x开始向后更新
        c[i] += v;  // 更新数字x在树状数组中的出现次数
    }
}

// 获取前缀和
int getsum(int x) {
    int sum = 0;
    for (int i = x; i >= 1; i -= lowbit(i)) {  // 从x开始向前获取前缀和
        sum += c[i];  // 累加数字i在树状数组中的出现次数
    }
    return sum;
}

// 查找中位数
void PeekMedian() {
    int left = 1, right = maxn, mid,
        k = ((s.size() + 1) / 2);  // 初始化left、right、k
    while (left < right) {         // 二分查找
        mid = (left + right) / 2;  // 计算中间位置
        if (getsum(mid) >= k) {  // 中间位置的数字出现次数大于等于k
            right = mid;         // 向左查找
        } else {
            left = mid + 1;  // 向右查找
        }
    }
    printf("%d\n", left);  // 输出中位数
}
int main() {
    int n, temp;
    scanf("%d", &n);
    string str;
    for (int i = 0; i < n; i++) {
        cin >> str;
        switch (str[1]) {
            case 'u':  // push操作
                scanf("%d", &temp);
                s.push(temp);
                update(temp, 1);
                break;

            case 'o':  // pop操作
                if (!s.empty()) {
                    update(s.top(), -1);
                    printf("%d\n", s.top());
                    s.pop();
                } else {
                    printf("Invalid\n");
                }
                break;

            default:  // median操作
                if (!s.empty()) {
                    PeekMedian();
                } else {
                    printf("Invalid\n");
                }
                break;
        }
    }
    return 0;
}