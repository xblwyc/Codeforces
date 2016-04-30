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
#define LD double
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
const int N = 3010;

struct Edge
{
    int from;
    int to;
    int weight;
    
    Edge(int f, int t, int w):from(f), to(t), weight(w) {}
};
vector<Edge> edges;
vector<int> G[N]; // 每个节点出发的边编号
int p[N]; // 当前节点单源最短路中的上一条边
int d[N]; // 单源最短路径长
bool in_queue[N];
int cnt[N];
int n;
int m;
void addEdge(int u, int v, int w)
{
    int index = edges.size();
    edges.PB(Edge(u,v,w));
    G[u].PB(index);
}
bool SPFA(int s)
{
    int u;
    queue<int> Q;
    memset(in_queue, 0, sizeof(in_queue));
    memset(cnt, 0, sizeof(cnt));
    memset(d, 0x3f, sizeof(d));
    
    d[s] = 0;
    in_queue[s] = true;
    Q.push(s);
    while (!Q.empty()) {
        in_queue[u=Q.front()] = false;
        Q.pop();
        for (int i=0; i<G[u].size(); ++i) {
            Edge &e = edges[G[u][i]];
            if (d[e.to] > d[u] + e.weight) {
                d[e.to] = d[u] + e.weight;
                p[e.to] = G[u][i];
                if (!in_queue[e.to]) {
                    Q.push(e.to);
                    in_queue[e.to] = true;
                    if (++cnt[e.to] > n)
                        return false;
                }
            }
        }
    }
    return true;
}
int dist[3010][3010];

vector<pair<int,int> > aa[3010];
vector<pair<int,int> > bb[3010];
void solve()
{
    FOR(i,0,n)
    {
        SPFA(i);
        FOR(j,0,n)
        dist[i][j] = d[j];
    }
    FOR(i,0,n)
    {
        FOR(j,0,n)
        {
            if(i == j)
                continue;
            if(dist[i][j] != INF)
            {
                aa[i].PB(MP(dist[i][j], j));
                bb[j].PB(MP(dist[i][j], i));
            }
        }
    }
    FOR(i,0,n)
    {
        sort(ALL(aa[i]), greater<pair<int,int>>());
        sort(ALL(bb[i]), greater<pair<int,int>>());
    }
    int res = -1;
    vector<int> list;
    FOR(i,0,n)
    FOR(j,0,n)
    {
        if(i == j)
            continue;
        if(dist[i][j] == INF)
            continue;
        int curr = dist[i][j];
        FOR(p,0,min((int)bb[i].size(), 3))
        FOR(q,0,min((int)aa[j].size(), 3))
        {
            int u = bb[i][p].second;
            int v = aa[j][q].second;
            if(u == i || u == j)
                continue;
            if(v == i || v == j)
                continue;
            if(u == v)
                continue;
            if(curr + bb[i][p].first + aa[j][q].first > res)
            {
                res = curr + bb[i][p].first + aa[j][q].first;
                list = vector<int>({u,i,j,v});
            }
        }
    }
    FOR(i,0,list.size())
    cout << list[i] + 1 << " ";
    cout << endl;
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(false);
    cin >> n >> m;
    FOR(i,0,m)
    {
        int x ,y;
        cin >> x >> y;
        x--,y--;
        addEdge(x,y,1);
    }
    solve();
    return 0;
}