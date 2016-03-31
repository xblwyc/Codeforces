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
#define FORE(a, b, n) for(int (a) = (b); (a) <= (n); ++(a))
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

int n,m;
pair<LL,char> p[200200];
pair<LL,char> s[200200];
vector<pair<LL,char> > pp;
vector<pair<LL,char> > ss;
LL calc(int para)
{
    if(para == 1)
    {
        LL res = 0;
        FOR(i,0,n)
        {
            if(pp[0].second == ss[i].second && pp[0].first <= ss[i].first)
            {
                res += (ss[i].first - pp[0].first + 1LL);
            }
        }
        return res;
    }
    else
    {
        LL res = 0;
        FOR(i,0,n - 1)
        {
            if(pp[0].second == ss[i].second && pp[1].second == ss[i + 1].second && pp[0].first <= ss[i].first && pp[1].first <= ss[i + 1].first)
                res++;
        }
        return res;
    }
}
int pre[200200];
void getPre()
{
    int i = 0, j = -1;
    pre[0] = -1;
    while ( i < m )
    {
        if ( j == -1 || pp[i] == pp[j] )
            pre[++i] = ++j;
        else
            j = pre[j];
    }
}
vector<int> pos;
int kmp()
{
    int i   = 0, j = 0;
    int ans = 0;
    getPre();
    
    while ( i < n )
    {
        if ( j == -1 || ss[i] == pp[j] )
        {
            i++; j++;
        }else
            j = pre[j];
        if ( j == m )
        {
            ans++;
            pos.PB(i - m);
            j = pre[j];
        }
    }
    return(ans);
}
LL solve()
{
    FOR(i,0,m)
    {
        if(pp.size() == 0 || p[i].second != pp.back().second)
            pp.PB(p[i]);
        else
            pp.back().first += p[i].first;
    }
    FOR(i,0,n)
    {
        if(ss.size() == 0 || s[i].second != ss.back().second)
            ss.PB(s[i]);
        else
            ss.back().first += s[i].first;
    }
    m = pp.size();
    n = ss.size();
    if(m == 1 || m == 2)
        return calc(m);
    vector<pair<LL,char> > ppp = pp;
    pp.erase(pp.begin());
    pp.pop_back();
    int mm = m;
    m -= 2;
    kmp();
    m = mm;
    LL cnt = 0;
    FOR(i,0,pos.size())
    {
        int index = pos[i];
        if(index == 0 || index + m - 2 >= n)
            continue;
        if(ss[index - 1].second == ppp[0].second && ss[index - 1].first >= ppp[0].first)
        {
            if(ss[index + m - 2].second == ppp.back().second && ss[index + m - 2].first >= ppp.back().first)
                cnt++;
        }
    }
    return cnt;
}
int  main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    cin >> n >> m;
    string temp;
    FOR(i,0,n)
    {
        cin >> temp;
        int pos = temp.find('-');
        s[i].first = stoi(temp.substr(0,pos));
        s[i].second = temp.back();
    }
    FOR(i,0,m)
    {
        cin >> temp;
        int pos = temp.find('-');
        p[i].first = stoi(temp.substr(0,pos));
        p[i].second = temp.back();
    }
    cout << solve() << endl;
    return 0;
}