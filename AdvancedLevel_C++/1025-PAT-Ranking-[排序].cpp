#include <iostream>
#include <vector>
using namespace std;
struct student {
    long long int no;
    int score, finrank, loca, locarank;
};
int main() {
    int n, m, totle = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &m);
        vector<student> v(m);
        for (int j = 0; j < m; j++) {
            scanf("%lld %d", &v[j].no, &v[j].score);
            v[j].loca = i;
        }
    }

    return 0;
}