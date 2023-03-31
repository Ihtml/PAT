#include <iostream>
#include <map>
using namespace std;
map<string, int> stringToInt;
map<int, string> intToString;
map<string, int> ans;
int idNum = 1, k;
int stoifunc(string s) {
    if (stringToInt[s] == 0) {
        stringToInt[s] = idNum;
        intToString[idNum] = s;
        return idNum++;
    } else {
        return stringToInt[s];
    }
}
const int N = 1010;
int G[N][N], weight[N];
bool vis[2010];
void dfs(int u, int& head, int& numMember, int& totalweight) {
    vis[u] = true;
    numMember++;
    if (weight[u] > weight[head]) {
        head = u;
    }
    for (int v = 1; v < idNum; v++) {
        if (G[u][v] > 0) {
            totalweight += G[u][v];
            G[u][v] = G[v][u] = 0;
            if (vis[v] == false) {
                dfs(v, head, numMember, totalweight);
            }
        }
    }
}
void dfsTrave() {
    for (int i = 1; i < idNum; i++) {
        if (vis[i] == false) {
            int head = i, numMember = 0, totalweight = 0;
            dfs(i, head, numMember, totalweight);
            if (numMember > 2 && totalweight > k) {
                ans[intToString[head]] = numMember;
            }
        }
    }
}
int main() {
    int n, w;
    scanf("%d%d", &n, &k);
    string s1, s2;
    for (int i = 0; i < n; i++) {
        cin >> s1 >> s2 >> w;
        int id1 = stoifunc(s1);
        int id2 = stoifunc(s2);
        weight[id1] += w;
        weight[id2] += w;
        G[id1][id2] += w;
        G[id2][id1] += w;
    }
    dfsTrave();

    return 0;
}