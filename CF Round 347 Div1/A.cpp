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
#include <sstream>
#include <set>
#include <iterator>
#include <iomanip>
#include <map>
#include <stack>
using namespace std;
#define FOR(a, b, n) for(int (a) = (b); (a) < (n); ++(a))
#define FORE(a, b, n) for(int (a) = (b); (a) <= (n); ++(a))
#define ITE(a, v) for(auto (a) = v.begin(); (a) != v.end(); ++(a))
#define LL long long
#define ALL(v) v.begin(),v.end()
#define ZERO(v) memset(v, 0, sizeof v)
#define NEG(v)  memset(v, -1, sizeof v)
#define F first
#define S second
#define LD long double
#define pw(x) (1LL << (x))
#define sqr(x) ((x)*(x))
#define PB push_back
#define MP make_pair
#define MOD 1000000007
#define PI 3.141592653589793
#define PII pair<LL, LL>
#define INF 0x3f3f3f3f
#define FUL(x) memset(x, 0x3f, sizeof(x));
#define debug(args...) {cerr << #args << " = "; errDebug(args); cerr << endl;}
void errDebug() {}
template<typename T, typename... Args>
void errDebug(T a, Args... args) {
    cerr << a << ' ';
    errDebug(args...);
}
LL tenPow(int exp)
{
    LL res = 1;
    FOR(i,0,exp)
    res *= 10;
    return res;
}
pair<int,int> conv(string s)
{
    // 0.4(2) = x, 4.(2) = 10x , 42.(2) = 100x 90x = 38 x = 3
    // 0.000125(6);
    // 1239.00000(2);
    // (1239000002 - 123900000) / (10^6 - 10^5) 
    int pos = s.find("(");
    string s1 = s.substr(0,pos);
    string s2 = s.substr(pos + 1);
    pos = s1.find(".");
    string s11 = s1.substr(0,pos);
    string s12 = s1.substr(pos + 1);
    int first = stoi(s11);
    int second = stoi(s12);
    int third = stoi(s2);
    int base1 = tenPow(s11.size());
    int base2 = tenPow(s11.size() + s2.size());
    int dividend = first * base2 + second * base1 + third;
    dividend -= first * base1 + second;
    int divide = base2 - base1;
    int g = __gcd(dividend, divide);
    return MP(dividdend/g,  divide / g);



}
int main()
{

}