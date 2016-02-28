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


int n;
int m;
int b[100100];
int f[100100];
vector<int> pos[100100];
vector<int> res;
int solve()
{
    
    bool flag = true;
    FOR(i,0,m)
    {
        int val = b[i];
        if(pos[val].size() > 1)
        {
            flag = false;
        }
        else if(pos[val].size() == 0)
        {
            return -1;
        }
        else
            res.PB(pos[val][0]);
        
    }
    if(flag == false)
        return 0;
    return 1;
    
}
int  main()
{

    cin >> n;
    cin >> m;
    FOR(i,0,n)
    scanf("%d", &f[i]);
    FOR(i,0,m)
    scanf("%d", &b[i]);
    FOR(i,0,n)
    {
        pos[f[i]].PB(i);
    }
    int ress = solve();
    if(ress == 1)
    {
        cout << "Possible" << endl;
        FOR(i,0, res.size())
        cout << res[i]  + 1<< " ";
        cout << endl;
    }
    else if(ress ==0)
        cout << "Ambiguity" << endl;
    else
        cout <<"Impossible" << endl;
    return 0;
    
}