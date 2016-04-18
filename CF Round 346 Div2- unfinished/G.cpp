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
LL a[1000100];
LL dp[1000100][2];
LL solve()
{
    // dp[i][0]-> remain < h[i + 1], dp[i][1]->remain >= h[i + 1];
    ZERO(dp);
    dp[0][0] = dp[0][1] = 0;
    a[0] = 1e9;
    a[n + 1] = 1e9;
    FORE(i,1,n)
    {
        dp[i][0] += dp[i - 1][0] * (min(a[i + 1],min(a[i - 1], a[i])) - 1);
        dp[i][1] += dp[i - 1][0] * max(0LL, min(a[i - 1], a[i]) - a[i + 1]);
        dp[i][0] += min(a[i], a[i + 1]) - 1;
        dp[i][1] += max(0LL, a[i] - a[i + 1]);
        dp[i][0] %= MOD;
        dp[i][1] %= MOD;
    }
    LL res = 0;
    FORE(i,1,n)
    {
        res += (dp[i][0] + dp[i][1]);
        res %= MOD;
    }
    return res;
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    cin >> n;
    FORE(i,1,n)
    cin >> a[i];
    cout << solve() << endl;
    return 0;
}