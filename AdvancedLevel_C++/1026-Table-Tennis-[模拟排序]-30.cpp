#include <iostream>
#include <vector>
using namespace std;
struct person {
    int arrive, start, time;
    bool vip;
} tempperson;
bool cmp1(person a, person b) {
    return a.arrive < b.arrive;
}
vector<person> player;
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
    return 0;
}