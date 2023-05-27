/*
题目大意：给一棵树，在树根出货物的价格为p，
从根结点开始每往下走一层，该层的货物价格将会在父亲结点的价格上增加r%，
给出每个叶结点的货物量，求他们的价格之和
*/
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
struct node {
    double data;
    vector<int> child;
};
vector<node> v;
double ans = 0.0, p, r;
int main() {
    int n, k, c;
    scanf("%d %lf %lf", &n, &p, &r);
    r = r / 100;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        if (k == 0) {
            scanf("%lf", &v[i].data);
        } else {
            for (int j = 0; j < k; j++) {
                scanf("%d", &c);
                v[i].child.push_back(c);
            }
        }
    }
    printf("%.1f", ans * p);
    return 0;
}