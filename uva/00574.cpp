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

void dfs(vi& v, int ci, int sum, int key, int& tar, vi& cv, vvi& ret, set<int>& cache){

    key = key % MOD;
    if(sum==tar&&nex(cache,key)){
        cache.ins(key);
        vi ts = cv;
        ret.pb(ts);
        return;
    }
    if(sum>tar) return;
    if(ci==sz(v)) return;
    

    cv.pb(v[ci]);
    dfs(v,ci+1,sum + v[ci],1000*key+v[ci],tar,cv,ret,cache);
    cv.pob();

    dfs(v,ci+1,sum,key,tar,cv,ret,cache);


}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t,n;
    while(cin >> t && cin >> n && (t!=0||n!=0)){

        vi v;
        FOR(i,0,n){
            int k;
            cin >> k;
            v.pb(k);
        }

        sort(all(v),greater<int>());
        vi cv;
        vvi ret;
        set<int> cache;
        dfs(v,0,0,0,t,cv,ret,cache);

        printf("Sums of %d:\n",t);
        if(sz(ret)==0) printf("NONE\n");
        for(auto i : ret){
            FOR(j,0,sz(i)){
                if(j==0) printf("%d",i[j]);
                else printf("+%d",i[j]);
            }
            printf("\n");
        }

    }

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343