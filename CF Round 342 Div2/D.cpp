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
string s;
int arr[100010];
int n;
int dp[100010][2][10];

string ans1;
string ans2;
int rec(int pos, int c1, int c2)
{
    if(dp[pos][c1][c2] != -1)
        return dp[pos][c1][c2];
    if(pos == n - 1 - pos)
    {
        int val = arr[pos];
        if(c1)
            val += 10;
        if(c2)
            val--;
        if(val % 2 == 0)
        {
            ans1[pos] = val / 2 + '0';
            return dp[pos][c1][c2] = 1;
        }return dp[pos][c1][c2] = 0;
    }
    if(pos + 1 == n - 1 - pos)
    {
        int val1 = arr[pos];
        int val2 = arr[n - 1 - pos];
        if(c1)
            val1 += 10;
        if(c2)
            val2--;
        int val = val1 * 10 + val2;
        dp[pos][c1][c2] = 0;
        for(int v1 = (pos == 0); v1 < 10; v1++)
        {
            for(int v2 = 0; v2 < 10 ;v2++)
            {
                if((v1 + v2) * 10 + v1 + v2 == val)
                {
                    ans1[pos] = '0' + v1;
                    ans1[pos + 1] = '0' + v2;
                    return dp[pos][c1][c2] = 1;
                }
            }
        }
        return dp[pos][c1][c2];
    }
    int val1 = arr[pos];
    int val2 = arr[n - 1 - pos];
    if(c1)
        val1 += 10;
    if(c2)
        val2--;
    dp[pos][c1][c2] = 0;
    for(int v1 = (pos == 0); v1 < 10; v1++)
    {
        for(int v2 = 0; v2 < 10 ;v2++)
        {
            if(v1 + v2 == val1 && v1 + v2 == val2 && rec(pos + 1, 0,0))
            {
                ans1[pos] = '0' + v1;
                ans1[n - 1 - pos] = '0' + v2;
                return dp[pos][c1][c2] = 1;
            }
            if(v1 + v2 + 1 == val1 && v1 + v2 == val2 && rec(pos + 1, 1, 0))
            {
                ans1[pos] = '0' + v1;
                ans1[n - 1 - pos] = '0' + v2;
                return dp[pos][c1][c2] = 1;
            }
            if(v1 + v2 + 1 == val1 && v1 + v2 - 10 == val2 && rec(pos + 1, 1, 1))
            {
                ans1[pos] = '0' + v1;
                ans1[n - 1 - pos] = '0' + v2;
                return dp[pos][c1][c2] = 1;
            }
            if(v1 + v2  == val1 && v1 + v2 - 10 == val2 && rec(pos + 1, 0, 1))
            {
                ans1[pos] = '0' + v1;
                ans1[n - 1 - pos] = '0' + v2;
                return dp[pos][c1][c2] = 1;
            }
        }
    }
    return dp[pos][c1][c2];
}
int rec2(int pos, int c1, int c2)
{

    if(dp[pos][c1][c2] != -1)
        return dp[pos][c1][c2];

    if(pos + 1 == n - 1 - pos)
    {
        int val = arr[pos + 1];
        if(c1)
            val += 10;
        if(c2)
            val--;
        if(val % 2 == 0)
        {
            ans2[pos] = val / 2 + '0';
            return dp[pos][c1][c2] = 1;
        }
        return dp[pos][c1][c2] = 0;
    }
    if(pos + 2 == n - 1 - pos)
    {
        int val1 = arr[pos + 1];
        int val2 = arr[n - 1 - pos];
        if(c1)
            val1 += 10;
        if(c2)
            val2--;
        int val = val1 * 10 + val2;
        dp[pos][c1][c2] = 0;
        for(int v1 = (pos == 0); v1 < 10; v1++)
        {
            for(int v2 = 0; v2 < 10 ;v2++)
            {
                if((v1 + v2) * 10 + v1 + v2 == val)
                {
                    ans2[pos] = '0' + v1;
                    ans2[pos + 1] = '0' + v2;
                    return dp[pos][c1][c2] = 1;
                }
            }
        }
        return dp[pos][c1][c2];
    }
    int val1 = arr[pos + 1];
    int val2 = arr[n - 1 - pos];
    if(c1)
        val1 += 10;
    if(c2)
        val2--;
    dp[pos][c1][c2] = 0;
    for(int v1 = (pos == 0); v1 < 10; v1++)
    {
        for(int v2 = 0; v2 < 10 ;v2++)
        {
            if(v1 + v2 == val1 && v1 + v2 == val2 && rec2(pos + 1, 0,0))
            {
                ans2[pos] = '0' + v1;
                ans2[n - 2 - pos] = '0' + v2;
                return dp[pos][c1][c2] = 1;
            }
            if(v1 + v2 + 1 == val1 && v1 + v2 == val2 && rec2(pos + 1, 1, 0))
            {
                ans2[pos] = '0' + v1;
                ans2[n - 2 - pos] = '0' + v2;
                return dp[pos][c1][c2] = 1;
            }
            if(v1 + v2 + 1 == val1 && v1 + v2 - 10 == val2 && rec2(pos + 1, 1, 1))
            {
                ans2[pos] = '0' + v1;
                ans2[n - 2 - pos] = '0' + v2;
                return dp[pos][c1][c2] = 1;
            }
            if(v1 + v2  == val1 && v1 + v2 - 10 == val2 && rec2(pos + 1, 0, 1))
            {
                ans2[pos] = '0' + v1;
                ans2[n - 2 - pos] = '0' + v2;
                return dp[pos][c1][c2] = 1;
            }
        }
    }
    return dp[pos][c1][c2];
}
int check1()
{
    NEG(dp);
    int res = rec(0,0,0);
    return res;
}
int check2()
{
    if(arr[0] != 1)
        return 0;
    NEG(dp);
    int res = rec2(0,1,0);
    return res;
}
string solve()
{
    ans1 = string(n, ' ');
    ans2 = string(n - 1, ' ');
    int res1 = check1();
    if(res1)
        return ans1;
    int res2 = check2();
    if(res2)
        return ans2;
    return "0";
}
//941 149 -> 1090
int  main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    cin >> s;
    n = s.size();
    FOR(i,0,n)
    arr[i] = s[i] - '0';
    string res = solve();
    if(res[0] == '0')
    {
        for(int i = 0; i < res.size()  - 1- i; i++)
            swap(res[i],res[res.size() - 1 - i]);
    }
    cout << res << endl;
    
    return 0;
    
}