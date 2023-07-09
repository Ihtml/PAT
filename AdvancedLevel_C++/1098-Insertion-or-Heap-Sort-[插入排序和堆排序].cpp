/*给出n和n个数的序列a和b，a为原始序列，b为排序其中的一个步骤，问b是a经过了堆排序还是插入排序的，并且输出它的下一步*/
#include <iostream>
#include <vector>
using namespace std;
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
    if (p = n + 1) {
        printf("Insertion Sort\n");
    } else {
        printf("Heap Sort\n");
    }

    return 0;
}