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
int m,n,p;
int b[310][310];
vector<vector<pair<int,int> > > a;
int dp[310][310];
vector<int> row[310];
vector<int> col[310];
int solve()
{
    FUL(dp);
    a.resize(p + 2);
    FOR(i,0,m)
    FOR(j,0,n)
        a[b[i][j]].PB(MP(i,j));
    FOR(i,0,a[1].size())
    {
        int x = a[1][i].first;
        int y = a[1][i].second;
        dp[x][y] = x + y;
    }
    FOR(i,1,p)
    {
        FOR(j,0,m)
        row[j].clear();
        FOR(j,0,n)
        col[j].clear();
        vector<pair<int,int> > &vec1 = a[i];
        FOR(j,0,vec1.size())
        {
            row[vec1[j].first].PB(vec1[j].second);
            col[vec1[j].second].PB(vec1[j].first);
        }
        FOR(j,0,m)
            sort(ALL(row[j]));
        FOR(j,0,n)
            sort(ALL(col[j]));
        vector<pair<int,int> > &vec2 = a[i + 1];
            FOR(k,0,vec2.size())
            {
                int xb = vec2[k].first;
                int yb = vec2[k].second;
                FOR(j,0,m)
                {
                    vector<int> &r = row[j];
                    if(r.size() == 0)
                        continue;
                    int xa = j;
                    auto low = lower_bound(ALL(r), yb);
                    if(low == r.end())
                        low--;
                    int ya = *low;
                    dp[xb][yb] = min(dp[xb][yb], dp[xa][ya] + abs(xa - xb) + abs(ya - yb));
                    if(low != r.begin())
                    {   
                        low--;
                        ya = *low;
                        dp[xb][yb] = min(dp[xb][yb], dp[xa][ya] + abs(xa - xb) + abs(ya - yb));
                    }
                }
                FOR(j,0,n)
                {
                    vector<int> &r = col[j];
                    if(r.size() == 0)
                        continue;
                    int ya = j;
                    auto low = lower_bound(ALL(r), xb);
                    if(low == r.end())
                        low--;
                    int xa = *low;
                    dp[xb][yb] = min(dp[xb][yb], dp[xa][ya] + abs(xa - xb) + abs(ya - yb));
                    if(low != r.begin())
                    {   
                        low--;
                        xa = *low;
                        dp[xb][yb] = min(dp[xb][yb], dp[xa][ya] + abs(xa - xb) + abs(ya - yb));
                    }
                }

            }
    }
    return dp[a[p][0].first][a[p][0].second];
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    cin >> m >> n >> p;
    FOR(i,0,m)
    FOR(j,0,n)
    cin >> b[i][j];
    cout << solve() << endl;
    return 0;
}