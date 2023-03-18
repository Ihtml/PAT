#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
struct person {
    int arrive, start, time;
    bool vip;
} tempperson;
struct tablenode {
    int end = 8 * 3600, num;
    bool vip = 0;
};

bool cmp1(person a, person b) {
    return a.arrive < b.arrive;
}
bool cmp2(person a, person b) {
    return a.start < b.start;
}
vector<tablenode> table;
vector<person> player;
int findnextvip(int vipid) {
    vipid++;
    while (vipid < player.size() && player[vipid].vip == false) {
        vipid++;
    }
    return vipid;
}
void alloctable(int personid, int tableid) {
    if (player[personid].arrive <= table[tableid].end) {
        player[personid].start = table[tableid].end;
    } else {
        player[personid].start = player[personid].arrive;
    }
    table[tableid].end = player[personid].start + player[personid].time;
    table[tableid].num++;
    // cout << personid + 1 << endl;
}
int main() {
    int n, k, m, viptable;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int h, m, s, temptime, flag;
        scanf("%d:%d:%d %d %d", &h, &m, &s, &temptime, &flag);
        tempperson.arrive = h * 3600 + m * 60 + s;
        tempperson.start = 21 * 3600;
        if (tempperson.arrive >= 21 * 3600) {
            continue;
        }
        tempperson.time = temptime <= 120 ? temptime * 60 : 7200;
        tempperson.vip = ((flag == 1) ? true : false);
        player.push_back(tempperson);
    }
    sort(player.begin(), player.end(), cmp1);
    scanf("%d%d", &k, &m);
    table.resize(k + 1);
    for (int i = 0; i < m; i++) {
        scanf("%d", &viptable);
        table[viptable].vip = true;
    }
    int i = 0, vipid = -1;
    vipid = findnextvip(vipid);
    while (i < player.size()) {
        int index = -1, minendtime = 999999999;
        for (int j = 1; j <= k; j++) {
            if (table[j].end < minendtime) {
                minendtime = table[j].end;
                index = j;
            }
        }
        if (minendtime < player[i].arrive) {  // 修正：在人来之前有多个桌子空，选序号最小的
            for (int j = 1; j <= k; j++) {
                if (table[j].end < player[i].arrive) {
                    index = j;
                    break;
                }
            }
        }
        if (table[index].end >= 21 * 3600) {  // 最早的结束时间都大于21点
            break;
        }
        if (player[i].vip == true && i < vipid) {  // 已经使用过VIP桌特权的客户
            i++;
            continue;
        }
        if (table[index].vip == true) {  // vip桌
            // cout << "viptable:" << index;
            if (player[i].vip == true) {  // 排队的第一个是VIP客户
                alloctable(i, index);

                if (vipid == i) {
                    vipid = findnextvip(vipid);
                }
                i++;
            } else {  //  排队的第一个是普通客户
                if (vipid < player.size() &&
                    player[vipid].arrive <=
                        table[index].end) {  //  vip客户在队列中
                    alloctable(vipid, index);

                    vipid = findnextvip(vipid);
                } else {
                    alloctable(i, index);
                    i++;
                }
            }
        } else {                           // 普通桌
            if (player[i].vip == false) {  // 排队队首是普通客户
                // cout << "table:" << index;
                alloctable(i, index);
                i++;
            } else {  // 排队队首是VIP客户
                int vipindex = -1, minvipendtime = 999999999;
                for (int j = 1; j <= k; j++) {
                    if (table[j].vip == true && table[j].end < minvipendtime) {
                        minvipendtime = table[j].end;
                        vipindex = j;
                    }
                }
                if (vipindex != -1 && player[i].arrive >= table[vipindex].end) {
                    // cout << "tablevip:" << vipindex;
                    alloctable(
                        i, vipindex);  // 该VIP客户到达时，又有VIP桌子空出来了
                    if (vipid == i) {
                        vipid = findnextvip(vipid);
                    }
                    i++;

                } else {
                    // cout << "table:" << index;
                    alloctable(i, index);
                    if (vipid == i) {
                        vipid = findnextvip(vipid);
                    }
                    i++;
                }
            }
        }
    }
    sort(player.begin(), player.end(), cmp2);
    for (int i = 0; i < player.size() && player[i].start < 21 * 3600; i++) {
        printf("%02d:%02d:%02d ", player[i].arrive / 3600,
               player[i].arrive % 3600 / 60, player[i].arrive % 60);
        printf("%02d:%02d:%02d ", player[i].start / 3600,
               player[i].start % 3600 / 60, player[i].start % 60);
        printf("%d\n", (player[i].start - player[i].arrive + 30) / 60);
    }
    for (int i = 1; i <= k; i++) {
        if (i != 1) {
            printf(" ");
        }
        printf("%d", table[i].num);
    }
    return 0;
}