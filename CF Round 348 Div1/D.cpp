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
struct TreapNode
{
    TreapNode* left;
    TreapNode* right;
    int cnt;
    int c;
    int val;
    int fixed;
};
class Treap
{
public:
    TreapNode* root;
    Treap()
    {
        root = NULL;
    }
    int count(TreapNode* curr)
    {
        if(!curr)
            return 0;
        else
            return curr->cnt;
    }
    void rotateLeft(TreapNode*& curr)
    {
        TreapNode* r = curr->right;
        curr->cnt -= count(r);
        r->cnt -= count(r->left);
        curr->right = r->left;
        curr->cnt += count(r->left);
        r->left = curr;
        r->cnt += count(curr);
        curr = r;
    }
    void rotateRight(TreapNode*& curr)
    {
        TreapNode* l = curr->left;
        curr->cnt -= count(l);
        l->cnt -= count(l->right);
        curr->left = l->right;
        curr->cnt += count(l->right);
        l->right = curr;
        l->cnt += count(curr);
        curr = l;
    }
    void insert(TreapNode*&curr, int val)
    {
        if(!curr)
        {
            curr = new TreapNode;
            curr->val = val;
            curr->fixed = rand();
            curr->cnt = 1;
            curr->c = 1;
            curr->left = curr->right = NULL;
        }
        else if(val < curr->val)
        {
            insert(curr->left, val);
            curr->cnt++;
            if(curr->left->fixed < curr->fixed)
                rotateRight(curr);
        }
        else if(val > curr->val)
        {
            insert(curr->right, val);
            curr->cnt++;
            if(curr->right->fixed < curr->fixed)
                rotateLeft(curr);
        }
        else
        {
            curr->c++;
            curr->cnt++;
        }
    }
    int find(TreapNode*& curr, int k)
    {
        if(curr == NULL)
            return 0;
        if(curr->val == k)
            return count(curr->left) + curr->c;
        else if(curr->val > k)
            return find(curr->left, k);
        else
            return count(curr->left) + curr->c + find(curr->right, k);
    }
    void insert(int val)
    {
        insert(root, val);
    }
    int find(int k)
    {
        return find(root,k);
    }
    
} treap[100100][2];
int n;
int a,x,t;
map<int,int> umap;
int cnt;
int check(int val)
{
    if(umap.count(val) == 0)
        umap[val] = cnt++;
    return umap[val];
        
}
int main() {

    scanf("%d", &n);
    cnt = 0;
    FOR(i,0,n)
    {
        scanf("%d %d %d", &a, &t, &x);
        int index = check(x);
        if(a == 1)
            treap[index][0].insert(t);
        else if(a == 2)
            treap[index][1].insert(t);
        else
        {
            int val1 = treap[index][0].find(t);
            int val2 = treap[index][1].find(t);
            cout << val1 - val2 << endl;
        }
    }
    return 0;
}