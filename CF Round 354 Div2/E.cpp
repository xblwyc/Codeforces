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
int a[100100];
bool valid()
{
    vector<LD> aa;
    FOR(i,0,n + 1)
    aa.PB(a[i]);
    FOR(i,0,n)
    {
        LD add = aa.back() * k;
        aa.pop_back();
        aa.back() += add;
    }
    return aa.back() == 0;
}
string solve()
{
    vector<pair<int,int> > aa;
    FOR(i,0,n + 1)
    {
        if(aa.size() == 0 || ((a[i] == INF) != aa.back().first))
            aa.PB(MP(a[i] == INF, 1));
        else
            aa.back().second++;
    }
    if(aa.size() == 1 && aa[0].first == 0)
    {
        if(valid())
            return "Yes";
        else
            return "No";
    }
    int cnt1 = 0;
    int cnt2 = 0;
    FOR(i,0,n + 1)
    {
        if(a[i] == INF)
            cnt1++;
    }
    cnt2 = n + 1 - cnt1;
    if(k == 0)
    {
        if(a[0] == 0)
            return "Yes";
        else if(a[0] == INF)
        {
            if(cnt2 % 2 != 0)
                return "Yes";
        }
        return "No";

    }
    if(cnt1 % 2 == 0)
    {
        if(cnt2 % 2 == 0)
        {
            return "Yes";
        }
        else
            return "No";
    }
    else
    {
        if(cnt2 % 2 == 0)
            return "No";
        else
            return "Yes";
    }
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    cin >> n >> k;
    FOR(i,0,n + 1)
    {
        string s;
        cin >> s;
        if(s == "?")
            a[i] = INF;
        else
            a[i] = stoi(s);
    }
    cout << solve() << endl;
    return 0;
}