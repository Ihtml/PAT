#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct peo {
    int id, ge, gi, fin;
    vector<int> choice;
};

int main() {
    int n, m, k, quota[105];  // n-申请学生总数 m-学校数量 k-学生志愿数
    scanf("%d%d%d", &n, &m, &k);
    int cnt[110] = {0};  // 所有元素初始化为0
    vector<peo> stu(n), sch[105];
    for (int i = 0; i < m; i++) {
        scanf("%d", &quota[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &stu[i].ge, &stu[i].gi);
        stu[i].id = i;
        stu[i].fin = stu[i].ge + stu[i].gi;
        stu[i].choice.resize(k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &stu[i].choice[j]);
        }
    }

    return 0;
}