## 图的存储
### 邻接矩阵
设图G(V,E)的顶点标号为0, 1,.,N-1,那么可以令二维数组G[N][N]的两维分别表示图的顶点标号，即如果G[i][j]为1,则说明顶点i和顶点j之间有边;如果G[i][j]为0,则说明顶点i和顶点j之间不存在边，而这个二维数组G[][]则被称为邻接矩阵。另外，如果存在边权，则可以令G[i][i]存放边权，对不存在的边可以设边权为0、-1 或是一个很大的数。

### 邻接表
使用vector实现邻接表。
```c++
struct node {
    int v;                                  // 边的终点编号
    int w;                                  // 边权
    node(int _v, int _w) : v(_v), w(_w) {}  // 构造函数
};
vector<node> Adj[N];
Adj[1].push_back(node(3,4)); // 添加1号到达3号顶点的有向边，边权威4
```

## 图的遍历
### DFS
如果要遍历整个图，就需要对所有连通块分别进行遍历。所以DFS遍历图的基本思路就是将经过的顶点设置为已访问，在下次递归碰到这个顶点时就不再去处理，直到整个图的顶点都被标记为已访问。伪代码如下：
```c++
DFS(u) { //访问顶点 u
    vis[u] = true; //设置u 已被访问
    for (从u出发能到达的所有顶点v) //枚举从u出发可以到达的所有顶点 V
        if vis[v] == false //如果v未被访问
            DFS(v); //递归访问 v
}

DFSTrave(G) { //遍历图 G
    for (G的所有顶点u) //对 G的所有顶点u
        if vis[u]== false //如果 u未被访问
        DFS(u); //访问 u所在的连通块

```
邻接矩阵版：
```c++
const int MAXV = 1000;      // 最大顶点数
const int INF = 100000000;  // 设INF为一个很大的树
int n, G[MAXV][MAXV];       // n为顶点数，MAXV为最大顶点数
bool vis[MAXV] = {false};  // 如果顶点i已被访问，则vis[i]==true,初值为false

void DFS(int u, int depth) {  // u为当前访问的顶点标号，depth为深度
    vis[u] = true;            // 设置u已被访问
    for (int i = 0; i < n; i++) {
        if (vis[i] == false && G[u][i] != INF) {
            DFS(i, depth + 1);  // 访问i，深度加1
        }
    }
}

void DFSTrave() {
    for (int i = 0; i < n; i++) {
        if (vis[i] == false) {
            DFS(i, 1);  // 访问u和i所在的连通块，1表示第一层
        }
    }
}
```
邻接表版：
```c++
vector<int> Adj[MAXV];  // 图G的邻接表
int n;                  // n为顶点数，MAXV为最大顶点数
bool vis[MAXV] = {false};  // 如果顶点i已被访问，则vis[i]==true,初值为false

void DFS(int u, int depth) {  // u为当前访问的顶点标号，depth为深度
    vis[u] = true;            // 设置u已被访问
    // 如果要对u进行一些操作，可以在此处进行
    for (int i = 0; i < Adj[u].size(); i++) {
        int v = Adj[u][i];
        if (vis[v] == false) {  // 如果v未被访问
            DFS(v, depth + 1);  // 访问v，深度加1
        }
    }
}

void DFSTrave() {
    for (int i = 0; i < n; i++) {
        if (vis[i] == false) {
            DFS(i, 1);  // 访问u和i所在的连通块，1表示第一层
        }
    }
}
```

### BFS
使用BFS遍历图需要使用一个**队列**，通过反复去除队首顶点，将该顶点可到达的**未曾加入过队列**的顶点全部入队，知道队列为空时遍历结束。
伪代码：
```c++
BFS(u){ //遍历u所在的连通块
    queue q; //定义队列q
    // 将u入队;
    inq[u]= true; //设置u 已被加入过队列
    while(q非空) { //只要队列非空
        // 取出q的队首元素u进行访问;
        for (从u出发可达的所有顶点v)     //枚举从u能直接到达的顶点V
            if (inq[v]== false){ //如果v未曾加入过队列
                // 将v入队;
                inq[v] = true; //设置v已被加入过队列
            }
    }
}
BFSTrave(G) {//遍历图 G
    for(G的所有顶点u)  //枚举 G的所有顶点 u
        if (inq[u]== false){ // 如果u未曾加入过队列
        BFS(u); //遍历u所在的连通块
    }
}
```