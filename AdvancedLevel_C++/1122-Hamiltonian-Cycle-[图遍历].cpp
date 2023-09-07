/*给出一个图，判断给定的路径是不是包含了图所有顶点的环*/
#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main() {
    int n, m, cnt, k, a[210][210] = {0};
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        a[t1][t2] = a[t2][t1] = 1;
    }
    cin >> cnt;
    while (cnt--) {
        cin >> k;
        vector<int> v(k);
        set<int> s;
        int flag1 = 1, flag2 = 1;
        for (int i = 0; i < k; i++) {
            cin >> v[i];
            s.insert(v[i]);
        }
    }

    return 0;
}
