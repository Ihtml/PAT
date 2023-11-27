// 给一个树的层序遍历，判断它是不是堆，是大顶堆还是小顶堆。输出这个树的后序遍历
#include <iostream>
using namespace std;

int a[1005], m, n;

// 递归函数，用于输出以 index 为根的子树的后序遍历
void postOrder(int index) {
    if (index > n) {
        return;  // 超出数组范围，结束递归
    }
    postOrder(index * 2);      // 左子树
    postOrder(index * 2 + 1);  // 右子树
    cout << a[index] << (index == 1 ? "\n" : " ");  // 输出当前节点的值，根据是否是根节点决定输出换行符或空格
}

int main() {
    cin >> m >> n;
    while (m--) {
        int minn = 1, maxn = 1;

        // 读取数组元素
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);

        // 判断是大顶堆还是小顶堆
        for (int i = 2; i <= n; i++) {
            if (a[i] > a[i / 2])
                maxn = 0;  // 不是大顶堆
            if (a[i] < a[i / 2])
                minn = 0;  // 不是小顶堆
        }

        // 输出结果
        if (maxn == 1)
            printf("Max Heap\n");
        else if (minn == 1)
            printf("Min Heap\n");
        else
            printf("Not Heap\n");

        postOrder(1);  // 输出后序遍历
    }

    return 0;
}
