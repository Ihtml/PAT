#include <iostream>
#include <vector>
using namespace std;
struct person {
    int arrive, start, time;
    bool vip;
} tempperson;
struct tablenode {
    int end = 8 * 3600, num;
    bool vip;
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
int alloctable(int personid, int tableid) {
    if (player[personid].arrive <= table[tableid].end) {
        player[personid].start = table[tableid].end;
    } else {
        player[personid].start = player[personid].arrive;
    }
    table[tableid].end = player[personid].start + player[personid].time;
    table[tableid].num++;
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
        tempperson.time = temptime < 120 ? temptime * 60 : 7200;
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
        if (table[index].end >= 21 * 3600) {  // 最早的结束时间都大于21点
            break;
        }
        if (player[i].vip == true && i < vipid) {
            i++;
            continue;
        }
        if (table[index].vip == true) {
            if (player[i].vip = true) {
                alloctable(i, index);
                if (vipid == i)
                    vipid = findnextvip(vipid);
                i++;
            } else {
            }
        } else {
            /* code */
        }
    }
    return 0;
}