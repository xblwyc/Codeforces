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
string s;
LL conv(char c)
{
    if(c <= '9' && c >= '0')
        return c - '0';
    if(c <= 'z' && c >= 'a')
        return c - 'a' + 36;
    if(c <= 'Z' && c >= 'A')
        return c - 'A' + 10;
    if(c == '-')
        return 62;
    if(c == '_')
        return 63;
}
LL solve()
{
    LL res = 1;
    FOR(i,0,s.size())
    {
        char c = s[i];
        LL val = conv(c);
        for(int j = 0; j < 6; j++, val >>= 1)
        {
            if(val & 1)
            {

            }
            else
            {
                res *= 3;
                res %= MOD;
            }
        }
    }
    return res;
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    cin >> s;
    cout << solve() << endl;
    return 0;
}