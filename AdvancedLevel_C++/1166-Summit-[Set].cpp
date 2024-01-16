#include <iostream>
#include <set>
#include <vector>
using namespace std;
int n, m, u, v, k, flag, flag2, l, e;
vector<vector<int>> A(201, vector<int>(201, 0));
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        A[u][v] = A[v][u] = 1;
    }
    cin >> k;
    for (int i = 1; i <= k; i++) {
        flag = 0;
        set<int> temp;
        cin >> l;
        for (int j = 0; j < l; j++) {
            cin >> e;
            for (auto it : temp) {
                if (!A[e][it])
                    flag = 1;
            }
            temp.insert(e);
        }
        cout << "Area " << i;
        if (flag) {
            cout << " needs help.\n";
        } else {
            for (int i = 1; i <= n; i++) {
                flag2 = 1;
                if (temp.count(i))
                    continue;
                for (auto it : temp) {
                    if (!A[i][it]) {
                        flag2 = 0;
                        break;
                    }
                }
                if (flag2) {
                    flag = i;
                    break;
                }
            }
            if (!flag) {
                cout << " is OK.\n";
            } else {
                cout << " may invite more people, such as " << flag << ".\n";
            }
        }
    }
    return 0;
}