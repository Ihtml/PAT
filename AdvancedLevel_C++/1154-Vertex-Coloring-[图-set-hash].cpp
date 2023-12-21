/*
Q:给出一个图（先给出所有边，后给出每个点的颜色），
问是否满足：所有的边的两个点的颜色不相同
A:把所有边存起来，把所有点的颜色存起来（存的过程中放入set统计颜色个数），
枚举所有边检查是否每条边的两点个颜色是否相同，若全不相同，则输出颜色个数，否则输出No
*/
#include <iostream>
#include <set>
#include <vector>
using namespace std;
struct node {
    int t1, t2;
};
int main() {
    int n, m, k;
    cin >> n >> m;
    vector<node> v(m);
    for (int i = 0; i < m; i++)
        scanf("%d %d", &v[i].t1, &v[i].t2);
    cin >> k;
    while (k--) {
        int a[10009] = {0};
        bool flag = true;
        set<int> se;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            se.insert(a[i]);
        }
        for (int i = 0; i < m; i++) {
            if (a[v[i].t1] == a[v[i].t2]) {
                flag = false;
                break;
            }
        }
    }
    
    return 0;
}