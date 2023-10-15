/*给一棵二叉搜索树的前序遍历，判断它是否为红黑树，是输出Yes，否则输出No。*/
#include <iostream>
#include <vector>
using namespace std;
vector<int> arr;
struct node {
    int val;
    struct node *left, *right;
};

int main() {
    int k, n;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &n);
        arr.resize(n);
        node* root = NULL;
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[j]);
        }
    }
    return 0;
}