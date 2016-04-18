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
vector<pair<int,int> > g[100100];
int statu[100100];
int statu2[100100];
bool ok1;
bool ok2;
vector<int> vec1;
vector<int> vec2;
vector<int> v[2];
void DFS1(int index, int change, int color)
{
    if(statu[index] != -1)
    {
        if(statu[index] != change)
        {
            ok1 = false;
        }
        return;
    }
    if(change)
    vec1.PB(index + 1);
    statu[index] = change;
    FOR(i,0,g[index].size())
    {
        int v = g[index][i].first;
        int c = g[index][i].second ^ change;
        DFS1(v, (c != color), color);
    }
}
void DFS2(int index, int change, int color)
{
    if(statu2[index] != -1)
    {
        if(statu2[index] != change)
        {
            ok2 = false;
        }
        return;
    }
    if(change)
    vec2.PB(index + 1);
    statu2[index] = change;
    FOR(i,0,g[index].size())
    {
        int v = g[index][i].first;
        int c = g[index][i].second ^ change;
        DFS2(v, (c != color), color);
    }
}
int color;

LL solve()
{
    LL ans[2];
    ZERO(ans);


    FOR(c,0,2)
    {
        NEG(statu);
        NEG(statu2);
        FOR(i,0,n)
        {
            if(statu[i] != -1)
                continue;
            ok1 = true;
            ok2 = true;
            vec1.clear();
            vec2.clear();
            DFS1(i,0,c);
            DFS2(i,1,c);
            int res = INF;
            if(ok1)
                res = min(res, (int)vec1.size());
            if(ok2)
                res = min(res, (int)vec2.size());
            ans[c] += res;
            if(res == vec1.size())
            {
                FOR(j,0,vec1.size())
                v[c].PB(vec1[j]);
            }
            else
            {
                FOR(j,0,vec2.size())
                v[c].PB(vec2[j]);
            }
        }
    }
    if(ans[0] >= INF && ans[1] >= INF)
        return -1;
    if(ans[0] <= ans[1])
        color = 0;
    else
        color = 1;
    return min(ans[0], ans[1]);
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);
    cin >> n >> m;
    FOR(i,0,m)
    {
        int x, y;
        char c;
        cin >> x >> y >> c;
        x--;
        y--;
        if(c == 'B')
        {
            g[x].PB(MP(y, 0));
            g[y].PB(MP(x, 0));
        }
        else
        {
            g[x].PB(MP(y, 1));
            g[y].PB(MP(x, 1));
        }
    }
    LL res = solve();
    if(res != -1)
    {
        cout << res << endl;
        FOR(i,0,v[color].size())
        cout << v[color][i] << " ";
        cout << endl;
    }
    else
        cout << res << endl;
    return 0;
}