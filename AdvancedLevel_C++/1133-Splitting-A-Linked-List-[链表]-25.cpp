#include <iostream>
#include <vector>
using namespace std;

int main() {
    int first, n, k, data[100005], next[100005];

    // 读取输入
    scanf("%d%d%d", &first, &n, &k);
    for (int i = 0; i < n; i++) {
        int idx;
        scanf("%d", &idx);
        scanf("%d%d", &data[idx], &next[idx]);
    }

    // 定义三个链表，分别存放小于0、小于等于k、大于k的节点
    vector<int> v1, v2, v3;

    // 遍历链表，将节点按照规定分配到不同的链表中
    while (first != -1) {
        if (data[first] < 0) {
            v1.push_back(first);
        } else if (data[first] <= k) {
            v2.push_back(first);
        } else {
            v3.push_back(first);
        }
        first = next[first];
    }

    // 合并三个链表，按照规定的顺序
    v1.insert(v1.end(), v2.begin(), v2.end());
    v1.insert(v1.end(), v3.begin(), v3.end());

    // 输出结果
    for (int i = 0; i < v1.size(); i++) {
        if (i == v1.size() - 1) {
            printf("%05d %d -1", v1[i], data[v1[i]]);
        } else {
            printf("%05d %d %05d\n", v1[i], data[v1[i]], v1[i + 1]);
        }
    }

    return 0;
}
