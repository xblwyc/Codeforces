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

LL n,m;
set<LL> uset;
void solve()
{
    vector<LL> res;
    for(LL i = 1; i <= 1e9; i++)
    {
        if(m < i)
            break;
        if(uset.count(i) == 1)
            continue;
        res.PB(i);
        m -= i;
    }
    cout << res.size() << endl;
    FOR(i,0,res.size())
    cout << res[i] << " ";
    cout << endl;
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    cin >> n >> m;
    LL x;
    FOR(i,0,n)
    {
        cin >> x;
        uset.insert(x);
    }
    solve();
    return 0;
}