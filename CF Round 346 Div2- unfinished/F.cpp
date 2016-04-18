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

int n,m;
LL k;
int b[1010][1010];
int dirx[4] = {0,-1,0,1};
int diry[4] = {1,0,-1,0};
int root[1000100];
int sz[1000100];
int vis[1010][1010];
struct NODE
{
    int val, x,y;
} a[1000100];
int find(int u)
{
    if(u == root[u])
        return u;
    return root[u] = find(root[u]);
}
void uni(int u, int v)
{
    int r1 = find(u);
    int r2 = find(v);
    if(sz[r1] == 0 || sz[r2] == 0)
        return;
    if(r1 == r2)
        return;
    sz[r1] += sz[r2];
    sz[r2] = 0;
    root[r2] = r1;
    
}
int conv(int x, int y)
{
    return x * n + y;
}
bool cmp(NODE a, NODE b)
{
    return a.val > b.val;
}
void merge(int x ,int y)
{
    int index = conv(x,y);
    FOR(i,0,4)
    {
        int nx = x + dirx[i];
        int ny = y + diry[i];
        if(nx < 0 || nx >= m)
            continue;
        if(ny < 0 || ny >= n)
            continue;
        int ii = conv(nx, ny);
        uni(index, ii);
    }
}
void DFS(int x ,int y ,int val, int& tot)
{
    if(x < 0 || x >= m)
        return;
    if(y < 0 || y >= n)
        return;
    if(vis[x][y])
        return;
    if(b[x][y] < val)
        return;
    if(tot == 0)
        return;
    vis[x][y] = 1;
    if(b[x][y] >= val)
    {
        tot--;
        b[x][y] = -1;
    }
    FOR(i,0,4)
    {
        DFS(x + dirx[i], y + diry[i], val, tot);
    }
}
void solve()
{
    FOR(i,0,m)
    FOR(j,0,n)
    {
        a[conv(i,j)].val = b[i][j];
        a[conv(i,j)].x = i;
        a[conv(i,j)].y = j;
        root[conv(i,j)] = conv(i,j);
        sz[conv(i,j)] = 0;
    }
    sort(a, a + m * n, cmp);
    FOR(i,0,m * n)
    {
        /*FOR(j,0,m)
        {
            FOR(k,0,n)
            cout << find(conv(j,k)) << " ";
            cout << endl;
        }*/
        int index = conv(a[i].x, a[i].y);
        sz[index] = 1;
        merge(a[i].x, a[i].y);
        int cnt = sz[find(index)];
        if(k % a[i].val != 0)
            continue;
        if(cnt >= k / a[i].val)
        {
            cout << "YES" << endl;
            ZERO(vis);
            int t = k / a[i].val;
            DFS(a[i].x, a[i].y, a[i].val, t);
            FOR(u,0,m)
            {
                FOR(v,0,n)
                {
                    if(b[u][v] == -1)
                        cout << a[i].val << " ";
                    else
                        cout << 0 << " ";
                }
                cout << endl;
            }
            return;
        }
    }
    cout <<  "NO" << endl;;
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    cin >> m >> n;
    cin >> k;
    //m = n = 100;
    //k = 1e18;
    FOR(i,0,m)
    FOR(j,0,n)
    cin >> b[i][j];
    solve();
    
    return 0;
}