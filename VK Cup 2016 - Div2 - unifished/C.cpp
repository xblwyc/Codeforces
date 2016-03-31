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

int n,m;
int arr[200100];
pair<int,int> op[200100];
int suffix[200100];
void solve()
{
    suffix[m] = 0;
    for(int i = m - 1; i >= 0; i--)
        suffix[i] = max(suffix[i + 1], op[i].second);
    vector<pair<int,int> > ops;
    for(int i = 0; i < m; i++)
    {
        if(op[i].second > suffix[i + 1])
        {
            if(ops.size() == 0 || op[i].first != ops.back().first)
                ops.PB(op[i]);
        }
    }
    sort(arr, arr + ops[0].second);
    deque<int> dq;
    FOR(i,0, ops[0].second)
    dq.push_back(arr[i]);
    int pos = ops[0].second - 1;
    FOR(i,0,ops.size())
    {
        int stop;
        if(i == ops.size() - 1)
            stop = 0;
        else
            stop = ops[i + 1].second;
        if(ops[i].first == 1)
        {
            while(pos >= stop)
            {
                
                arr[pos] = dq.back();
                dq.pop_back();
                pos--;
            }
        }
        else
        {
            while(pos >= stop)
            {
                arr[pos] = dq.front();
                dq.pop_front();
                pos--;
            }
        }
    }
}
int  main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    cin >> n >> m;
    FOR(i,0,n)
    cin >> arr[i];
    FOR(i,0,m)
    cin >> op[i].first >> op[i].second;
    
    solve();
    FOR(i,0,n)
    cout << arr[i] << " ";
    cout << endl;
    return 0;
}