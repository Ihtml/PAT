/*
提供一棵树，在树根处货物的价格为p，从根结点开始每往下一层，该层货物价格将会在父亲结点的价格上增加r%。
求叶子结点出能获得的最低价格以及能提供最低价格的叶子结点数
*/
#include <iostream>
#include <vector>
using namespace std;
vector<int> v[100005];
int main(){
    int n, k, c;
    double p, r;
    scanf("%d %lf %lf", &n, &p, &r);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &k);
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &c);
            v[i].push_back(c);
        }
        
    }
    
    return 0;
} 