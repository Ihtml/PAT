/*
Q:给出一个链表。将链表排序，然后把链表上的结点按照key值从小到大排序（给出的结点有可能不在链表中）
*/
#include <algorithm>
#include <iostream>
using namespace std;
struct NODE {
    int addr, key, next;
    bool flag;
} node[100000];
int main() {
    int n, s, a, b, c, cnt = 0;
    scanf("%d%d", &n, &s);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &a, &b, &c);
        node[a] = {a, b, c, false};
    }
    for (int i = s; i != -1; i = node[i].next) {
        node[i].flag = true;
        cnt++;
    }
    return 0;
}