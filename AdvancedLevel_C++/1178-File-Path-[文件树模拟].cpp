#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int n, k;
vector<string> last(1005);
unordered_map<string, int> value;
int main() {
    cin >> n;
    getchar();
    int cnt = 0;
    vector<vector<string>> Tree(1005, vector<string>());
    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        int depth = line.find_first_not_of(" ");  // 找到第一个不是空字符的下标
        string id = line.substr(depth, 4);  // 节点字符串
        value[id] = cnt++;
        Tree[depth].push_back(id);
        if (depth > 0) {
            last[cnt] = Tree[depth - 1].back();  // 记录上一层的父节点是哪个
        }
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        string query;
        cin >> query;
    }
    return 0;
}