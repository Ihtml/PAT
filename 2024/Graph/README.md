- [图的存储](#图的存储)
  - [邻接矩阵](#邻接矩阵)
  - [邻接表](#邻接表)
- [图的遍历](#图的遍历)
  - [DFS](#dfs)
    - [邻接矩阵版：](#邻接矩阵版)
    - [邻接表版：](#邻接表版)
  - [BFS](#bfs)
    - [邻接矩阵版：](#邻接矩阵版-1)
    - [邻接矩阵版：](#邻接矩阵版-2)
  - [层序遍历:](#层序遍历)
- [最短路径](#最短路径)
  - [单元最短路径Dijkstra算法](#单元最短路径dijkstra算法)

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
#### 邻接矩阵版：
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
#### 邻接表版：
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
#### 邻接矩阵版：
```c++
int n, G[MAXV][MAXV];  // n 为顶点数，MAXV为最大顶点数
bool inq[MAXV] = {false};  // 若项点i 曾入过队列，则inq[i]==true。 初值为false
void BFS(int u) {  // 遍历u所在的连通块
    queue<int> q;
    // 定义队列q
    q.push(u);  // 将初始点u入队
    inq[u] = true;
    // 设置 u已被加入过队列
    while (!q.empty()) {  // 只要队列非空
        int u = q.front();
        // 取出队首元素
        q.pop();  // 将队首元素出队
        for (int v = 0; v < n; v++) {
            // 如果u的邻接点v未曾加入过队列
            if (inq[v] == false && G[u][v] != INF) {
                q.push(v);      // 将v 入队
                inq[v] = true;  // 标记 V为已被加入过队列
            }
        }
    }
}
void BFSTrave({           // 遍历图
    for (int u = 0; u < n; u++) {  // 枚举所有顶点
        if (inq[u] == false) {     // 如果u未曾加入过队列
            BFS(u);
        }
    }
}
```
#### 邻接矩阵版：
```c++
vector<int> Adj[MAXV];  // Adj存放从顶点u出发可到达的所有顶点
int n;                  // n为顶点数，MAXV为最大顶点数
bool inq[MAXV] = {false};  // 若项点i 曾入过队列，则inq[i]==true。 初值为false

void BFS(int u) {  // 遍历u所在的连通块
    queue<int> q;
    // 定义队列q
    q.push(u);  // 将初始点u入队
    inq[u] = true;
    // 设置 u已被加入过队列
    while (!q.empty()) {  // 只要队列非空
        int u = q.front();
        // 取出队首元素
        q.pop();  // 将队首元素出队
        for (int i = 0; i < Adj[u].size();
             i++) {  // 枚举从u出发能到达的所有顶点
            int v = Adj[u][i];
            if (inq[v] == false) {  // 如果v未曾加入过队列
                q.push(v);          // 将v入队
                inq[v] = true;      // 标记v为已加入过队列
            }
        }
    }
}
void BFSTrave() {                  // 遍历图
    for (int u = 0; u < n; u++) {  // 枚举所有顶点
        if (inq[u] == false) {     // 如果u未曾加入过队列
            BFS(u);                // 遍历u所在的连通块
        }
    }
}
```
### 层序遍历:
```c++
struct node {
    int v;      // 顶点编号
    int layer;  // 顶点层号
};
vector<node> Adj1[MAXV];
bool inq[MAXV] = {false};  // 若项点i 曾入过队列，则inq[i]==true。 初值为false

void BFS(int s) {
    queue<node> q;
    node start;
    start.v = s;
    start.layer = 0;
    q.push(start);
    inq[s] = true;
    while (!q.empty()) {
        node topNode = q.front();
        q.pop();
        int u = topNode.v;
        for (int i = 0; i < Adj1[u].size(); i++) {
            node next = Adj1[u][i];
            next.layer = topNode.layer + 1;
            if (inq[next.v] == false) {
                q.push(next);
                inq[next.v] = true;
            }
        }
    }
}
void BFSTrave() {                  // 遍历图
    for (int u = 0; u < n; u++) {  // 枚举所有顶点
        if (inq[u] == false) {     // 如果u未曾加入过队列
            BFS(u);                // 遍历u所在的连通块
        }
    }
}
```
## 最短路径
### 单元最短路径Dijkstra算法
策略：设置集合S存放已被访问的顶点，然后执行n次下面的两个步骤(n为顶点个数):
①每次从集合V-S 中选择与起点s的最短距离最小的一个顶点(记为u),访问并加入集合S 。
②之后，令顶点u为中介点，优化起点s与所有从u能到达的顶点v之间的最短距离。
实现：
①集合S可以用一个bool型数组vis[]来实现， 即当vis[i] = true时表示顶点V;已被访问，当vis[i] == false时表示顶点V;未被访问。
②令int型数组d[]表示起点s到达顶点V;的最短距离,初始时除了起点s的d[s]赋为0,
其余顶点都赋为一个很大的数(初学者可以用100000000， 即10%; 稍微懂点二进制编码的
话可以使用十六进制f33fffff，,但不要使用fxffffff，.因为两个这样的数相加可能会超过int的表示范围)来表示inf,即不可达。
伪代码：
```c++
//G为图，-般设成全局变量;数组d为源点到达各点的最短路径长度，s为起点
Dijkstra (G, d[], s) {
    // 初始化
    for(循环n次){
        u = 使d[u]最小的还未被访问的顶点的编号。
        记u已被访问。
        for(从u出发能到达的所有顶点v){
            if(v未被访问&&以u为中介点使s到v的最短距离d[v]更优)
                优化d[v];
        }
    }
}
```
邻接矩阵版: 时间复杂度O(V^2)
```c++
int n, G[MAXV][MAXV];
int d[MAXV];               // 起点到达各点的最短路径长度
bool vis[MAXV] = {false};  // 标记数组 vis[i]==true表示已访问，初值均为false

void Dijkstra(int s) {       // s为起点
    fill(d, d + MAXV, INF);  // fill函数将整个d数组赋为INF
    d[s] = 0;                // 起点s到达自身的距离为0
    for (int i = 0; i < n; i++) {
        int u = -1, MIN = INF;  // u使d[u]最小，MIN存放该最小的d[u]
        for (int j = 0; j < n; j++) {
            if (vis[j] == false && d[j] < MIN) {  // 找到未访问的顶点中d[]最小的
                u = j;
                MIN = d[j];
            }
        }
        // 找不到小于INF的d[u],说明剩下的顶点和起点s不连通
        if (u == -1)
            return;
        vis[u] = true;  // 标记u为已访问
        for (int v = 0; v < n; v++) {
            if (vis[v] == false && G[u][v] != INF && d[u] + G[u][v] < d[v]) {
                d[v] = d[u] + G[u][v];  // 优化d[v]
            }
        }
    }
}
```
邻接表版：复杂度O(V^2 + E)
```c++
struct node {
    int v, dis;  // v为目标顶点，dis为边权
};
vector<node> Adj[MAXV];  // 邻接表，存放从顶点u出发可以到达的所有顶点
int n, d[MAXV];            // n为(实际)顶点数
bool vis[MAXV] = {false};  // 标记数组，表示某个顶点是否已被访问
void Dijkstra(int s) {
    fill(d, d + MAXV, INF);
    d[s] = 0;
    for (int i = 0; i < n; i++) {
        int u = -1, MIN = INF;
        for (int j = 0; j < n; j++) {
            if (vis[j] == false && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1)
            return;
        vis[u] = true;
        for (int j = 0; j < Adj[u].size(); j++) {
            int v = Adj[u][j].v;
            if (vis[v] == false && d[u] + Adj[u][j].dis < d[v]) {
                d[v] = d[u] + Adj[u][j].dis;  // 优化d[v]
            }
        }
    }
}
```