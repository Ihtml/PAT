#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct node {
    int come, time;
} tempcustomer;
bool cmp1(node a, node b) {
    return a.come < b.come;
}
int main() {
    int n, k;  // n个客户 k个窗口
    scanf("%d%d", &n, &k);
    vector<node> custom;  // 提供服务的顾客
    for (int i = 0; i < n; i++) {
        int hh, mm, ss, time;
        scanf("%d:%d:%d %d", &hh, &mm, &ss, &time);
        int cometime = hh * 3600 + mm * 60 + ss;
        if (cometime > 61200)  // 17*60*60 下午5点以后到达
            continue;
        tempcustomer.come = cometime;
        tempcustomer.time = time * 60;
        custom.push_back(tempcustomer);
    }
    sort(custom.begin(), custom.end(), cmp1);  // 黄线外只有一个队伍，先来先服务
    vector<int> window(k, 28800);  // 28800 = 8*60*60
    double result = 0.0;
    for (int i = 0; i < custom.size(); i++) {
        int tempindex = 0, minfinish = window[0];
        for (int j = 1; j < k; j++) {  // k个窗口
            if (window[j] < minfinish) {
                minfinish = window[j];
                tempindex = j;
            }
        }
        if (window[tempindex] <= custom[i].come) {  // 不需要等
            window[tempindex] = custom[i].come + custom[i].time;
        } else {
            result += (window[tempindex] - custom[i].come);  // 累积等待时间
            window[tempindex] += custom[i].time;
        }
    }
    if (custom.size() == 0) {
        printf("0.0");
    } else {
        printf("%0.1f", result / 60.0 / custom.size());
    }
    return 0;
}