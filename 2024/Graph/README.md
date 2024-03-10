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
  - [单源最短路径Dijkstra算法](#单源最短路径dijkstra算法)
    - [邻接矩阵版: 时间复杂度O(V^2)](#邻接矩阵版-时间复杂度ov2)
      - [①新增边权:](#新增边权)
      - [②新增点权:](#新增点权)
      - [③求最短路径条数:](#求最短路径条数)
    - [邻接表版：复杂度O(V^2 + E)](#邻接表版复杂度ov2--e)
    - [通用模板方式：Dijkstra + DFS:](#通用模板方式dijkstra--dfs)
  - [全源最短路径Floyd算法-O(n^3)](#全源最短路径floyd算法-on3)
- [最小生成树](#最小生成树)
  - [Prim算法](#prim算法)

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
### 单源最短路径Dijkstra算法
可以用来处理无向边和有向边的单元最短路径问题，但**只能应对所有边权都是非负数的情况。** 处理无向边时只需当成两条指向相反的有向边即可。一条u与v之间的无向边在输入时可以分别对G[u][v]和G[v][u]赋以相同的边权;而对邻接表来说，只需要在u的邻接表Adj[u]末尾添加上v，并在v的邻接表Adj[v]末尾添加上u即可。
可以注意到，常规的做法都是复杂度O(V^2)级别的， 其中由于必须把每个顶点都标记为
已访问，因此外层循环的0(V)时间是无法避免的，但是寻找最小d[u]的过程却可以不必达到O(V)的复杂度，而可以使用堆优化来降低复杂度。最简洁的写法是直接使用STL中的优先队列priority__queue, 这样使用邻接表实现的Djkstra算法的时间复杂度可以降为0(VlogV+ E)。

算法策略：设置集合S存放已被访问的顶点，然后执行n次下面的两个步骤(n为顶点个数):
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
                令v的前驱为u;
        }
    }
}
```
#### 邻接矩阵版: 时间复杂度O(V^2)
```c++
int n, G[MAXV][MAXV];
int d[MAXV];    // 起点到达各点的最短路径长度
int pre[MAXV];  // pre[v]表示从起点到顶点v的的最短路径上v的前一个顶点(新添加)
bool vis[MAXV] = {false};  // 标记数组 vis[i]==true表示已访问，初值均为false

void Dijkstra(int s) {       // s为起点
    fill(d, d + MAXV, INF);  // fill函数将整个d数组赋为INF
    for (int i = 0; i < n; i++) {
        pre[i] = i;  // 初始状态下设每个点的前驱为自身（新添加）
    }
    d[s] = 0;  // 起点s到达自身的距离为0
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
                pre[v] = u;             // 记录v的前驱结点是u(新添加)
            }
        }
    }
}
void DFS(int s, int v) {  // s起点编号，v当前访问的顶点编号(从终点开始递归）
    if (v == s) {  // 如果当前已到达起点s,则输出起点并返回
        cout << s;
        return;
    }
    DFS(s, pre[v]);  // 递归访问v的前驱结点pre[v]
    cout << v;  // 从最深处return回来之后，输出每一层的顶点号
}
```
##### ①新增边权:
以新增的边权代表花费为例，用cost[u][v]表示u→v的花费(由题目输入),
并增加一个数组c[]，令从起点s到达顶点u的最少花费为c[u]，初始化时只有c[s]为0、其余c[u]均为INF 。这样就可以在d[u] + G[u][v] < d[v] (即可以使s到v的最短距离d[v]更优)时更新d[v]和c[v],而当d[u] + G[u][v] = d[v] ( 即最短距离相同)且c[u] + cost[u][v] < c[v] (即可以使s到v的最少花费更优)时更新c[v]。代码如下:
```c++
int cost[MAXV][MAXV], c[MAXV]; // cost[u][v]表示u→v的花费(由题目输入),s到点u的最少花费为c[u]
for (int v = 0; v < n; v++) {
    if (vis[v] == false && G[u][v] != INF) {  // 如果v未访问&&u能到达v
        if (d[u] + G[u][v] < d[v]) {  // 以u为中介可以使d[v]更优
            d[v] = d[u] + G[u][v];    // 优化d[v]
            pre[v] = u;               // 记录v的前驱结点是u(新添加)
            c[v] = c[u] + cost[u][v];
        } else if (d[u] + G[u][v] == d[v] && c[u] + cost[u][v] < c[v]) {
            c[v] = c[u] + cost[u][v];  // 最短距离相同时看能否使c[v]更优
        }
    }
}

```
##### ②新增点权:
以新增的点权代表城市中能收集到的物资为例，用weight[u]表示城市 u中的物资数目(由题目输入)，并增加一个数组w[]，令从起点s到达顶点u可以收集到的最大物资为w[u],初始化时只有w[s]为weight[s]、其余w[u]均为0。这样就可以在d[u] + G[u][v]< d[v] (即可以使s到v的最短距离d[v]更优)时更新d[v]和c[v]，而当d[u] + G[u][v] = d[v](即最短距离相同)且w[u] + weight[v]> w[v] (即可以使s到v的最大物资数目更优)时更新w[v]。代码如下:
```c++
int weight[MAXV], w[MAXV];
for (int v = 0; v < n; v++) {
    if (vis[v] == false && G[u][v] != INF) {  // 如果v未访问&&u能到达v
        if (d[u] + G[u][v] < d[v]) {  // 以u为中介可以使d[v]更优
            d[v] = d[u] + G[u][v];    // 优化d[v]
            pre[v] = u;               // 记录v的前驱结点是u(新添加)
            w[v] = w[u] + weight[v];
        } else if (d[u] + G[u][v] == d[v] && w[u] + weight[v] > w[v]) {
            w[v] = w[u] + weight[v];  // 最短距离相同时看能否使c[v]更优
            pre[v] = u;
        }
    }
}
```
##### ③求最短路径条数:
只需要增加一个数组num[],令从起点s到达顶点u的最短路径条
数为num[u],初始化时只有num[s]为1、其余num[u]均为0。这样就可以在d[u] + G[u][v] < d[v] (即可以使s到v的最短距离d[v]更优)时更新d[v],并让num[v]继承num[u],而当d[u] + G[u][v] = d[v] (即最短距离相同)时将num[u]加到num[v]上。代码如下：
```c++
int num[MAXV];
vector<int> pre[MAXV];
for (int v = 0; v < n; v++) {
    if (vis[v] == false && G[u][v] != INF) {  // 如果v未访问&&u能到达v
        if (d[u] + G[u][v] < d[v]) {  // 以u为中介可以使d[v]更优
            d[v] = d[u] + G[u][v];    // 优化d[v]
            pre[v].clear();           // 清空v的前驱节点集合
            pre[v].push_back(u);      // 将u加入v的前驱节点集合中
            num[v] = num[u];
        } else if (d[u] + G[u][v] == d[v]) {
            num[v] += num[u];
            pre[v].push_back(u); // 最短距离相同时累加num
        }
    }
}
```

#### 邻接表版：复杂度O(V^2 + E)
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

#### 通用模板方式：Dijkstra + DFS:
先在Dijkstra算法中记录下所有最短路径(只考虑距离)，然后从这些最短路径中选出一条第二标尺最优的路径。
```c++
const int MAXV = 1000;
const int INF = 100000000;

// 邻接矩阵版
int n, G[MAXV][MAXV];
int d[MAXV];  // 起点到达各点的最短路径长度
vector<int> pre[MAXV];  // pre[v]表示从起点到顶点v的的最短路径上v的前一个顶点
bool vis[MAXV] = {false};  // 标记数组 vis[i]==true表示已访问，初值均为false

void Dijkstra(int s) {  // s为起点
    fill(d, d + MAXV, INF);
    d[s] = 0;
    for (int i = 0; i < n; i++) {
        int u = -1, MIN = INF;  // 找到最小的d[u]
        for (int j = 0; j < n; j++) {
            if (vis[j] == false && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1) {
            return;
        }
        vis[u] = true;
        for (int v = 0; v < n; v++) {
            if (vis[v] == false && G[u][v] != INF) {
                if (d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];  // 优化d[v]
                    pre[v].clear();         // 清空pre[v]
                    pre[v].push_back(u);    // 令v的前驱为u
                } else if (d[u] + G[u][v] == d[v]) {
                    pre[v].push_back(u);  // 令v的前驱为u
                }
            }
        }
    }
}
int main() {}
```
DFS:遍历所有最短路径，找出一条使第二标尺最优的路径
```c++
int optvalue, st, ed;
vector<int> path, tempPath;
void DFS(int v) {   // v为当前访问结点
    if (v == st) {  // 递归边界（如果到达了叶子结点st）
        tempPath.push_back(v);
        int value;
        // todo：计算路径tempPath上的value值
        if (value > optvalue) {  // value 优于 optvalue
            optvalue = value;    // 更新第二标尺最优值与最优路径
            path = tempPath;
        }
        tempPath.pop_back();  // 将刚加入的结点删除
        return;
    }
    tempPath.push_back(v);  // 将当前访问结点加入临时路径tempPath的最后面
    for (int i = 0; i < pre[v].size(); i++) {
        DFS(pre[v][i]);  // 结点v的前驱结点pre[v][i],递归
    }
    tempPath.pop_back();  // 遍历完所有前驱结点，将当前结点v删除

    // todo① 边权之和
    int value = 0;
    for (int i = tempPath.size() - 1; i > 0; i--) {  // 倒着访问结点
        int id = tempPath[i], idNext = tempPath[i - 1];
        value += G[id][idNext];  // value增加边id -> idNext的边权
    }
     // todo②点权之和
    int value = 0, weight[MAXV], w[MAXV];
    for (int i = tempPath.size() - 1; i >= 0; i--) {  // 倒着访问结点
        int id = tempPath[i];                         // 当前结点id
        value += weight[id];  // value增加结点id的点权
    }
}
```

### 全源最短路径Floyd算法-O(n^3)
Floyd算法用来解决全源最短路问题，即对给定的图G(V,E),求任意两点u, v之间的最短路径长度，时间复杂度是O(n^3)。由于n3的复杂度决定了顶点数n的限制约在200以内，因此使用邻接矩阵来实现Floyd算法是非常合适且方
便的。
Floyd算法基于这样一一个事实: 如果存在顶点k,使得以k作为中介点时顶点i和顶点j的当前最短距离缩短，则使用顶点k作为顶点i和顶点j的中介点，即当dis[i][k] + dis[k][j] < dis[i][j]时，令dis[i][i]} = dis[i][k] + dis[k][j] (其中dis[i][]表示从顶点i到顶点j的最短距离)。如从V1到V4的距离为3,而以V2为中介点时可以使V1到V4的距离缩短为2,那么就把V1到V4的距离从3优化为2,即当dis[1][2] + dis[2][4] < dis[1][4]时, 令dis[1][4] = dis[1][2] + dis[2][4]。
伪代码：
```
枚举顶点k∈[1, n]
    以顶点k作为中介点，枚举所有顶点对i和j (i∈[1, n]，j∈[1, n])
        如果dis[i][k]+ dis[k][j]< dis[i][j]成立
            赋值dis[i][j] = dis[i][k] + dis[k][j]
```

## 最小生成树
### Prim算法
prim算法(可以将其读作“普里姆算法”)用来解决最小生成树问题，其基本思想是对图G(V,E)设置集合S,存放已被访问的顶点，然后每次从集合V-S中选择与集合S的最短距离最小的-一个顶点(记为u)，访问并加入集合S。之后，令顶点u为中介点，优化所有从u能到达的顶点v与集合S之间的最短距离。这样的操作执行n次(n 为顶点个数)，直到集合S已包含所有顶点。可以发现，prim 算法的思想与最短路径中Dijkstra 算法的思想几乎完全相同,只不过是数组d[]的含义不同,在涉及最短距离时使用了集合S代Djkstra算法中的起点s。