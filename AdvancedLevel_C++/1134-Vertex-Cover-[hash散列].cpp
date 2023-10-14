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
    
    // 读取输入中的节点数 n 和边数 m
    cin >> n >> m;
    
    // 创建一个名为 v 的 vector 数组，每个元素是一个 vector，用于表示图的邻接列表
    vector<int> v[n];
    
    // 读取边的信息，并将其存储在邻接列表中
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        v[a].push_back(i);
        v[b].push_back(i);
    }
    
    // 读取查询次数 k
    cin >> k;
    
    // 处理每次查询
    for (int i = 0; i < k; i++) {
        cin >> nv; // 读取当前查询中涉及的节点数
        
        int flag = 0; // 用于标记查询结果的标志
        
        // 创建一个 hash 数组，用于记录哪些边已经被覆盖
        vector<int> hash(m, 0);
        
        // 读取当前查询中的节点信息
        for (int j = 0; j < nv; j++) {
            cin >> num; // 读取一个节点
            
            // 遍历节点的边，将对应边在 hash 数组中标记为已覆盖
            for (int k = 0; k < v[num].size(); k++) {
                hash[v[num][k]] = 1;
            }
        }
        
        // 检查是否所有的边都已经被覆盖
        for (int j = 0; j < m; j++) {
            if (hash[j] == 0) {
                printf("No\n"); // 存在未覆盖的边，输出 "No"
                flag = 1;
                break;
            }
        }
        
        // 如果所有边都被覆盖，输出 "Yes"
        if (flag == 0)
            printf("Yes\n");
    }

    return 0;
}
