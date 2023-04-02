/*
Q:给出两个数字序列，从这两个序列中分别选取相同数量的元素进行⼀对一相乘，问能得到
的乘积之和最大为多少
A:把这两个序列列都从⼩到⼤排序，将前⾯都是负数的数相乘求和，然后将后⾯都是正数的数相乘
求和
*/
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int main() {
    int n, m, ans = 0, p = 0, q = 0;
    scanf("%d", &m);
    vector<int> v1(m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &v1[i]);
    }
    scanf("%d", &n);
    vector<int> v2(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v2[i]);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    // TODO
    return 0;
}