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
bool cmp1(node a, node b) {
    if (strcmp(a.id, b.id) != 0) {
        return strcmp(a.id, b.id) < 0;
    } else {
        return a.time < b.time;
    }
}
bool cmp2(node a, node b) {
    return a.time < b.time;
}
int main() {
    int n, k, maxtime = -1;
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
    sort(record.begin(), record.end(), cmp1);
    map<string, int> mapp;
    for (int i = 0; i < n - 1; i++) {
        if (strcmp(record[i].id, record[i + 1].id) == 0 &&
            record[i].flag == 1 && record[i + 1].flag == -1) {
            car.push_back(record[i]);
            car.push_back(record[i + 1]);
            mapp[record[i].id] += (record[i + 1].time - record[i].time);
            if (maxtime < mapp[record[i].id]) {
                maxtime = mapp[record[i].id];
            }
        }
    }
    sort(car.begin(), car.end(), cmp2);  // car按时间排序
    vector<int> cnt(n);
    // cnt[i]表示在i下标的记录的时间点的时候车辆的数量。数量可以由前一个数量+当前车辆的flag得到。
    for (int i = 0; i < car.size(); i++) {
        if (i == 0) {
            cnt[i] += car[i].flag;
        } else {
            cnt[i] = cnt[i - 1] + car[i].flag;
        }
    }
    for (int i = 0; i < k; i++) {
        int h, m, s;
        scanf("%d:%d:%d", &h, &m, &s);
        int temptime = h * 3600 + m * 60 + s;
        int j, tempindex = 0;
        for (j = tempindex; j < car.size(); i++) {
            if (car[j].time > temptime) {
                printf("%d\n", cnt[j - 1]);
                break;
            } else if (j = car.size() - 1) {
                printf("%d\n", cnt[j]);
            }
        }
        tempindex = j;
    }
    for (auto it = mapp.begin(); it != mapp.end(); it++) {
        if (it->second == maxtime) {
            printf("%s ", it->first.c_str());
        }
    }
    printf("%02d:%02d:%02d", maxtime / 3600, (maxtime % 3600) / 60, maxtime % 60);
    return 0;
}