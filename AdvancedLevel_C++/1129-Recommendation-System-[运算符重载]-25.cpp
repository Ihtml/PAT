#include <iostream>
#include <set>
using namespace std;

struct obj {
    int idx, ctn;

    // 重载比较运算符，用于自定义 set 的排序规则
    bool operator<(const obj& a) const {
        return ctn == a.ctn ? idx < a.idx : ctn > a.ctn;
    }
};

int main() {
    int n, k, idx, book[500001];
    set<obj> st;

    // 读取输入
    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &idx);

        if (i != 0) {
            // 输出当前数的前 k 大频次的数
            printf("%d:", idx);
            int t = 0;
            for (auto it = st.begin(); t < k && it != st.end(); it++) {
                printf(" %d", it->idx);
                t++;
            }
            printf("\n");
        }

        // 更新 set 中的元素
        obj a;
        a.idx = idx;
        a.ctn = book[idx];
        auto it = st.find(a);

        // 如果元素已经存在，先删除旧的再插入新的
        if (it != st.end()) {
            st.erase(it);
        }

        // 更新频次并插入 set
        book[idx]++;
        a.ctn = book[idx];
        st.insert(a);
    }

    return 0;
}
