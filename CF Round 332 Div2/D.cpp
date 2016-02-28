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
#define INF 5e8
inline long double min(long double a , long double b) {if(a < b)return a; return b;}
inline long double max(long double a , long double b) {if(a < b)return b; return a;}


LL x;
set<pair<LL,LL> > res;
LL calc(int k)
{
    LL res = 1;
    res *= k;
    res *= (k + 1);
    res *= (2*k + 1);
    res /= 6;
    return res;
}
void solve()
{
    for(int k = 1; k <= 10e6 + 1 && calc(k) <= x; k++)
    {
        LL temp = x - calc(k);
        LL temp1 = 1LL * k * (k + 1) / 2;
        if(temp % temp1 == 0)
        {
            LL temp2 = temp / temp1;
            res.insert(MP(k,k + temp2));
            res.insert(MP(k + temp2, k));
        }
    }
}
int  main()
{

    cin >> x;
    solve();
    cout << res.size() << endl;
    ITE(i,res)
    cout << i->first << " " << i->second << endl;
    return 0;
    
}