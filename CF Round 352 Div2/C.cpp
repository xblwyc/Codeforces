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
LL ax,ay,bx,by,tx,ty;
int n;
struct node
{
    LD da, db, dt;
    LL x, y;
    int index;
} a[100100];
node b[100100];
bool comp(node A, node B)
{
    LD tmp1 = A.da - A.dt;
    LD tmp2 = B.da - B.dt;
    return tmp1 < tmp2;
}

bool comp2(node A, node B)
{
    LD tmp1 = A.db - A.dt;
    LD tmp2 = B.db - B.dt;
    return tmp1 < tmp2;
}
LD solve()
{
    LD sum = 0;
    FOR(i,0,n)
    {
        a[i].index = i;
        LD da = sqrt(sqr(ax - a[i].x) + sqr(ay - a[i].y));
        LD db = sqrt(sqr(bx - a[i].x) + sqr(by - a[i].y));
        LD dt = sqrt(sqr(tx - a[i].x) + sqr(ty - a[i].y));
        a[i].da = da;
        a[i].db = db;
        a[i].dt = dt;
        sum += 2 * dt;
    }
    memcpy(b, a,sizeof(b));
    sort(a, a + n, comp);
    sort(b, b + n, comp2);
    LD res = min(sum - a[0].dt + a[0].da, sum - b[0].dt + b[0].db);
    FOR(i,0,min(n,2))
    {
        FOR(j,0,min(n,2))
        {
            if(a[i].index  == b[j].index)
                continue;
            res = min(res, sum - a[i].dt + a[i].da - b[j].dt + b[j].db);
        }
    }
    return res;

}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    cout << fixed;
    cout << setprecision(15);
    cin >> ax >> ay >> bx >> by >> tx >> ty;
    cin >> n;
    FOR(i,0,n)
    cin >> a[i].x >> a[i].y;
    cout << solve() << endl;
    return 0;
}