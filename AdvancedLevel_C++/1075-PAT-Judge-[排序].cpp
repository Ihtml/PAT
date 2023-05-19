#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct node {
    int rank, id, total = 0;
    vector<int> score;
    int passnum = 0;
    bool isshown = false;
};
bool cmp(node a, node b) {
    if (a.total != b.total) {
        return a.total > b.total;
    } else if (a.passnum != b.passnum) {
        return a.passnum > b.passnum;
    } else {
        return a.id < b.id;
    }
}
int main(){
    int n, k, m, id, num, score;
    scanf("%d %d %d", &n, &k, &m);
    vector<node> v(n+1);
    // todo
    return 0;
}
