#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <cmath>
#include <climits>
#include <utility>
#include <fstream>
#include <memory>
#include <set>
#include <iomanip>
#include <map>
#include <stack>
using namespace std;
#define debug(v) cout << "Variable is " << v << endl;
#define PA(A,i,n) for(int i = 0; i < n; i++) cout << A[i] << " "; cout << endl;
#define FOR(a, b, n) for(int (a) = (b); (a) < (n); ++(a))
#define FORE(a, b, n) for(int (a) = (b); (a) <= (n); ++(a))
#define ITE(a, v) for(auto (a) = v.begin(); (a) != v.end(); ++(a))
#define LL long long
#define ALL(v) v.begin(),v.end()
#define ZERO(v) memset(v, 0, sizeof v)
#define NEG(v)  memset(v, -1, sizeof v)
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MOD 1000000007
#define PI 3.141592653589793
#define INF 0x3f3f3f3f
inline long  double min(long double a , long double b) {if(a < b)return a; return b;}
inline long  double max(long double a , long double b) {if(a < b)return b; return a;}
LL n,a,b,p,q;

LL solve()
{
    LL aa = n / a;
    LL bb = n / b;
    LL G = __gcd(a, b);
    LL c = a / G * b;
    LL cc = n / c;
    LL res = (aa - cc) * p + (bb - cc) * q;
    if(p > q)
        res += cc * p;
    else
        res += cc * q;
    return res;
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    cin >> n >> a >> b >> p >> q;
    cout << solve() << endl;
    return 0;
}