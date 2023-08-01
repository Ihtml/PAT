/*有n个人，每个人喜欢k个活动，如果两个人有任意一个活动相同，就称为他们处于同一个社交网络。
求这n个人一共形成了多少个社交网络*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> father, isRoot;
int findFather(int x) {
    int a = x;
    while (x != father[x])
        x = father[x];
    while (a != father[a]) {
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}
void Union(int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if (faA != faB)
        father[faA] = faB;
}
int main() {
    int n, k, t, cnt = 0;
    // course[t]是喜欢t活动的人的编号
    int course[100] = {0};
    scanf("%d", n);
    father.resize(n + 1);
    isRoot.resize(n + 1);
    for (int i = 0; i <= n; i++) {
        father[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d:", &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &t);
            if (course[t] == 0)
                course[t] = i;
            Union(i, findFather(course[t]));
        }
    }
    return 0;
}