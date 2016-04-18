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
string s;
int y[10] = {1990, 1991,1992,1993,1994,1995,1996,1997,1998,1989};
string solve()
{
    reverse(ALL(s));
    int start = y[s[0] - '0'];
    vector<int> res(100,0);
    FOR(i,0,4)
    {
        res[i] = start % 10;
        start /= 10;
    }
    start = 1;

    FOR(i,1,s.size())
    {
        int val = s[i] - '0';
        if(res[start] >= 10)
        {
            res[start + 1]++;
            res[start] %= 10;
        }
            if(val > res[start])
                res[start] = val;
            else
                res[start] = 10 + val;
        if(res[start] >= 10)
        {
            res[start + 1]++;
            res[start] %= 10;
        }
        start++;
    }
    FOR(i,0,res.size() - 1)
    {
        if(res[i] >= 10)
        {
            int c = res[i] / 10;
            res[i] %= 10;
            res[i + 1] += c;
        }
    }
    
    string ans;
    start = res.size() - 1;
    while(start >= 0 && res[start] == 0)
        start--;
    for(int i = start; i >= 0; i--)
    {
        ans.PB(res[i] + '0');
    }
    return ans;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);
    cin >> n;
    FOR(i,0,n)
    {
        cin >> s;
        s = s.substr(4);
        cout << solve() << endl;
    }
    return 0;
}