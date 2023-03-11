#include <iostream>
#include <vector>
using namespace std;
struct student {
    long long int no;
    int score, finrank, loca, locarank;
};
bool cmp(student a, student b) {
    a.score != b.score ? a.score > b.score : a.no < b.no;
}
int main() {
    int n, m;
    scanf("%d", &n);
    vector<student> fin;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &m);
        vector<student> v(m);
        for (int j = 0; j < m; j++) {
            scanf("%lld %d", &v[j].no, &v[j].score);
            v[j].loca = i;
        }
        sort(v.begin(), v.end(), cmp);
        v[0].locarank = 1;
        fin.push_back(v[0]);
        for (int j = 1; j < m; j++) {
            v[j].locarank =
                (v[j].score == v[j - 1].score) ? (v[j - 1].locarank) : j + 1;
            fin.push_back(v[j]);
        }
    }
    sort(fin.begin(), fin.end(), cmp);
    return 0;
}