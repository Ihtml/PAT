/*
给出n个车牌号、时间点、进出状态的记录，然后查询k个时间点这时校园内的车辆个数。
最后还要输出在校园里面呆的时间最长的车的车牌号，以及呆了多久的时间。
如果有多辆车就按照它的字母从小到大输出车牌。
*/
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
struct node {
    char id[10];
    int time, flag = 0;
};

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<node> record(n), car;
    for (int i = 0; i < n; i++) {
        char temp[5];
        int h, m, s;
        scanf("%s %d:%d:%d %s\n", record[i].id, &h, &m, &s, temp);
        int temptime = h * 3600 + m * 60 + s;
        record[i].time = temptime;
        record[i].flag = (temp == "in" ? 1 : -1);
    }

    return 0;
}