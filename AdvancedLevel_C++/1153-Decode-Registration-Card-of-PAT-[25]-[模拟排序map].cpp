/* 给出一组学生的准考证号和成绩，准考证号包含了等级(
    乙甲顶)，考场号，日期，和个人编号信息，并有三种查询方式
    查询一：给出考试等级，找出该等级的考生，按照成绩降序，准考证升序排序
    查询二：给出考场号，统计该考场的考生数量和总得分
    查询三：给出考试日期，查询改日期下所有考场的考试人数，按照人数降序，考场号升序排序
    */
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
struct node {
    string t;
    int value;
};
bool cmp(const node& a, const node& b) {
    return a.value != b.value ? a.value > b.value : a.t < b.t;
}
int main() {
    int n, k, num;
    string s;
    cin >> n >> k;
    vector<node> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].t >> v[i].value;
    for (int i = 1; i <= k; i++) {
        cin >> num >> s;
        printf("Case %d: %d %s\n", i, num, s.c_str());
        vector<node> ans;
        int cnt = 0, sum = 0;
        if (num == 1) {
            for (int j = 0; j < n; j++)
                if (v[j].t[0] == s[0])
                    ans.push_back(v[j]);
        } else if (num == 2) {
            for (int j = 0; j < n; j++) {
                if (v[j].t.substr(1, 3) == s) {
                    cnt++;
                    sum += v[j].value;
                }
            }
            if (cnt != 0)
                printf("%d %d\n", cnt, sum);
        } else if (num == 3) {
            unordered_map<string, int> m;
            for (int j = 0; j < n; j++)
                if (v[j].t.substr(4, 6) == s)
                    m[v[j].t.substr(1, 3)]++;
            for (auto it : m)
                ans.push_back({it.first, it.second});
        }
        sort(ans.begin(), ans.end(), cmp);
        for (int j = 0; j < ans.size(); j++)
            printf("%s %d\n", ans[j].t.c_str(), ans[j].value);
        if (((num == 1 || num == 3) && ans.size() == 0) ||
            (num == 2 && cnt == 0))
            printf("NA\n");
    }

    return 0;
}