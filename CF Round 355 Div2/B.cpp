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
LL n, h, k;
LL a[100100];
// 3 10 5
// 1 2 2
LL solve()
{
    LL remain = 0;
    LL start = 0;
    LL res = 0;
    FOR(i,0,2 * n + 10)
    {
        if(start == n && remain == 0)
            break;
        bool add = false;
        while(start < n && h - remain >= a[start])
        {
            add = true;
            remain += a[start];
            start++;
        }
        if(add)
        {
                res += (remain / k);
                remain %= k;
        }
        else
        {
            res++;
            remain = 0;
        }

    }
    return res;

}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    cin >> n >> h >> k;
    FOR(i,0,n)
    cin >> a[i];
    cout << solve() << endl;
    return 0;
}