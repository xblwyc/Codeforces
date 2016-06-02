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

char buff[1010][1010];
int dirx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int diry[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int n;
int a[1010][1010];
int dp[1010][1010][8];
int dd[1010][1010];
int c[1010][1010][8][4];
int vis[1010][1010][8];
LD lg[4];

int calc(int x, int y, int dir)
{
    if(x <= 0 || x > n || y <= 0 || y > n)
        return 0;
    if(dp[x][y][dir] != -1)
        return dp[x][y][dir];
    if(a[x][y] == 0)
        return dp[x][y][dir] = 0;
    dp[x][y][dir] = calc(x + dirx[dir], y + diry[dir], dir) + 1;
    return dp[x][y][dir];
}
void calc2(int x, int y, int dir)
{
    if(x <= 0 || x > n || y <= 0 || y > n)
        return;
    if(vis[x][y][dir])
        return;
    vis[x][y][dir] = 1;
    calc2(x + dirx[dir], y + diry[dir], dir);
    FOR(i,0,4)
    c[x][y][dir][i] = c[x + dirx[dir]][y + diry[dir]][dir][i];
    c[x][y][dir][a[x][y]]++;
}
LL solve()
{   
    lg[1] = 0;
    lg[2] = log(2);
    lg[3] = log(3);
    NEG(dp);
    ZERO(vis);
    FORE(i,0,n)
    FOR(k,0,8)
    dp[i][0][k] = dp[0][i][k] = dp[i][n + 1][k] = dp[n + 1][i][k] = 0;
    FUL(dd);
    ZERO(c);
    FORE(i,1,n)
    FORE(j,1,n)
    FOR(k,0,8)
    {
        dp[i][j][k] = calc(i,j,k);
        calc2(i,j,k);
    }
    pair<LD,pair<int, pair<int,int> > > res = MP(-1, MP(-1, MP(-1,-1)));
    int t2 = -1;
    int t3 = -1;
    FORE(i,1,n)
    FORE(j,1,n)
    {
        int d = INF;
        FOR(k,0,8)
        {
            if(k % 2 == 0)
                continue;
            d = min(d, dp[i][j][k]);
        }
        int two = 0;
        int three = 0;
        if(d != 0)
        {
            FOR(k,0,8)
            {
                if(k % 2 == 0)
                    continue;
                two += c[i + dirx[k]][j + diry[k]][k][2] - c[i + dirx[k] * d][j + diry[k] * d][k][2];
                three += c[i + dirx[k]][j + diry[k]][k][3] - c[i + dirx[k] * d][j + diry[k] * d][k][3];
            }
            if(a[i][j] == 2)
                two++;
            else if(a[i][j] == 3)
                three++;
            pair<LD,pair<int, pair<int,int> > > tmp = MP(two * lg[2] + three * lg[3], MP(0, MP(i,j)));
            if(tmp > res)
            {
                res = tmp;
                t2 = two;
                t3 = three;
            }
        }
        two = three = 0;
        d = INF;
        FOR(k,0,8)
        {
            if(k % 2 != 0)
                continue;
            d = min(d, dp[i][j][k]);
        }
        if(d != 0)
        {
            FOR(k,0,8)
            {
                if(k % 2 != 0)
                    continue;
                two += c[i + dirx[k]][j + diry[k]][k][2] - c[i + dirx[k] * d][j + diry[k] * d][k][2];
                three += c[i + dirx[k]][j + diry[k]][k][3] - c[i + dirx[k] * d][j + diry[k] * d][k][3];
            }
            if(a[i][j] == 2)
                two++;
            else if(a[i][j] == 3)
                three++;
            pair<LD,pair<int, pair<int,int> > > tmp = MP(two * lg[2] + three * lg[3], MP(1, MP(i,j)));
            if(tmp > res)
            {
                res = tmp;
                t2 = two;
                t3 = three;
            }
        }
    }
    if(t2 == -1 && t3 == -1)
        return 0;
    LL ans = 1;
    FOR(i,0,t2)
    {
        ans *= 2;
        ans %= MOD;
    }
    FOR(i,0,t3)
    {
        ans *= 3;
        ans %= MOD;
    }
    return ans;
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    cin >> n;
    FORE(i,1,n)
    FORE(j,1,n)
    cin >> buff[i][j];
    FORE(i,1,n)
    FORE(j,1,n)
    a[i][j] = buff[i][j] - '0';
    cout << solve() << endl;
    return 0;
}