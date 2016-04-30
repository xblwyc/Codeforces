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
int dp[10010][4];
string s;
void solve()
{
    
    ZERO(dp);
    queue<pair<int,int> > q;
    if(s.size() - 3 + 1 > 4)
    q.push(MP(s.size() - 3, 2));
    if(s.size() - 4 + 1 > 4)
    q.push(MP(s.size() - 4, 3));
    set<string> uset;
    while(q.size())
    {
        int index = q.front().first;
        int last = q.front().second;
        q.pop();
        if(dp[index][last])
            continue;
        dp[index][last] = 1;
        if(last == 3)
            uset.insert(s.substr(index + 1, 3));
        if(last == 2)
            uset.insert(s.substr(index + 1, 2));
        if(index - 2 + 1 > 4)
        {
            if(last == 2)
            {
                if(s[index - 1] != s[index + 1] || s[index] != s[index + 2])
                    q.push(MP(index - 2, 2));
            }
            else
                q.push(MP(index - 2, 2));
        }
        if(index - 3 + 1 > 4)
        {
            if(last == 3)
            {
                if(s[index - 2] != s[index + 1] || s[index - 1] != s[index + 2] || s[index] != s[index + 3])
                    q.push(MP(index - 3, 3));
            }
            else
                q.push(MP(index - 3, 3));
        }
    }
    cout << uset.size() << endl;
    ITE(i, uset)
    cout << *i << endl;
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(false);
    cin >> s;
    
    solve();
    return 0;
}