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
inline long double min(long double a , long double b) {if(a < b)return a; return b;}
inline long double max(long double a , long double b) {if(a < b)return b; return a;}

int n;
int r;
int v;
double s,f;
int fff;
int sss;
unordered_map<int,double> umap;
double ff(double val)
{
    return 2 * sin(val) * r + 2 * val * r;
}
double solve()
{
    if(umap[fff - sss] != 0)
        return umap[fff - sss];
    s = sss;
    f = fff;
    double circle = 2 * PI * r;
    double roundTime = circle / v;
    double res = 0;
    double times = (f - s) / circle;
    int timesInt = times;
    f -= timesInt * circle;
    res += roundTime * timesInt;
    double dis = f - s;
    double l = 0;
    double h = PI;
    //cout << dis << " " << res << endl;
    for(int i = 0; i < 100; i++)
    {
        double m = (l + h) / 2;
        if(ff(m) > dis)
            h = m;
        else
            l = m;
    }
    //cout << l / 2 / PI * 360 << endl;
    res += 2 * l * r / v;
    umap[fff-sss] = res;
    return res;
        
}
int main(){
    
    cout << setprecision(15);
    cin >> n;
    cin >> r >> v;
    FOR(i,0,n)
    {
        scanf("%d%d", &sss, &fff);
        cout << solve () << endl;
    }
    return 0;
}
