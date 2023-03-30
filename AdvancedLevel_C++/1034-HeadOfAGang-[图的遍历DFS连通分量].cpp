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

    return 0;
}