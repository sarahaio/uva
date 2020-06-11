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
    
int dfs(map<int,vi>& cm, int anc, int ci, set<int>& bt){
    if(nex(cm,ci)) return 0;

    int cmax = 0;
    
    for(auto i : cm[ci]){
        if(ex(bt,ci*25+i)) continue;
        bt.ins(ci*25+i);
        bt.ins(ci+25*i);
        cmax = max(cmax,1 + dfs(cm,ci,i,bt));
        bt.erase(ci*25+i);
        bt.erase(ci+25*i);
    }
    return cmax;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    while(cin >> n >> m && (n!=0||m!=0)){

        map<int,vi> cm;
        FOR(i,0,m){
            int i1,i2;
            cin >> i1 >> i2;
            cm[i1].pb(i2);
            cm[i2].pb(i1);
        }

        int cmax = 0;
        for(auto i : cm){
            set<int> bt;
            cmax = max(cmax,dfs(cm,25,i.f,bt));
        }
        printf("%d\n",cmax);
    }

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343