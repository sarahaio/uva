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

void dfs(int ci, int k, string& cs, set<string>& cache, int& n, string& s){
    if(ci==n){
        string t = cs;
        cache.ins(t);
        return;
    }

    if(k>0){
        cs.pb('A');
        dfs(ci+1,k-1,cs,cache,n,s);
        cs.pob();

        cs.pb('G');
        dfs(ci+1,k-1,cs,cache,n,s);
        cs.pob();

        cs.pb('C');
        dfs(ci+1,k-1,cs,cache,n,s);
        cs.pob();

        cs.pb('T');
        dfs(ci+1,k-1,cs,cache,n,s);
        cs.pob();
    }

    cs.pb(s[ci]);
    dfs(ci+1,k,cs,cache,n,s);
    cs.pob();

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    FOR(o,0,t){
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;

        string cs = "";
        set<string> cache;
        dfs(0,k,cs,cache,n,s);

        vs ret1;
        for(auto i : cache){
            ret1.pb(i);
        }

        sort(all(ret1));

        printf("%d\n",sz(ret1));
        for(auto i : ret1){
            printf("%s\n",i.c_str());
        }

    }

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343