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

int n,k;
LL h;
int c[500100];
bool valid2(int val)
{
    LL res = 0;
    FOR(i,0,n)
    {
        if(c[i] < val)
            res += (val - c[i]);
    }
    if(res > k)
        return false;
    return true;
}
bool valid(int val)
{
    LL res = 0;
    FOR(i,0,n)
    {
        if(c[i] > val)
            res += (c[i] - val);
    }
    if(res > k)
        return false;
    return true;
}
LL solve()
{
    sort(c, c + n);
    int low = 1;
    int high = 0;
    LL sum = 0;
    FOR(i,0,n)
    {
        sum += c[i];
        high = max(high, c[i]);
    }
    if(sum % n == 0)
        low = sum / n;
    else
        low = sum / n + 1;
    while(low < high)
    {
        LL mid = (low + high) / 2;
        if(valid(mid))
            high = mid;
        else
            low = mid + 1;
    }
    h = low;
    low = 1;
    high = h;
    if(sum % n != 0)
        high = h - 1;
    while(low < high)
    {
        LL mid = (low + high + 1) / 2;
        if(valid2(mid))
            low = mid;
        else
            high = mid - 1;
    }
    debug(low);
    return h - low;
 
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    cin >> n >> k;
    FOR(i,0,n)
    cin >> c[i];
    cout << solve() << endl;
    return 0;
}