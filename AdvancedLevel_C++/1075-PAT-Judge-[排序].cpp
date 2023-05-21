#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct node {
    int rank, id, total = 0;
    vector<int> score;
    int passnum = 0;       // 完整通过的题⽬目个数
    bool isshown = false;  // 至少有一题通过
};
bool cmp(node a, node b) {
    if (a.total != b.total) {
        return a.total > b.total;
    } else if (a.passnum != b.passnum) {
        return a.passnum > b.passnum;
    } else {
        return a.id < b.id;
    }
}
int main() {
    int n, k, m, id, num, score;
    scanf("%d %d %d", &n, &k, &m);
    vector<node> v(n + 1);
    for (int i = 1; i <= n; i++) {
        v[i].score.resize(k + 1, -1);
    }
    vector<int> full(k + 1);
    for (int i = 1; i <= k; i++) {
        scanf("%d", &full[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &id, &num, &score);
        v[id].id = id;
        v[id].score[num] = max(v[id].score[num], score);
        if (score != -1) {
            v[id].isshown = true;
        } else if (v[id].score[num] == -1) {
            v[id].score[num] = -2;  // 编译都没通过
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (v[i].score[j] != -1 && v[i].score[j] != -2) {
                v[i].total += v[i].score[j];
            }
            if (v[i].score[j] == full[j]) {
                v[i].passnum++;
            }
        }
    }
    sort(v.begin() + 1, v.end(), cmp);

    return 0;
}
