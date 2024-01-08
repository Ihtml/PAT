#include <iostream>
using namespace std;
struct node {
    int lchild, rchild, parent, level;
    node() { lchild = rchild = parent = -1; }
} Tree[1002];
int n, m, a, b, root, f, Full;
int In[32], Post[32];
string t;
int deal(int R, int start, int end, int Pa) {
    if (start > end) {
        return -1;
    }
    int i = start;
    while (i < end && In[i] != Post[R]) {
        i++;
    }
    Tree[Post[R]].parent = Pa;
    Tree[Post[R]].level = Tree[Pa].level + 1;
    Tree[Post[R]].lchild = deal(R - 1 - end + i, start, i - 1, Post[R]);
    Tree[Post[R]].rchild = deal(R - 1, i + 1, end, Post[R]);
    if (Tree[Post[R]].lchild * Tree[Post[R]].rchild < 0) {
        Full = 1;
    }
    return Post[R];
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> Post[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> In[i];
    }
    root = Post[n - 1];
    deal(n - 1, 0, n - 1, 1001);
    return 0;
}