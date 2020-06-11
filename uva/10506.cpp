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

bool dfs(int ci, int& total, int& m, int& n, string& cs, set<string>& cache){
    // if(ci == total - m){
    //     cs += cs.substr(0,m);
    // }
    if(ci==total){
        return true;
    }
    string te = cs.substr(ci,m);
    bool ret = false;
    if(nex(cache,te)){
        cache.ins(te);
        FOR(i,0,n){
            cs.ins(cs.begin()+ci+m,'0'+i);
            ret = ret || dfs(ci+1,total,m,n,cs,cache);
            if(ret) return ret;
            cs.erase(cs.begin()+ci+m);
        }
        cache.erase(te);
        ret = ret || dfs(ci+1,total,m,n,cs,cache);
        if(ret) return ret;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int m, n;
    while(cin >> m >> n){
        int total = pow(n,m);
        string cs = "";
        FOR(i,0,m){
            cs.pb('0');
            cs.pb('0');
        }
        set<string> cache;
        bool ret = dfs(0,total,m,n,cs,cache);
        cs = cs.substr(0,total);
        printf("%s\n",cs.c_str());
    }

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343