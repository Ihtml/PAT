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
    int id, rid, mid, num, area;
    int cid[10];
}data[1005];

struct node {
    int id, people;
    double num, area;
    bool falg = false;
} ans[N];

int root[N];
bool visit[N];
int main() {
    int n, k, cnt = 0;
    cin >> n;
    for (int i = 0; i < N; i++) {
        root[i] = i;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &data[i].id, &data[i].fid, &data[i].mid, &k);
        visit[data[i].id] = true;
    }
    return 0;
}
