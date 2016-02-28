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
int arr[200010];
int main(){
    
    cin >> n;
    FOR(i,0,n)
    scanf("%d", &arr[i]);
    sort(arr,arr + n);
    int res = arr[n - 1] - arr[0];
    FOR(i,0,n/2)
    {
        res = min(res, arr[i + n / 2] - arr[i]);
    }
    cout << res << endl;
    return 0;
}