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
int main(){
    int n, k, num;
    string s;
    cin >> n >> k;
    vector<node> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].t >> v[i].value;
    return 0;
}