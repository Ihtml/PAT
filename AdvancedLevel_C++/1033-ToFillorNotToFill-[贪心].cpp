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
    station a = {0.0, d};
    sta[0] = a;
    for (int i = 1; i <= n; i++) {
        scanf("%lf%lf", &sta[i].price, &sta[i].dis);
    }
    sort(sta.begin(), sta.end(), cmp1);
    double nowdis = 0.0, maxdis = 0.0, nowprice = 0.0, totalPrice = 0.0,
           leftdis = 0.0;
    if (sta[0].dis != 0) {
        printf("The maximum travel distance = 0.00");
        return 0;  // 这里必须要return 0；否则会继续往下执行
    } else {
        nowprice = sta[0].price;
    }
    while (nowdis < d) {
        maxdis = nowdis + cmax * davg;
        double minPriceDis = 0, minPrice = inf;
        int flag = 0;
        for (int i = 1; i <= n && sta[i].dis <= maxdis; i++) {
            if (sta[i].dis <= nowdis) {  // 已经通过的点
                continue;
            }
            if (sta[i].price < nowprice) {  // maxdis距离内有比当前站价格低的站
                totalPrice += (sta[i].dis - nowdis - leftdis) * nowprice / davg;
                leftdis = 0.0;
                nowprice = sta[i].price;
                nowdis = sta[i].dis;
                flag = 1;
                break;
            }
            if (sta[i].price < minPrice) {  // 寻找下一个maxdis距离内最便宜的站
                minPrice = sta[i].price;
                minPriceDis = sta[i].dis;
            }
        }
        if (flag == 0 && minPrice != inf) {  // maxdis距离内没有比当前站价格更低的站
            totalPrice += (nowprice * (cmax - leftdis / davg));  // 带低价油过去
            leftdis = cmax * davg - (minPriceDis - nowdis);  // 到站还剩的低价油可以走的距离
            nowprice = minPrice;
            nowdis = minPriceDis;
        }
        if (flag == 0 && minPrice == inf) {  // sta[i].dis > maxdis
            nowdis += cmax * davg;
            printf("The maximum travel distance = %.2f", nowdis);
            return 0;
        }
    }
    printf("%.2f", totalPrice);
    return 0;
}