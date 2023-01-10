#include <iostream>
#include <vector>
using namespace std;
struct node {
    int data, next;
} A[100000];
vector<int> L1, L2, ans;  // L1 L2 保存链表的顺序

int main() {
    int sa, sb, p1, p2, N, addr;
    cin >> sa >> sb >> N;
    for (int i = 0; i < N; i++) {
        cin >> addr >> A[addr].data >> A[addr].next;
    }
    p1 = sa;
    p2 = sb;
    while (p1 != -1) {
        L1.push_back(p1);
        p1 = A[p1].next;
    }
    while (p2 != -1) {
        L2.push_back(p2);
        p2 = A[p2].next;
    }
    if (L1.size() < L2.size()) {
        swap(L1, L2);
    }
    for (int i = 0, c = L2.size() - 1; i < L1.size(); i++) {
        ans.push_back(L1[i]);
        if (i & 1 && c >= 0) {
            ans.push_back(L2[c--]);
        }
    }
    for (int i = 0; i < ans.size() - 1; i++) {
        printf("%05d %d %05d\n", ans[i], A[ans[i]].data, ans[i + 1]);
    }
    printf("%05d %d -1", ans.back(), A[ans.back()].data);
    return 0;
}