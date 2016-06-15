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
string a[100100];
int x[100100];
void solve()
{
    vector<pair<string,int> > res;
    priority_queue<int, vector<int>, greater<int>> q;
    FOR(i,0,n)
    {
        if(a[i] == "insert")
        {
            res.PB(MP(a[i], x[i]));
            q.push(x[i]);
        }
        else if(a[i] == "removeMin")
        {
            if(q.size() == 0)
            {
                res.PB(MP("insert", 1));
                res.PB(MP(a[i], x[i]));
            }
            else
            {
                res.PB(MP(a[i], x[i]));
                q.pop();
            }
        }
        else
        {
            if(q.size() == 0)
            {
                q.push(x[i]);
                res.PB(MP("insert", x[i]));
                res.PB(MP(a[i],x[i]));
            }
            else
            {
                while(q.size() && q.top() < x[i])
                {
                    q.pop();
                    res.PB(MP("removeMin", 1));
                }
                if(q.size() && q.top() == x[i])
                {
                    res.PB(MP(a[i], x[i]));
                }
                else
                {
                    q.push(x[i]);
                    res.PB(MP("insert", x[i]));
                    res.PB(MP(a[i],x[i]));
                }

            }
        }
    }
    cout << res.size() << endl;
    FOR(i,0,res.size())
    {
        if(res[i].first == "removeMin")
        {
            cout << res[i].first << endl;
        }
        else
            cout << res[i].first << " " << res[i].second << endl;
    }
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    cin >> n;
    FOR(i,0,n)
    {
        cin >> a[i];
        if(a[i] != "removeMin")
            cin >> x[i];
    }
    solve();
    return 0;
}