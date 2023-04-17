/*
Q:给出n个正整数和一个正整数m，问n个数字中是否存在⼀对数字a和b(a <=
b),使a+b=m成立。如果有多个，输出a最⼩的那一对。
A: 建⽴数组a保存每个数字出现的次数，然后判断输出
*/
#include <iostream>
int a[1001];
using namespace std;
int main() {
    int n, m, temp;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        a[temp]++;
    }
    for (int i = 0; i < 1001; i++) {
        if (a[i]) {
            a[i]--;
            if (i < m && a[m - i]) {
                cout << i << " " << m - i;
                return 0;
            }
            a[i]++;
        }
    }
    cout << "No Solution";
    return 0;
}