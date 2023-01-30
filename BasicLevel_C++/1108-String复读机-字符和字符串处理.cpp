#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main() {
    vector<int>  c(200);
    int flag = 1;
    string s = "String", SS;
    cin >> SS;
    for (auto it : SS)
        c[it]++;
    while (flag) {
        flag = 0;
        for (int i = 0; i < 6; i++) {
            if (c[s[i]] != 0) {
                cout << s[i];
                flag = 1;
                c[s[i]]--;
            }
        }
    }
    return 0;
}
int main1() {
    string s = "String", SS;
    cin >> SS;
    unordered_map<char, int> mp;
    int l = s.length(), len = SS.length();
    for (int i = 0; i < l; i++) {
        mp[s[i]] = 0;
    }
    for (int i = 0; i < len; i++) {
        if (s.find(SS[i]) != string::npos) {
            mp[SS[i]]++;
        }
    }
    int flag = 1;
    while (flag) {
        flag = 0;
        for (int i = 0; i < 6; i++) {
            if (mp[s[i]]) {
                cout << s[i];
                mp[s[i]]--;
                flag = 1;
            }
        }
    }
    return 0;
}