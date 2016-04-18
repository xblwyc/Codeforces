#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <ostream>
#include <queue>
#include <cmath>
#include <climits>
#include <utility>
#include <fstream>
#include <memory>
#include <sstream>
#include <set>
#include <iterator>
#include <iomanip>
#include <map>
#include <stack>
using namespace std;
#define FOR(a, b, n) for(int (a) = (b); (a) < (n); ++(a))
#define FORE(a, b, n) for(int (a) = (b); (a) <= (n); ++(a))
#define ITE(a, v) for(auto (a) = v.begin(); (a) != v.end(); ++(a))
#define LL long long
#define ALL(v) v.begin(),v.end()
#define ZERO(v) memset(v, 0, sizeof v)
#define NEG(v)  memset(v, -1, sizeof v)
#define F first
#define S second
#define LD long double
#define pw(x) (1LL << (x))
#define sqr(x) ((x)*(x))
#define PB push_back
#define MP make_pair
#define MOD 1000000007
#define PI 3.141592653589793
#define PII pair<LL, LL>
#define INF 0x3f3f3f3f
#define FUL(x) memset(x, 0x3f, sizeof(x));
#define debug(args...) {cerr << #args << " = "; errDebug(args); cerr << endl;}
void errDebug() {}
template<typename T, typename... Args>
void errDebug(T a, Args... args) {
    cerr << a << ' ';
    errDebug(args...);
}

struct Edge
{
    int from;
    int to;
    int weight;
    
    Edge(int f, int t, int w):from(f), to(t), weight(w) {}
};
const int N = 100100;
vector<Edge> edges;
vector<int> G[N]; // 每个节点出发的边编号

void addEdge(int u, int v, int w)
{
    int index = edges.size();
    edges.PB(Edge(u,v,w));
    G[u].PB(index);
}

int n, m;
int cnt;
int vis[100100];
bool circle;
void DFS(int index, int par)
{
    if(vis[index])
        return;
    vis[index] = 1;
    FOR(i,0,G[index].size())
    {
        int pos = G[index][i];
        int v = edges[pos].to;
        if(v == par)
            continue;
        if(!vis[v])
            DFS(v, index);
        else
            circle = true;
    }
    
}
int solve()
{
    cnt = 0;
    ZERO(vis);
    FORE(i,1,n)
    {
        circle = false;
        if(vis[i])
            continue;
        DFS(i, -1);
        if(circle)
            continue;
        cnt++;
    }
    return cnt;
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    cin >> n >> m;
    int u,v;
    FOR(i,0,m)
    {
        cin >> u >> v;
        addEdge(u,v,1);
        addEdge(v,u,1);
    }
    cout << solve() << endl;
    return 0;
}