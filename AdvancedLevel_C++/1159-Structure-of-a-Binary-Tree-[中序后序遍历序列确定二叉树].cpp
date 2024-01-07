#include <iostream>
using namespace std;
struct node {
    int lchild, rchild, parent, level;
    node() { lchild = rchild = parent = -1; }
} Tree[1002];
int n, m, a, b, root, f, Full;
int In[32], Post[32];
string t;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> Post[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> In[i];
    }
    root = Post[n - 1];
    return 0;
}