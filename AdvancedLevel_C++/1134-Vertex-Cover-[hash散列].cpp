/*
Q:给n个结点m条边，再给k个集合。对这k个集合逐个进行判断。每个集合S里面的数字都是结点编号
求问整个图所有的m条边两端的结点，是否至少一个结点出自集合S中。如果是，输出Yes否则输出No
A:对于每一个集合做判断，遍历集合中的每一个元素，
将当前元素能够属于的边的编号i对应的hash[i]标记为1，表示这条边是满足有一个结点出自集合S中的。
最后判断hash数组中的每一个值是否都是1，如果有不是1的，说明这条边的两端结点没有一个出自集合S中，则输出No。否则输出Yes
*/

#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m, a, b, k, nv, num;
    cin >> n >> m;
    vector<int> v[n];
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        v[a].push_back(i);
        v[b].push_back(i);
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> nv;
        int flag = 0;
        vector<int> hash(m, 0);
        for (int j = 0; j < nv; j++) {
            cin >> num;
            for (int k = 0; k < v[num].size(); k++) {
                hash[v[num][k]] = 1;
            }
        }
        for (int j = 0; j < m; j++) {
            if (hash[j] == 0) {
                printf("No\n");
                flag = 1;
                break;
            }
        }
    }

    return 0;
}
