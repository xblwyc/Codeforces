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
int n;
struct CAKE{
    int index, r,h;
    LL vol;
} cake[100100];
LL tree[4 * 100100];
bool comp(CAKE a, CAKE b)
{
    LL t1 = 1LL * a.r * a.r * a.h;
    LL t2 = 1LL *b.r * b.r * b.h;
    if(t1 == t2)
        return a.index > b.index;
    return t1 < t2;
}

void build(int x, int l, int r)
{
    if(l == r)
    {
        tree[x] = 0;
        return;
    }
    int m = (l + r) / 2;
    build(x * 2 + 1, l, m);
    build(x * 2 + 2, m + 1, r);
    tree[x] = 0;
}
void update(LL val, int pos,int x, int l, int r)
{
    int m = (l + r) / 2;
    if(pos <= l && pos >= r)
    {
        tree[x] = val;
        return;
    }
    if(pos < l)
        return;
    if(pos > r)
        return;
    update(val, pos, x * 2 + 1, l, m);
    update(val, pos, x * 2 + 2, m + 1, r);
    tree[x] = max(tree[x * 2 + 1], tree[x * 2 + 2]);
}
LL query(int L, int R, int x ,int l, int r)
{
    if(L <= l && R >= r)
    {
        return tree[x];
    }
    if(R < l)
        return 0;
    if(L > r)
        return 0;
    int m = (l + r) / 2;
    return max(query(L, R, x * 2 + 1, l, m), query(L, R, x * 2 +2, m + 1, r));
}
int  main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    cout << setprecision(15);
    cin >> n;
    FOR(i,0,n)
    {
        cin >> cake[i].r;
        cin >> cake[i].h;
        cake[i].index = i;
        cake[i].vol = 1LL * cake[i].r * cake[i].r  * cake[i].h;
       // cout << cake[i].vol << endl;
    }
   // cout << "hah" << endl;
   // ZERO(c);
    sort(cake, cake + n , comp);
    LL res = 0;
    build(0,0, n - 1 );
    for(int i = 0; i < n; i++ )
    {
        int ind = cake[i].index;
        LL temp = query(0, ind - 1, 0, 0, n - 1);
        res = max(res, temp + cake[i].vol);
        update(temp + cake[i].vol,ind, 0, 0,n - 1);
    }
    cout << res * PI << endl;
    return 0;
}