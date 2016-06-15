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
int n;
LD a[20][20];
LD dp[1 << 18][20];
int final;
LD rec(int statu, int last)
{
    if(statu == final)
    {
        if(last == 0)
            return 1;
        else
            return 0;
    }
    if(dp[statu][last] != -1)
        return dp[statu][last];
    LD res = 0;
    FOR(i,0,n)
    {
        if(statu & (1 << i))
            continue;
        res = max(res, a[last][i] * rec(statu | (1 << i), last) + a[i][last] * rec(statu | (1 << i), i));
    }
    return dp[statu][last] = res;

}
LD solve()
{
    if(n == 1)
        return 1;
    LD res = 0;
    final = (1 << n) - 1;
    FOR(i,0,20)
    FOR(k,0,pw(n))
    dp[k][i] = -1;
    FOR(i,0,n)
    FOR(j,0,n)
    {
        if(i == j)
            continue;
        res = max(res, a[i][j] * rec((1 << i) | (1 << j), i) + a[j][i] * rec((1 << i) | (1 << j), j));
    }
    return res;
}
int  main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    cin >> n;
    FOR(i,0,n)
    FOR(j,0,n)
    cin >> a[i][j];
    cout << solve() << endl;
    return 0;
}