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
#define INF 0x3f3f3f3f
inline long  double min(long double a , long double b) {if(a < b)return a; return b;}
inline long  double max(long double a , long double b) {if(a < b)return b; return a;}

vector<string> split(string s, string c)
{
    unsigned long pos2 = s.find(c);
    unsigned long pos1 = 0;
    vector<string> res;
    while(pos2 != s.size())
    {
        res.PB(s.substr(pos1, pos2 - pos1));
        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if(pos1 != s.size())
        res.PB(s.substr(pos1));
    return res;
}

string s1;
string s2;
LL solve()
{
    LL res = 0;
    int pos = s1.find(s2);
    while(pos != -1 && pos < s1.size())
    {
        res++;
        int poss = pos + s2.size();
        if(poss >= s1.size())
            break;
        pos = s1.find(s2, poss);
    }
    return res;
}
int  main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    cin >> s1 >> s2;

    cout << solve() << endl;
    return 0;
    
}