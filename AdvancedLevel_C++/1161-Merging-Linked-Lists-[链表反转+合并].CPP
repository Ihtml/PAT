// 将较短的链表逆序，合并到较长的链表上
#include <iostream>
#include <vector>
using namespace std;
struct node {
    int data, next;
} A[100000];
vector<int> L1, L2, ans;
int sa, sb, n, a, ta, tb, c;
int main() {
    cin >> sa >> sb >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> A[a].data >> A[a].next;
    }
    ta = sa;
    while (ta != -1) {
        L1.push_back(ta);
        ta = A[ta].next;
    }
    tb = sb;
    while (tb != -1) {
        L2.push_back(tb);
        tb = A[tb].next;
    }
    if (L1.size() < L2.size())
        // swap交换的是两个容器的内部指针和大小等信息，而不是逐个元素地复制
        swap(L1, L2);
    // L1是长链表 L2是短链表
    for (int i = 0, c = L2.size() - 1; i < L1.size(); i++) {
        ans.push_back(L1[i]);
        if ((i % 2 == 1) && c >= 0) {
            ans.push_back(L2[c--]);
        }
    }
    for (int i = 1; i < ans.size(); i++) {
        printf("%05d %d %05d\n", ans[i - 1], A[ans[i - 1]].data, ans[i]);
    }
    printf("%05d %d -1", ans.back(), A[ans.back()].data);
    return 0;
}