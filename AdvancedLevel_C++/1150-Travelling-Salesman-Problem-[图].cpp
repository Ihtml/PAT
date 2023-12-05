/*给出一条路径，判断这条路径是这个图的旅行商环路、简单旅行商环路还是非旅行商环路*/
// 如果给出的路径存在某两个连续的点不可达,或者第一个结点和最后一个结点不同,
// 或者这个路径没有访问过图中所有的点，它就不是一个旅行商环路(flag = 0)
#include <iostream>
#include <set>
#include <vector>
using namespace std;
int e[300][300], n, m, k, ans = 99999999, ansid;
vector<int> v;
void check(int index) {
    int sum = 0, cnt, flag = 1;
    scanf("%d", &cnt);
    set<int> s;
    vector<int> v(cnt);
    for (int i = 0; i < cnt; i++) {
        scanf("%d", &v[i]);
        s.insert(v[i]);
    }
    for (int i = 0; i < cnt - 1; i++) {
        if (e[v[i]][v[i + 1]] == 0)
            flag = 0;
        sum += e[v[i]][v[i + 1]];
    }
    if (flag == 0) {
        printf("Path %d: NA (Not a TS cycle)\n", index);
    } else if (v[0] != v[cnt - 1] || s.size() != n) {
        printf("Path %d: %d (Not a TS cycle)\n", index, sum);
    } else if (cnt != n + 1) {
        printf("Path %d: %d (TS cycle)\n", index, sum);
        if (sum < ans) {
            ans = sum;
            ansid = index;
        }
    } else {
        printf("Path %d: %d (TS simple cycle)\n", index, sum);
        if (sum < ans) {
            ans = sum;
            ansid = index;
        }
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int t1, t2, t;
        scanf("%d%d%d", &t1, &t2, &t);
        e[t1][t2] = e[t2][t1] = t;
    }
    scanf("%d", &k);
    for (int i = 1; i <= k; i++)
        check(i);
    printf("Shortest Dist(%d) = %d\n", ansid, ans);
    return 0;
}