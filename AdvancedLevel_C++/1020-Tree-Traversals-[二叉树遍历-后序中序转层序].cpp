#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct node {
    int index, value;
};
vector<int> post, in;
vector<int> ans;
int main() {
    int n;
    scanf("%d", &n);
    post.resize(n);
    in.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &post[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }
    return 0;
}