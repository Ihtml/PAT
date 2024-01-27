#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int n, k;                       // n 表示节点数，k 表示查询数
vector<string> last(1005);      // 存储每个节点的父节点ID
unordered_map<string, int> mp;  // 将节点ID映射到一个整数值
int main() {
    cin >> n;
    getchar();
    int cnt = 0;
    vector<vector<string>> Tree(1005, vector<string>());  // 树的结构按深度分层
    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        int depth = line.find_first_not_of(" ");  // 当前行的深度（空格数量）
        string id = line.substr(depth, 4);  // 节点ID字符串
        mp[id] = cnt;                       // 将节点ID映射到计数器值
        Tree[depth].push_back(id);  // 将节点加入对应深度的向量中
        if (depth > 0) {
            last[cnt] = Tree[depth - 1].back();  // 记录上一层的父节点是哪个
        }
        cnt++;
    }
    cin >> k;
    vector<string> path;
    for (int i = 0; i < k; i++) {
        string query;
        cin >> query;
        path.clear();
        if (mp.find(query) == mp.end()) {
            cout << "Error: " << query << " is not found." << endl;
            continue;
        }
        while (query != "0000") {  // 从查询节点回溯到根节点
            path.push_back(query);
            query = last[mp[query]];
        }
        path.push_back("0000");                       // 加入根节点
        for (int i = path.size() - 1; i >= 0; i--) {  // 逆序输出路径
            cout << path[i];
            i&& cout << "->";
        }
        cout << "\n";
    }
    return 0;
}