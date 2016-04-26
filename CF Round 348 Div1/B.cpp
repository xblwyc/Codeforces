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
int n, q;
int a[2][1000000];
int flag;
int ops;
int dir;
int start[2];
int len;
void solve()
{
    start[0] -= dir / 2;
    start[1] -= dir / 2;
    start[0] += len;
    start[1] += len;
    start[1] %= len;
    start[0] %= len;
}
int main() {

    scanf("%d%d", &n, &q);
    start[0] = start[1] = 0;
    len = n / 2;
    FOR(i,0,n)
    {
        if(i % 2 == 0)
        {
            a[0][start[0]++] = i + 1;
        }
        else
            a[1][start[1]++] = i + 1;
    }
    start[0] = start[1] = 0;
    flag = 0;
    FOR(i,0,q)
    {
        scanf("%d", &ops);
        if(ops == 2)
            flag ^= 1;
        else
        {
            scanf("%d", &dir);
            if(dir % 2 != 0)
            {
                dir++;
                start[flag]++;
                start[flag] += len;
                start[flag] %= len;
                flag ^= 1;
            }
            solve();
        }
    }
    FOR(i,0,n)
    {
        if(i % 2 == 0)
        {
            printf("%d ",a[flag][start[flag]++]);
        }
        else
            printf("%d ",a[flag ^ 1][start[flag ^ 1]++]);

        start[1] %= len;
        start[0] %= len;
    }
    cout << endl;
    return 0;
}