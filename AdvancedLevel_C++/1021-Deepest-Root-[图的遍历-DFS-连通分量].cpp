#include <iostream>
#include <set>
#include <vector>
using namespace std;

int n, maxheight = 0;    // n为节点数，maxheight为最大高度
vector<vector<int> > v;  // 图的邻接表存储结构
bool visit[10010];       // 标记节点是否被访问过
set<int> s;              // 存储最深的根节点编号
vector<int> temp;        // 临时存储最深的根节点

void dfs(int node, int height) {  // 深度优先搜索
    if (height > maxheight) {     // 更新最大高度
        temp.clear();             // 清空当前最深的根节点
        temp.push_back(node);     // 将当前节点加入最深的根节点中
        maxheight = height;       // 更新最大高度
    } else if (height == maxheight) {  // 如果和最大高度相等
        temp.push_back(node);  // 将当前节点加入最深的根节点中
    }
    visit[node] = true;  // 标记当前节点已经被访问过
    for (int i = 0; i < v[node].size(); i++) {  // 遍历当前节点的邻居节点
        if (visit[v[node][i]] == false) {  // 如果邻居节点没有被访问过
            dfs(v[node][i], height + 1);  // 递归访问邻居节点
        }
    }
}

int main() {
    // 读入节点数n
    scanf("%d", &n);
    // 初始化图v的大小为n+1，存储节点的连通情况
    v.resize(n + 1);
    // 初始化节点a、b、连通块数量cnt和起始点s1
    int a, b, cnt = 0, s1 = 0;
    // 读入节点之间的连通情况，构建图v
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    // 遍历所有未访问过的节点
    for (int i = 1; i <= n; i++) {
        if (visit[i] == false) {
            // 以当前节点为起点，进行深度优先搜索
            dfs(i, 1);
            // 如果当前节点为1，将搜索结果存储到s中，并记录起始点s1
            if (i == 1) {
                // 如果搜索结果不为空，记录其中的第一个节点为s1
                if (temp.size() != 0) {
                    s1 = temp[0];
                }
                // 将搜索结果存储到s中
                for (int j = 0; j < temp.size(); j++) {
                    s.insert(temp[j]);
                }
            }
            // 连通块数量加1
            cnt++;
        }
    }
    // 如果连通块数量大于等于2，输出错误信息
    if (cnt >= 2) {
        printf("Error: %d components", cnt);
    } else {
        // 清空搜索结果temp、最大高度maxheight和访问标记visit
        temp.clear();
        maxheight = 0;
        fill(visit, visit + 10010, false);
        // 以起始点s1为根节点，进行深度优先搜索
        dfs(s1, 1);
        // 将搜索结果存储到s中，得到并集
        for (int i = 0; i < temp.size(); i++) {
            s.insert(temp[i]);
        }
        // 遍历并输出所有的最深根节点
        for (auto it = s.begin(); it != s.end(); it++) {
            printf("%d\n", *it);
        }
    }
    return 0;
}