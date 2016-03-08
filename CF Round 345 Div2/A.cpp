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


int a, b;
LL dp[1100][1100];
LL rec(int aa ,int bb)
{
    if(dp[aa][bb] != -1)
        return dp[aa][bb];
    if(aa == 1 && bb == 1)
        return 0;
    if(aa <= 0 || bb <= 0)
        return 0;
    if(aa == 1)
        return dp[aa][bb] = 1 + rec(aa + 1, bb - 2);
    if(bb == 1)
        return dp[aa][bb] = 1 + rec(aa - 2, bb + 1);
    return dp[aa][bb] = 1 + max(rec(aa - 2, bb + 1),rec(aa + 1, bb - 2));
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    NEG(dp);
    cin >> a >> b;
    cout << rec(a,b) << endl;
    return 0;
}