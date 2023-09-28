/*给一个二叉树，输出中缀表达式，且加上括号表示运算的优先级*/
#include <iostream>
using namespace std;
struct node {
    string data;
    int l, r;
} a[100];
int main() {
    int n, have[100] = {0};
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].data >> a[i].l >> a[i].r;
        if (a[i].l != -1) {
            have[a[i].l] = 1;
        }
        if (a[i].r != -1) {
            have[a[i].r] = 1;
        }
    }
    return 0;
}
