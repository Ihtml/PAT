#include <limits.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int inf = INT_MAX;
struct station {
    double price, dis;
};
bool cmp1(station a, station b) {
    return a.dis < b.dis;
}
int main() {
    double cmax, d, davg;
    int n;
    // cmax:邮箱最大容量 d:起点到目的地距离
    // davg:平均每单位油的行驶距离 n:汽车的站点数量
    scanf("%lf%lf%lf%d", &cmax, &d, &davg, &n);
    vector<station> sta(n + 1);
    sta[0] = {0.0, d};
    for (int i = 1; i <= n; i++) {
        scanf("%lf%lf", &sta[i].price, &sta[i].dis);
    }
    sort(sta.begin(), sta.end(), cmp1);
    return 0;
}