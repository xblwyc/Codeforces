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
int m,n,q,x,y,val, ops;
pair<int,int> g[110][110];
int res[110][110];
void solve()
{
    if(ops == 3)
    {
        int xx = g[x][y].first;
        int yy = g[x][y].second;
        res[xx][yy] = val;
    }
    else if(ops == 1)
    {
        int r = val;
        pair<int,int> f = g[r][0];
        for(int i = 0; i < n - 1; i++)
            g[r][i] = g[r][i + 1];
        g[r][n - 1] = f;
    }
    else
    {
        int c = val;
        pair<int,int> f = g[0][c];
        for(int i = 0; i < m - 1; i++)
            g[i][c] = g[i + 1][c];
        g[m - 1][c] = f;
    }
}
int main() {
    
    cin.tie(0);
    cin.sync_with_stdio(false);
    cin >> m >> n >> q;
    FOR(i,0,m)
    FOR(j,0,n)
    g[i][j] = MP(i,j);
    FUL(res);
    FOR(i,0,q)
    {
        cin >> ops;
        if(ops == 3)
        {
            cin >> x >> y >> val;
            x--;
            y--;
        }
        else
        {
            cin >> val;
            val--;
        }
        solve();
    }
    FOR(i,0,m)
    {
        FOR(j,0,n)
        {
            if(res[i][j] == INF)
                cout << 1 << " ";
            else
                cout << res[i][j] << " ";
        }
        cout << endl;
    }
        return 0;
}