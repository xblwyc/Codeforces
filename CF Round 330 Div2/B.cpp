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
inline long double min(long double a , long double b) {if(a < b)return a; return b;}
inline long double max(long double a , long double b) {if(a < b)return b; return a;}

int n;
int k;
int b[100100];
int a[100100];
int powTen(int kk)
{
    int res=  1;
    while(kk)
    {
        res *= 10;
        kk--;
    }
    return res;
}
LL solve(int index)
{
    int aa = a[index];
    int bb = b[index];
    int end = powTen(k) - 1;
    end = end/aa * aa;
    int tot = end / aa + 1;
    int start = bb * powTen(k - 1);
    end = (bb + 1) * powTen(k - 1) - 1;
    end = end / aa * aa;
    if(start % aa != 0)
        start = (start / aa + 1) * aa;
    if(end >= start)
    {
        tot -= (end - start) / aa;
        tot--;
    }
    return tot;
}
int main(){

    cin >> n;
    cin >> k;
    FOR(i,0,n/k)
    scanf("%d", &a[i]);
    FOR(i,0,n/k)
    scanf("%d", &b[i]);
    LL res = 1;
    FOR(i,0,n/k)
    {
        res *= solve(i);
        res %= MOD;
    }
    cout << res << endl;
    return 0;
}