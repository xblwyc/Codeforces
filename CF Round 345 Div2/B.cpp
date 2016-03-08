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


int n;
int arr[1010];
multiset<int> uset;
int solve()
{
    FOR(i,0,n)
    uset.insert(arr[i]);
    int arrT[1010];
    int last = -1;
    FOR(i,0,n)
    {
        auto val = uset.upper_bound(last);
        if(val == uset.end())
        {
            last = -1;
            val = uset.upper_bound(last);
        }
        arrT[i] = *val;
        last = arrT[i];
        uset.erase(val);
    }
    int res = 0;
    FOR(i,1,n)
    {
        if(arrT[i] > arrT[i - 1])
            res++;
    }
    return res;
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    cin >> n;
    FOR(i,0,n)
    cin >> arr[i];
    cout << solve() << endl;
    return 0;
}