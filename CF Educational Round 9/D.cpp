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

int n;
int m;
struct NODE
{
    int val;
    int index;
} arr[1000100];
int flag[1000100];
bool comp(NODE a ,NODE b)
{
    return a.val < b.val;
}
void solve()
{
    ZERO(flag);
    map<int,int> umap;
    FOR(i,0,n)
    umap[arr[i].val]++;
    ITE(i,umap)
    {
        int val = i->first;
        int cnt = i->second;
        for(int a = val; a <= m; a += val)
            flag[a] += cnt;
    }
    int ans = -1;
    int res = 0;
    for(int i = m; i >= 1; i--)
    {
        if(flag[i] >= res)
        {
            ans = i;
            res = flag[i];
        }
    }
    cout << ans << " " << res << endl;
    FOR(i,0,n)
    {
        if(ans % arr[i].val == 0)
            cout << i + 1 << " ";
    }
    cout << endl;
}
int  main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    cin >> n >> m;
    FOR(i,0,n)
    {
        cin >> arr[i].val;
        arr[i].index = i + 1;
    }
    solve();
    return 0;
}