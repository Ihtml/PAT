#include <iostream>
#include <stack>
using namespace std;
stack<int> s;
int main() {
    int n;
    scanf("%d", &n);
    string str;
    for (int i = 0; i < n; i++) {
        cin >> str;
        switch (str[1]) {
            case 'u':  // push操作

                break;

            case 'o':  // pop操作
                if (!s.empty()) {
                } else {
                    printf("Invalid\n");
                }

                break;

            default:  // median操作
                if (!s.empty()) {
                } else {
                    printf("Invalid\n");
                }

                break;
        }
    }
    return 0;
}