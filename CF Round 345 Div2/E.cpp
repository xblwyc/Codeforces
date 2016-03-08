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
LL a,b;
LL T;
string s;
LL prefix[500100];
LL suffix[500100];
bool valid(int num)
{
    LL res = INT_MAX;
    for(int right = 1; right <= num; right++)
    {
        int left = num - right;
        LL costRight = prefix[right - 1];
        LL costLeft = 0;
        if(left != 0)
            costLeft = suffix[left - 1];
        LL cost = costRight + costLeft;
        cost += 1LL * min(right - 1, left) * a;
        res = min(res, cost);
    }
    return res <= T;
}
LL calc(int index)
{
    LL res = 1;
    if(s[index] == 'w')
        res += b;
    return res;
}
int solve()
{
    int tmp = 1;
    if(s[0] == 'w')
        tmp += b;
    if(tmp > T)
        return 0;
    prefix[0] = tmp;
    suffix[0] = calc(n - 1) + a;
    FOR(i,1,n)
    {
        prefix[i] = prefix[i - 1] + calc(i) + a;
    }
    FOR(i,1,n)
    {
        suffix[i] = suffix[i - 1] + calc(n - i - 1) + a;
    }
    
    int low = 1;
    int high = n;
    while(low < high)
    {
        int m = (low + high + 1) / 2;
        if(valid(m))
            low = m;
        else
            high = m - 1;
    }
    return low;
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    cin >> n >> a >> b>> T;
    cin >> s;
    cout << solve() << endl;
    return 0;
}