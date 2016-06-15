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

LL a, b ,n ,x;
LL fastpow(LL aa ,LL nn)
{
    if(nn == 1)
        return aa;
    LL res = fastpow(aa, nn / 2);
    res *= res;
    res %= MOD;
    if(nn % 2 == 0)
        return res;
    else
        return (res * aa) % MOD;
}
LL solve()
{
    // a^n * x + b (1 + a + a^2 + ... + a^(n - 1)) = a^n * x + b * (a^n - 1) / (a - 1)
    if(a == 1)
        return (x + b * (n % MOD)) % MOD;
    LL aa = fastpow(a, n);
    LL res = 0;
    res += (aa * x) % MOD;
    LL tmp = (b * (aa - 1)) % MOD;
    tmp *= fastpow(a - 1, MOD - 2);
    tmp %= MOD;
    return (res + tmp) % MOD;

}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    cin >> a >> b >> n >> x;
    cout << solve() << endl;
    return 0;
}