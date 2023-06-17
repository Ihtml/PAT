/*
题目大意：给一棵树，在树根出货物的价格为p，
从根结点开始每往下走一层，该层的货物价格将会在父亲结点的价格上增加r%，
求所有叶子结点的最高价格，以及这个价格的叶子结点个数。
*/

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int n, maxdepth = 0, maxnum = 0, temp, root;
vector<int> v[100010];
int main() {
    double p, r;
    scanf("%d %lf %lf", &n, &p, &r);  // n-供应商数量 p-根节点价格 r-价格提升比例
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        if (temp == -1) {
            root = 1;
        } else {
            v[temp].push_back(i);
        }
    }
}