/*Q:输出一个二叉搜索树的最后两层结点个数a和b，以及他们的和c：“a + b = c”*/
/*A:用链表存储，递归构建二叉搜索树，深度优先搜索，
传入的参数为结点和当前结点的深度depth，如果当前结点为NULL就更新最大深度maxdepth的值并return，
将每一层所对应的结点个数存储在数组num中，输出数组的最后两个的值*/
#include <iostream>
#include <vector>
using namespace std;
struct node {
    int v;
    struct node *left, *right;
};
vector<int> num(1000);
int main(){
    int n, t;
    cin >> n;
    node *root = NULL;
    return 0;
}