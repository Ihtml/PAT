#include <iostream>
#include <vector>
using namespace std;
struct node {
    int next;
    int data;
} LinkList[100001];

int main() {
    int first, n, k, addr, t, cnt = 0, c = 0;
    vector<int> L, ans, E[100001];  
    cin >> first >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> addr;
        cin >> LinkList[addr].data >> LinkList[addr].next;
    }
    t = first;
    while (t != -1) {  // 去除无效结点信息
        L.push_back(t);
        t = LinkList[t].next;
    }
    n = L.size();  // 得到有效链表长度
    for (int i = 0; i < n; i++) {
        E[c].push_back(L[i]);  // 二维数组E为区块链表
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
        printf("%05d %d %05d\n", ans[i - 1], LinkList[ans[i - 1]].data, ans[i]);
    }
    printf("%05d %d -1", ans.back(), LinkList[ans.back()].data);
    return 0;
}