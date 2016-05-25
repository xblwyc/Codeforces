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
int n, k;
string s;
int check(vector<int> &vec)
{
    if(vec.size() - 2 <= k)
        return n;
    int res = 0;
    for(int i = 0; i + k + 1 < vec.size(); i++)
    {
        int pos1 = vec[i];
        int pos2 = vec[i + k + 1];
        res = max(res, pos2 - 1 - pos1);
    }
    return res;
}
int solve()
{
    vector<int> a;
    vector<int> b;
    a.PB(-1);
    b.PB(-1);
    FOR(i,0,n)
    if(s[i] == 'a')
        a.PB(i);
    FOR(i,0,n)
    if(s[i] == 'b')
        b.PB(i);
    a.PB(n);
    b.PB(n);
    int res = max(check(a), check(b));
    return res;
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    cin >> n >> k;
    cin >> s;
    cout << solve() << endl;
    return 0;
}