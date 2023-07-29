/*有n个人，每个人喜欢k个活动，如果两个人有任意一个活动相同，就称为他们处于同一个社交网络。
求这n个人一共形成了多少个社交网络*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> father, isRoot;
int main() {
    int n, k, t, cnt = 0;
    // course[t]是喜欢t活动的人的编号
    int course[100] = {0};
    scanf("%d", n);
    father.resize(n + 1);
    father.resize(n + 1);
    for (int i = 0; i <= n; i++) {
        father[i] = i;
    }

    return 0;
}