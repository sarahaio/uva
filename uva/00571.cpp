#pragma GCC optimize("O3")
#pragma GCC target("sse4")

// #include <bits/stdc++.h>
#include <vector>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <random>
#include <queue>
#include <algorithm>
#include <climits>
#include <map>
#include <set>
#include <stack>
#include <sstream>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<pd> vpd;
typedef vector<cd> vcd;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = b; i > a; i--)
#define F0Rd(i, a) for (int i = a; i > -1; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define pob pop_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
#define que queue
#define pa pair
#define ex(m, i) m.find(i) != m.end()
#define nex(m, i) m.find(i) == m.end()

#define uniq(x) x.resize(unique(all(x)) - x.begin())

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy
const vvi ds = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}};

// p1 1 fill 2 pour 3 empty
// p2 1 a 2 b
bool dfs(int ca, int cb, int& a, int& b, int& target, vector<pa<int,int>>& actions, set<int>& cache){

    if(ca==target || cb == target) {
        return true;
    }
    if(ex(cache,ca*1001+cb)) return false;
    // cout<<ca<<" "<<cb<<endl;
    cache.ins(ca*1001+cb);

    bool ret = false;
    // fill a
    if(ca!=a&&cb!=b){
        actions.pb(mp(1,1));
        ret = ret || dfs(a,cb,a,b,target,actions,cache);
        if(ret) return ret;
        actions.pob();
    }
    

    // fill b
    if(cb!=b&&ca!=a){
        actions.pb(mp(1,2));
        ret = ret || dfs(ca,b,a,b,target,actions,cache);
        if(ret) return ret;
        actions.pob();
    }

    // empty a
    if(ca!=0){
        actions.pb(mp(3,1));
        ret = ret || dfs(0,cb,a,b,target,actions,cache);
        if(ret) return ret;
        actions.pob();
    }

    // empty b
    if(cb!=0){
        actions.pb(mp(3,2));
        ret = ret || dfs(ca,0,a,b,target,actions,cache);
        if(ret) return ret;
        actions.pob();
    }
    
    // pour a
    if(ca!=0){
        actions.pb(mp(2,1));
        int tb = min(cb+ca,b);
        int ta = ca - tb + cb;
        ret = ret || dfs(ta,tb,a,b,target,actions,cache);
        if(ret) return ret;
        actions.pob();
    }

    // pour b
    if(cb!=0){
        actions.pb(mp(2,2));
        int ta = min(ca+cb,a);
        int tb = cb - ta + ca;
        ret = ret || dfs(ta,tb,a,b,target,actions,cache);
        if(ret) return ret;
        actions.pob(); 
    }

    return ret;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int a, b, n;
    while(cin >> a >> b >> n){

        vector<pa<int,int>> actions;
        set<int> cache;

        int ret = dfs(0,0,a,b,n,actions,cache);

        for(auto i : actions){
            switch(i.f){
                case 1:{
                    printf("fill ");
                    if(i.s==1) printf("A\n");
                    else printf("B\n");
                    break;
                }
                case 2:{
                    printf("pour ");
                    if(i.s==1) printf("A B\n");
                    else printf("B A\n");
                    break;
                }
                case 3:{
                    printf("empty ");
                    if(i.s==1) printf("A\n");
                    else printf("B\n");
                    break;
                }
            }
        }
        printf("success\n");

    }

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343