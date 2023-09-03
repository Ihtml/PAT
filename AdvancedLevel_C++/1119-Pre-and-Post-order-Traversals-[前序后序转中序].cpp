/*给出一棵树的结点个数n，以及它的前序遍历和后序遍历，输出它的中序遍历，
如果中序遍历不唯一就输出No，且输出其中一个中序即可，如果中序遍历唯一就输出Yes，并输出它的中序*/
#include <iostream>
#include <vector>
using namespace std;
vector<int> in, pre, post;
bool isUnique = true;
void getIn(int preLeft,int preRight,int postLeft, int postRight){
    // Todo
}
int main() {
    int n;
    cin >> n;
    pre.resize(n), post.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> pre[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> post[i];
    }
    cout << (isUnique == true ? "Yes" : "No") << in[0];

    return 0;
}