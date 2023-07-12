/*给出n和n个数的序列a和b，a为原始序列，b为排序其中的一个步骤，问b是a经过了堆排序还是插入排序的，并且输出它的下一步*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void downAdjust(vector<int>& b, int low, int high) {
    int i = 1, j = i * 2;
    while (j <= high) {
        if (j + 1 <= high && b[j] < b[j + 1]) {
            j = j + 1;
        }
        if (b[i] >= b[j]) {
            break;
        }
        swap(b[i], b[j]);
        i = j;
        j = i * 2;
    }
}
int main() {
    int n, p = 2;
    scanf("%d", &n);
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
    }
    while (p <= n && b[p - 1] <= b[p]) {
        p++;
    }
    int index = p;  // b[p] < b[p-1]
    while (p <= n && a[p] == b[p]) {
        p++;
    }
    if (p == n + 1) {
        printf("Insertion Sort\n");
        // 插入排序的下一步就是把第一个不符合从小到大的顺序的那个元素插入到前面已排序的里面的合适的位置
        // 那么只要对前几个已排序的+后面一位这个序列sort排序即可
        sort(b.begin() + 1, b.begin() + index + 1);
    } else {
        printf("Heap Sort\n");
        p = n;
        while (p > 2 && b[p] >= b[1]) {
            p--;
        }
        swap(b[1], b[p]);
        // 调整堆
        downAdjust(b, 1, p - 1);
    }
    printf("%d", b[1]);
    for (int i = 2; i <= n; i++) {
        printf(" %d", b[i]);
    }
    return 0;
}