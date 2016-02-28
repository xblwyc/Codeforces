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

vector<string> split(string s, string c)
{
    unsigned long pos2 = s.find(c);
    unsigned long pos1 = 0;
    vector<string> res;
    while(pos2 != s.size())
    {
        res.PB(s.substr(pos1, pos2 - pos1));
        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if(pos1 != s.size())
        res.PB(s.substr(pos1));
    return res;
}
void add(LL &val1, LL val2)
{
    val1 += val2;
    if(val1 >= MOD)
        val1 %= MOD;
}
int n,m;
string s;
LL dp[2010][2010];
LL dp2[2010][2010];
LL solve()
{
    ZERO(dp);
    ZERO(dp2);
    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[0][1] = 0;
    FOR(l, 1, n - m + 1)
    {
        FOR(i,0,l + 1)
        {
            int op = i;
            int cl = l - i;
            add(dp[op + 1][cl], dp[op][cl]);
            if(op - cl >= 1)
                add(dp[op][cl + 1], dp[op][cl]);
        }
    }
    dp2[0][0] = 1;
    dp2[0][1] = 1;
    dp2[1][0] = 0;
    FOR(l, 1, n - m + 1)
    {
        FOR(i,0,l + 1)
        {
            int op = i;
            int cl = l - i;
            add(dp2[op][cl + 1], dp2[op][cl]);
            if(cl - op >= 1)
                add(dp2[op + 1][cl], dp2[op][cl]);
        }
    }
    
    int offset = 0;
    int diff = 0;
    FOR(i,0,m)
    {
        if(s[i] == '(')
            diff--;
        else
            diff++;
        offset = max(offset, diff);
    }
    LL res = 0;
    FOR(l1,0,n - m + 1)
    {
        int l2 = n - m - l1;
        FOR(i,0,l1 + 1)
        {
            int lOp = i;
            int lCl = l1 - i;
            if(lOp - lCl < offset)
                continue;
            int x1 = (l1 + l2 - 2 * i + diff) / 2;
            int x2 = (l2 - x1);
            if(x1 >= 0 && x2 >= 0 && x1 - x2 == (l1 - 2 * i + diff))
                add(res, 1LL * dp[i][l1 - i] * dp2[x1][x2]);
        }
    }
    return res;
    
}
int  main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);
   // n = 100000;
   // m = 100000 - 2000;
    cin >> n >> m;
    cin >> s;
    cout << solve() << endl;
    return 0;
}