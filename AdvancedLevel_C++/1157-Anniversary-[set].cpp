#include <iostream>
#include <set>
using namespace std;
int main() {
    int n, m, ctn;
    string temp, smallx = "99999999", smalla = "99999999", ansx, ansa;
    set<string> record;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        record.insert(temp);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> temp;
        if (record.count(temp)) {
            ctn++;
        }
    }

    return 0;
}