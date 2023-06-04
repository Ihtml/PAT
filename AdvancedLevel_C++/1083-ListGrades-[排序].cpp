#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct peo {
    string name, id;
    int grade;
};
bool cmp(peo a, peo b) {
    return a.grade > b.grade;
}
int main() {
    int n, low, high, cnt = 0;
    cin >> n;
    vector<peo> stud(n);
    for (int i = 0; i < n; i++) {
        cin >> stud[i].name >> stud[i].id >> stud[i].grade;
    }
    cin >> low >> high;
    for (int i = 0; i < n; i++) {
        if (stud[i].grade < low || stud[i].grade > high) {
            stud[i].grade = -1;
        } else {
            cnt++;
        }
    }
    sort(stud.begin(), stud.end(), cmp);
    for (int i = 0; i < cnt; i++) {
        cout << stud[i].name << " " << stud[i].id << endl;
    }
    if (cnt == 0) {
        cout << "NONE";
    }
    return 0;
}