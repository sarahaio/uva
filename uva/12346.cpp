#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
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
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
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


#define FOR(i,a,b) for (int i=a; i<b; i++)
#define F0R(i,a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = b; i > a; i--)
#define F0Rd(i,a) for (int i = a; i > -1; i--)
 
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
#define ex(m,i) m.find(i)!=m.end()
#define nex(m,i) m.find(i)==m.end()


#define uniq(x) x.resize(unique(all(x))-x.begin())
 
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy
const vvi ds = {
    {-1,0},
    {1,0},
    {0,-1},
    {0,1}
};
 
struct comp{
    bool operator()(pa<int,int> p1, pa<int,int> p2) const{
        if(p1.f!=p2.f){
            return p1.f < p2.f;
        }
        return p1.s > p2.s;
    }
};


void dfs(vector<pa<ll,ll>>& gates, int i, int choices, vector<pa<ll,ll>>& require,vector<ll>& res){
    if(i==sz(gates)){
        FOR(j,0,sz(require)){
            ll cost = 0;
            ll flow = 0;
            int k = choices;
            int m = 0;
            while(k>0){
                cost += gates[m].f * (k&1);
                flow += gates[m].s * (k&1) * require[j].s;
                if(flow > require[j].f) break;
                k >>= 1;
                m++;
            }
            if(flow >= require[j].f){
                res[j] = min(res[j],cost);
            }
        }
        return;
    }

    dfs(gates,i+1,choices,require,res);

    int rchoice = choices;
    rchoice = 1 << i | choices;
    dfs(gates,i+1,rchoice,require,res);
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int pre, que;
    cin >> pre;
    vector<pa<ll,ll>> vs;
    FOR(i,0,pre){
        ll flow, cost;
        cin >> flow >> cost;
        vs.pb(mp(cost,flow)); 
    }

    cin >> que;
    vector<pa<ll,ll>> require;
    FOR(i,0,que){
        ll flow, hour;
        cin >> flow >> hour;

        require.pb(mp(flow,hour));
    }

    vl ret(que,LLONG_MAX);
    dfs(vs,0,0,require,ret);


    FOR(j,0,que){
        if(ret[j]==LLONG_MAX){
            printf("Case %d: IMPOSSIBLE\n",j+1);
        }
        else{
            printf("Case %d: %lld\n",j+1,ret[j]);
        }
    }
    
    return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343