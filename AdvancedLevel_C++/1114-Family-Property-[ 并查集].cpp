/*
Q:给定每个人的家庭成员和其自己名下的房产，请你统计出每个家庭的人口数、人均房产面积及房产套数。
首先在第一行输出家庭个数（所有有亲属关系的人都属于同一个家庭）
随后按下列格式输出每个家庭的信息：家庭成员的最小编号
家庭人口数人均房产套数人均房产面积。
人均值要求保留小数点后3位。家庭信息首先按人均面积降序输出，若有并列，则按成员编号的升序输出。
*/
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 10000;
struct DATA {
    int id, fid, mid, num, area;
    int cid[10];
} pdata[1005];

struct node {
    int id, people;
    double num, area;
    bool flag = false;
} ans[N];

int root[N];
bool visit[N];
int find(int x) {
    while (x != root[x]) {
        x = root[x];
    }
    return x;
}
void Union(int a, int b) {
    int faA = find(a);
    int faB = find(b);
    if (faA > faB) {
        root[faA] = faB;
    } else if (faA < faB) {
        root[faB] = faA;
    }
}
void cmp1(node a, node b) {
    if (a.area != b.area) {
        return a.area > b.area;
    } else {
        return a.id < b.id;
    }
}
int main() {
    int n, k, cnt = 0;
    cin >> n;
    for (int i = 0; i < N; i++) {
        root[i] = i;
    }
    for (int i = 0; i < n; i++) {
        // pdata[i].id: 当前人的ID
        // pdata[i].fid: 当前人的父亲的ID
        // pdata[i].mid: 当前人的母亲的ID
        // k: 当前人的子女数量（孩子的个数）
        scanf("%d %d %d %d", &pdata[i].id, &pdata[i].fid, &pdata[i].mid, &k);
        visit[pdata[i].id] = true;
        if (pdata[i].fid != -1) {
            visit[pdata[i].fid] = true;
            Union(pdata[i].fid, pdata[i].id);
        }
        if (pdata[i].mid != -1) {
            visit[pdata[i].mid] = true;
            Union(pdata[i].mid, pdata[i].id);
        }
        for (int j = 0; j < k; j++) {
            scanf("%d", &pdata[i].cid[j]);
            visit[pdata[i].cid[j]] = true;
            Union(pdata[i].cid[j], pdata[i].id);
        }
        scanf("%d %d", &pdata[i].num, &pdata[i].area);
        for (int i = 0; i < n; i++) {
            int id = find(pdata[i].id);
            ans[id].id = id;
            ans[id].num += pdata[i].num;
            ans[id].area += pdata[i].area;
            ans[id].flag = true;
        }
        for (int i = 0; i < 10000; i++) {
            if (visit[i]) {
                ans[find(i)].people++;
            }
            if (ans[i].flag) {
                cnt++;
            }
        }
        for (int i = 0; i < 10000; i++) {
            if (ans[i].flag) {
                ans[i].num = (double)(ans[i].num * 1.0 / ans[i].people);
                ans[i].area = (double)(ans[i].area * 1.0 / ans[i].people);
            }
        }
        sort(ans, ans + 10000, cmp1);
        printf("%d\n", cnt);
        for (int i = 0; i < cnt; i++)
            printf("%04d %d %.3f %.3f\n", ans[i].id, ans[i].people, ans[i].num,
                   ans[i].area);
    }
    return 0;
}
