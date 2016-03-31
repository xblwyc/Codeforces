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

int m,n,k;
pair<int,pair<int,int> > op[100100];
set<int> row;
set<int> col;
int b[5010][5010];
void solve()
{
    ZERO(b);
    for(int i = k; i >= 0; i--)
    {
        int ops = op[i].first;
        int index = op[i].second.first;
        index--;
        int val = op[i].second.second;
        if(ops == 1)
        {
            if(row.count(index) != 0)
                continue;
            row.insert(index);
            FOR(j,0,n)
            {
                if(b[index][j] == 0)
                    b[index][j] = val;
            }
        }
        else
        {
            if(col.count(index) != 0)
                continue;
            col.insert(index);
            FOR(j,0,m)
            {
                if(b[j][index] == 0)
                    b[j][index] = val;
            }
        }
    }
    FOR(i,0,m)
    {
        FOR(j,0,n)
        cout << b[i][j] << " ";
        cout << endl;
    }
}
int  main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    cin >> m >> n >> k;
    FOR(i,0,k)
        cin >> op[i].first >> op[i].second.first >> op[i].second.second;
    solve();
    return 0;
}