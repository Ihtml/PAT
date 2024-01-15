// 将单链表按块反转
// 遍历A将链表正确顺序记录在链表L中，然后需要重新定义链表长度n
// 因为输入中有无效的假结点信息
#include <iostream>
#include <vector>
using namespace std;
struct node {
    int data, next;
} A[100001];
vector<int> L, ans, E[100001];
int s, n, k, addr, temp, mark, cnt = 0, c = 0;
int main() {
    cin >> s >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> addr >> A[addr].data >> A[addr].next;
    }
    temp = s;
    while (temp != -1) {
        L.push_back(temp);
        temp = A[temp].next;
    }
    n = L.size();
    // 将单链表按k个元素分块，存在二维数组E中
    for (int i = 0; i < n; i++) {
        E[c].push_back(L[i]);
        cnt++;
        if (cnt == k && i != n - 1) {
            cnt = 0;
            c++;
        }
    }
    for (int i = c; i >= 0; i--) {
        for (auto it : E[i]) {
            ans.push_back(it);
        }
    }
    for (int i = 1; i < n; i++) {
        printf("%05d %d %05d\n", ans[i - 1], A[ans[i - 1]].data, ans[i]);
    }
    printf("%05d %d -1", ans.back(), A[ans.back()].data);
    return 0;
}