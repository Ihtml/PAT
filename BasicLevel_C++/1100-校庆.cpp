#include <iostream>
#include <set>
using namespace std;
set<string> record;
int main() {
    int N, M, ctn = 0;
    string temp, minX = "99999999", X, minY = "99999999", Y;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        record.insert(temp);
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> temp;
        if (record.find(temp) != record.end()) {
            ctn++;
            if (temp.substr(6, 8) < minX) {
                minX = temp.substr(6, 8);
                X = temp;
            }
        }
        if (temp.substr(6, 8) < minY) {
            minY = temp.substr(6, 8);
            Y = temp;
        }
    }
    cout << ctn << endl;
    cout << (ctn ? X : Y);
    return 0;
}