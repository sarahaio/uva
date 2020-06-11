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
    
void dfs(vi& ts, vi& cr, int ci, int t, int& l, int& csize, int& cmax, vi& ret){
    if(t > l) return;
    if(ci==sz(ts)){
        if(t > cmax || t == cmax && sz(cr) > csize){
            if(sz(cr)==0) cout<<sz(cr)<<endl;
            cmax = t;
            ret = cr;
            csize = sz(cr);
        }
        return;
    }
    dfs(ts,cr,ci+1,t,l,csize,cmax,ret);
    cr.pb(ts[ci]);
    dfs(ts,cr,ci+1,t+ts[ci],l,csize,cmax,ret);
    cr.pob();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int l;
    while(cin >> l){
        int t;
        cin >> t;
        vi ts;
        FOR(i,0,t){
            int u;
            cin >> u;
            ts.pb(u);
        }

        vi cr;
        vi ret;
        int cmax = 0;
        int csize = 0;
        dfs(ts,cr,0,0,l,csize,cmax,ret);
        for(auto i : ret){
            printf("%d ",i);
        }
        printf("sum:%d\n",cmax);
    }

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343