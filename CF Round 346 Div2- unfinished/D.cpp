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

int n;
pair<LL,LL> a[1010];
int calc(pair<LL,LL> b, pair<LL,LL> c, pair<LL,LL> d)
{
    LL res = (d.F - b.F) * (c.S - b.S) - (c.F -b.F) * (d.S - b.S);
    if(res < 0)
        return 1;
    else
        return 0;
}
int solve()
{
    int res = 0;
    FOR(i,0,n)
    {
        int prev = i - 1;
        int next = i + 1;
        if(prev < 0)
            prev += n;
        if(next >= n)
            next -= (n);
        res += calc(a[prev], a[i], a[next]);
    }
    return res;
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    cin >> n;
    FOR(i,0,n)
    cin >> a[i].F >> a[i].S;
    int u1,u2;
    cin >> u1 >> u2;
    cout << solve() << endl;
    return 0;
}