/*
Q:给出一个链表。将链表排序，然后把链表上的结点按照key值从小到大排序（给出的结点有可能不在链表中）
A:建立结构体数组，按照从首地址开始的顺序(直到-1)遍历一遍整个链表，将在链表中的结点
的flag标记为true，并且统计cnt(有效结点的个数)。(因为有的结点根本不在链表中)
然后将链表进行排序，如果flag == false就把他们移动到后面(即:reuturn a.flag>
b.flag),最后只输出前cnt个链表的信息
*/
#include <algorithm>
#include <iostream>
using namespace std;
struct NODE {
    int addr, key, next;
    bool flag;
} node[100000];
int cmp(NODE a, NODE b) {
    return (!a.flag || !b.flag) ? a.flag > b.flag : a.key < b.key;
}
int main() {
    int n, s, addr, key, next, cnt = 0;
    scanf("%d%d", &n, &s);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &addr, &key, &next);
        NODE a = {addr, key, next, false};
        node[addr] = a;
    }
    for (int i = s; i != -1; i = node[i].next) {
        node[i].flag = true;
        cnt++;
    }
    if (cnt == 0) {
        printf("0 -1");
    } else {
        sort(node, node + 100000, cmp);
        printf("%d %05d\n", cnt, node[0].addr);
        for (int i = 0; i < cnt; i++) {
            printf("%05d %d ", node[i].addr, node[i].key);
            if (i != cnt - 1) {
                printf("%05d\n", node[i + 1].addr);
            } else {
                printf("-1\n");
            }
        }
    }
    return 0;
}