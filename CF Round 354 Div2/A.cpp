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
int a[110];
int check()
{
    int index1 = 0;
    int index2 = 0;
    FOR(i,1,n)
    {
        if(a[i] > a[index1])
            index1 = i;
        if(a[i] < a[index2])
            index2 = i;
    }
    return abs(index1 - index2);
}
int solve()
{
    int res = 0;
    FOR(i,0,n)
    {
        FOR(j,i,n)
        {
            swap(a[i],a[j]);
            res = max(res,check());
            swap(a[i],a[j]);
        }
    }
    return res;
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    cin >> n;
    FOR(i,0,n)
    cin >> a[i];
    cout << solve() << endl;
    return 0;
}