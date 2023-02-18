#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct node {
    int come, time;
} tempcustomer;
bool cmp1(node a, node b){
    return a.come < b.come;
}
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<node> custom;
    for (int i = 0; i < n; i++) {
        int hh, mm, ss, time;
        scanf("%d:%d:%d %d", &hh, &mm, &ss, &time);
        int cometime = hh * 3600 + mm * 60 + ss;
        if (cometime > 61200) // 17*60*60
            continue;
        tempcustomer.come = cometime;
        tempcustomer.time = time * 60;
        custom.push_back(tempcustomer);
    }
    sort(custom.begin(), custom.end(), cmp1);
    return 0;
}