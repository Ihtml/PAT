/*
np为老鼠的数量，ng为每组最多g个老鼠。先给出np个老鼠的重量，再给出老鼠的初始顺序(第i名的老鼠是第j号，j从0开始)。
每ng个老鼠分为一组，对于每组老鼠，选出最重的那个，晋级下一轮比赛，然后依次再以np个老鼠一组分类，然后选出重量最大的，直到只剩下一只老鼠，排名为1。
输出为老鼠的排名，这个排名是按照原输入老鼠的顺序输出的
*/
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct node {
    int weight, index, rank, index0;
};
bool cmp(node a, node b) {
    return a.index0 < b.index0;
}
int main() {
    int n, g, num;
    scanf("%d%d", &n, &g);
    vector<int> v(n);
    vector<node> w(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);  // weight
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        w[i].weight = v[num];
        w[i].index = i; 
        w[i].index0 = num;  // 比赛顺序
    }

    return 0;
}