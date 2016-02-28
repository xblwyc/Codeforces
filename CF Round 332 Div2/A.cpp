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


int d1,d2,d3;
int  main()
{

    cin >> d1 >> d2 >> d3;
    d1 = min(d2 + d3, d1);
    d2 = min(d1 + d3, d2);
    d3 = min(d1 + d2, d3);
    cout << d1 + d2 + d3 << endl;
    return 0;
    
}