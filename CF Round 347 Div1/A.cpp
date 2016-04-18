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
string s;
vector<string> a;
vector<int> p;
vector<int> m;
int n;
int solve()
{
    n = stoi(a.back());
    int cnt1 = 0,cnt2 = 0;
    FOR(i,0,a.size())
    {
        if(a[i] == "+")
            cnt1++;
        else if(a[i] == "-")
            cnt2++;
    }
    int high = (cnt1 + 1) * n - cnt2 * 1;
    int low = (cnt1 + 1) * 1 - cnt2 * n;
    if(n < low || n > high)
        return 0;

    FOR(i,0,cnt1 + 1)
    p.PB(1);
    FOR(i,0,cnt2)
    m.PB(n);
    int diff = n - low;
    if(diff == 0)
        return 1;
    FOR(i,0,p.size())
    {
        int add = min(n - p[i], diff);
        p[i] += add;
        diff -= add;
        if(diff == 0)
            break;
    }
    if(diff == 0)
        return 1;
    FOR(i,0,m.size())
    {
        int add = min(m[i] - 1, diff);
        m[i] -= add;
        diff -= add;
        if(diff == 0)
            break;
    }
    return 1;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);
    while(cin >> s)
    {
        a.PB(s);
        if(s == "=")
        {
            string x;
            cin >> x;
            a.PB(x);
            break;
        }
    }
    int res = solve();
    if(res)
    {
        cout << "Possible" << endl;
        cout << p[0] << " ";
        int start = 1;
        int start2 = 0;
        FOR(i,1,a.size())
        {
            if(a[i] == "?")
            {
                if(a[i - 1] == "+")
                    cout << p[start++] << " ";
                else
                    cout << m[start2++] << " ";
            }
            else
                cout << a[i] << " ";
        }
        cout << endl;
    }
    else
        cout << "Impossible" << endl;
    return 0;
}