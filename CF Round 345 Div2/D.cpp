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
#include <set>
#include <iterator>
#include <iomanip>
#include <map>
#include <stack>
using namespace std;
#define debug(x) ITE(a,x) cout << *a << " "; cout << endl;
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
#define pw(x) (1LL << (x))
#define sqr(x) ((x)*(x))
#define CC(x) cout << (x) << endl;
#define PB push_back
#define MP make_pair
#define MOD 1000000007
#define PI 3.141592653589793
#define INF 0x3f3f3f3f
inline long  double min(long double a , long double b) {if(a < b)return a; return b;}
inline long  double max(long double a , long double b) {if(a < b)return b; return a;}

#define N 1001100
int m,n;
int arr[N];
int arrT[N];
int root[N];
int val[N];
int row[N];
int col[N];

int find(int i) {
    return i == root[i] ? i : root[i] = find(root[i]);
}

void uni(int u, int v) {
    u = find(u); v = find(v);
    root[v] = u;
    //sz[u] += sz[v];
}
void solve()
{
    FOR(i,0,N)
    root[i] = i;
    FOR(i,0,m)
    {
        map<int,int> umap;
        FOR(j,0,n)
        {
            if(umap.count(arr[i * n + j]) != 0)
            {
                uni(i * n + j, umap[arr[i * n + j]]);
            }
            umap[arr[i * n + j]] = i * n + j;
        }
    }
    FOR(j,0,n)
    {
        map<int,int> umap;
        FOR(i,0,m)
        {
            if(umap.count(arr[i * n + j]) != 0)
            {
                uni(i * n + j, umap[arr[i * n + j]]);
            }
            umap[arr[i * n + j]] = i * n + j;
        }
    }
    vector<pair<int,int> > tmp;
    FOR(i,0,m)
    FOR(j,0,n)
    tmp.PB(MP(arr[i * n + j], i * n + j) );
    sort(ALL(tmp));
    ZERO(col);
    ZERO(row);
    ZERO(val);
    vector<int> buf;

    FOR(i,0,tmp.size())
    {
        int pos = tmp[i].second;
        int v = max(row[pos / n], col[pos % n]) + 1;
        val[find(pos)] = max(val[find(pos)], v);
        if(i == tmp.size() - 1 || tmp[i].first != tmp[i + 1].first)
        {
            int p = i;
            while(p >= 0 && tmp[p].first == tmp[i].first)
            {
                int ppos = tmp[p].second;
                row[ppos / n] = max(row[ppos/ n], val[find(ppos)]);
                col[ppos % n] = max(col[ppos % n], val[find(ppos)]);
                p--;
            }
        }
    }
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    cin >> m >> n;
    FOR(i,0,m)
    FOR(j,0,n)
    cin >> arr[i * n + j];
    solve();
    FOR(i,0,m)
    {
        FOR(j,0,n)
        cout << val[find(i * n + j)] << " ";
        cout << endl;
    }
    return 0;
}