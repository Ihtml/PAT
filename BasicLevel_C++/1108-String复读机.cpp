#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
    string s = "String", SS;
    cin >> SS;
    unordered_map<char, int> mp;
    int l=s.length(), len = SS.length();
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