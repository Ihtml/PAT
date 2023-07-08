/*给出n和n个数的序列a和b，a为原始序列，b为排序其中的一个步骤，问b是a经过了堆排序还是插入排序的，并且输出它的下一步*/
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
    }

    return 0;
}