#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct peo {
    int id, ge, gi, fin;  // 学生的ID、GE分数、GI分数、总分
    vector<int> choice;   // 学生的志愿选择
};

// 根据总分和GE分数进行排序的比较函数
bool cmp(peo& a, peo& b) {
    if (a.fin != b.fin) {
        return a.fin > b.fin;  // 总分降序排列
    }
    return a.ge > b.ge;  // GE分数降序排列
}

// 根据学生ID进行排序的比较函数
bool cmp2(peo& a, peo& b) {
    return a.id < b.id;
}

int main() {
    int n, m, k, quota[105];  // n-申请学生总数 m-学校数量 k-学生志愿数
    scanf("%d%d%d", &n, &m, &k);
    int cnt[110] = {0};  // 记录每个学校录取的学生数量，所有元素初始化为0
    vector<peo> stu(n), sch[105];
    for (int i = 0; i < m; i++) {
        scanf("%d", &quota[i]);
    }
    // 输入每个学生的信息
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &stu[i].ge, &stu[i].gi);
        stu[i].id = i;                       // 设置学生的ID为输入顺序
        stu[i].fin = stu[i].ge + stu[i].gi;  // 计算学生的总分
        stu[i].choice.resize(k);  // 调整学生志愿选择的大小为k
        for (int j = 0; j < k; j++) {
            scanf("%d", &stu[i].choice[j]);  // 输入学生的志愿选择
        }
    }
    sort(stu.begin(), stu.end(), cmp);  // 根据总分和GE分数排序学生
    // 根据学生的志愿选择进行录取
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            int schid = stu[i].choice[j];  // 获取当前志愿选择的学校ID
            int lastindex =
                cnt[schid] - 1;  // 获取当前学校已录取学生的最后一个索引

            // 如果当前学校的招生名额还未满，或者当前学生与最后一个录取学生的总分和GE分数相同
            if (cnt[schid] < quota[schid] ||
                (stu[i].fin == sch[schid][lastindex].fin &&
                 stu[i].ge == sch[schid][lastindex].ge)) {
                sch[schid].push_back(stu[i]);  // 录取该学生
                cnt[schid]++;  // 增加当前学校的录取人数
                break;         // 跳出当前学生的志愿选择循环
            }
        }
    }
    // 输出每个学校的录取名单
    for (int i = 0; i < m; i++) {
        sort(sch[i].begin(), sch[i].end(), cmp2);  // 根据学生ID排序录取名单
        for (int j = 0; j < cnt[i]; j++) {
            if (j != 0) {
                printf(" ");  // 输出空格分隔符（除了第一个学生）
            }
            printf("%d", sch[i][j].id);  // 输出学生的ID
        }
        printf("\n");  // 输出换行符，表示当前学校的录取名单结束
    }
    return 0;
}