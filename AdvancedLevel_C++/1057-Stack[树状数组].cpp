#include <iostream>
#include <stack>
#define lowbit(i) ((i) & (-i))
const int maxn = 100010;
using namespace std;
int c[maxn];
stack<int> s;
void update(int x, int v) {
    for (int i = x; i < maxn; i += lowbit(i)) {
        c[i] += v;
    }
}
int main() {
    int n, temp;
    scanf("%d", &n);
    string str;
    for (int i = 0; i < n; i++) {
        cin >> str;
        switch (str[1]) {
            case 'u':  // push操作
                scanf("%d", temp);
                s.push(temp);
                update(temp, 1);
                break;

            case 'o':  // pop操作
                if (!s.empty()) {
                    update(s.top(), -1);
                    printf("%d\n", s.top());
                    s.top();
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