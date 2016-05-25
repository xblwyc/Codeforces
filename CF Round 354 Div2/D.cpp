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
int m,n;
int b[1010][1010][4];
int xa,ya,xb,yb;
int d[1010][1010][4];
int dirx[4] = {0,-1,0,1};
int diry[4] = {1,0,-1,0};
struct node
{
    int x,y,ro,t;
};
bool check(int x ,int y, int nx, int ny,int ro)
{
    if(nx < 0 || nx >= m)
        return false;
    if(ny < 0 || ny >= n)
        return false;
    int w1[4];
    FOR(i,0,4)
    w1[(i + ro) % 4] = b[x][y][i];
    int w2[4];
    FOR(i,0,4)
    w2[(i + ro) % 4] = b[nx][ny][i];
    if(x + 1 == nx)
    {
        if(w1[3] == 1 && w2[1] == 1)
            return true;
        return false;
    }
    if(x - 1 == nx)
    {
        if(w1[1] == 1 && w2[3] == 1)
            return true;
        return false;
    }
    if(y + 1 == ny)
    {
        if(w1[2] == 1 && w2[0] == 1)
            return true;
        return false;
    }
    if(y - 1 == ny)
    {
        if(w1[0] == 1 && w2[2] == 1)
            return true;
        return false;
    }
    return false;

}
int solve()
{
    FUL(d);
    queue<node> q;
    q.push(node{xa,ya,0,0});
    d[xa][ya][0] = 0;
    while(q.size())
    {
        int x = q.front().x;
        int y = q.front().y;
        int ro = q.front().ro;
        int t = q.front().t;
        if(x == xb && y == yb)
            return t;
        q.pop();
        int nro = (ro + 1) % 4;
        if(d[x][y][nro] == INF)
        {
            d[x][y][nro] = t + 1;
            q.push(node{x,y,nro,t + 1});
        }
        FOR(i,0,4)
        {
            int nx = x + dirx[i];
            int ny = y + diry[i];
            if(nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;
            if(check(x,y,nx,ny, ro))
            {   
                if(d[nx][ny][ro] == INF)
                {
                    d[nx][ny][ro] = t + 1;
                    q.push(node{nx,ny,ro, t + 1});
                }
            }
        }
    }
    return -1;
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    cin >> m >> n;
    ZERO(b);
    FOR(i,0,m)
    FOR(j,0,n)
    {
        char c;
        cin >> c;
        if(c == '+')
            b[i][j][0] = b[i][j][1] = b[i][j][2] = b[i][j][3] = 1;
        else if(c == '-')
            b[i][j][0] = b[i][j][2] = 1;
        else if(c == '|')
            b[i][j][1] = b[i][j][3] = 1;
        else if(c == '^')
            b[i][j][1] = 1;
        else if(c == '>')
            b[i][j][2] = 1;
        else if(c == '<')
            b[i][j][0] = 1;
        else if(c == 'v')
            b[i][j][3] = 1;
        else if(c == 'L')
            b[i][j][1] = b[i][j][2] = b[i][j][3] = 1;
        else if(c == 'R')
            b[i][j][0] = b[i][j][1] = b[i][j][3] = 1;
        else if(c == 'U')
            b[i][j][0] = b[i][j][2] = b[i][j][3] = 1;
        else if(c == 'D')
            b[i][j][0] = b[i][j][1] = b[i][j][2] = 1;
    }
    cin >> xa >> ya >> xb >> yb;
    xa--;
    ya--;
    xb--;
    yb--;
    cout << solve() << endl;
    return 0;
}