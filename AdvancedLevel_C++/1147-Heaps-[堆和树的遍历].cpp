// 给一个树的层序遍历，判断它是不是堆，是大顶堆还是小顶堆。输出这个树的后序遍历
#include <iostream>
using namespace std;
int a[1005], m, n;
void postOrder(int index){
    if (index > n)
    {
        return;
    }
    postOrder(index*2);
    postOrder(index*2+1);
    cout << a[index] << (index == 1 ? "\n" : "");
}
int main(){
    cin >> m >> n;
    return 0;
}