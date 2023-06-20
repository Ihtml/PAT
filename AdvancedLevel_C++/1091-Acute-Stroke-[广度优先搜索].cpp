/*
Q:给定一个三维数组，0表示正常1表示有肿瘤，肿瘤块的大小大于等于t才算作是肿瘤，让计算所有满足肿瘤块的大小
A:三维的广度优先搜索～XYZ三个数组判断方向，对每一个点广度优先累计肿瘤块的大小，如果大于等于t就把结果累加。
用visit数组标记当前的点有没有被访问过，被访问过的结点是不会再访问的。
judge判断是否超过了边界，或者是否当前结点为0不是肿瘤
*/
#include <cstdio>
#include <queue>
using namespace std;
struct node {
    int x, y, z;
};
int m, n, l, t;
int arr[1300][130][80];
int main() {
    scanf("%d %d %d %d", &m, &n, &l, &t);
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                scanf("%d", &arr[j][k][i]);
            }
        }
    }
    int ans = 0;
}