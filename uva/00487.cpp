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
    {0, 1},
    {-1,-1},
    {-1,1},
    {1,-1},
    {1,1}};

const double epsilon = 1e-9;

void dfs(vs& cm, int i, int j, string& cs, set<string>& ret){

    if(sz(cs)>=3){
        // cout<<cs<<endl;
        string t = cs;
        ret.ins(t);
    }

    for(auto k : ds){
        int nx = i + k[0];
        int ny = j + k[1];
        if(nx>=0&&ny>=0&&nx<sz(cm)&&ny<sz(cm)&&cm[nx][ny]>cm[i][j]){
            cs.pb(cm[nx][ny]);
            dfs(cm,nx,ny,cs,ret);
            cs.pob();
        }
    }
    
}

struct comp{
    bool operator()(string& s1, string& s2) const {
        if(sz(s1)!=sz(s2)){
            return sz(s1) < sz(s2);
        }
        return s1 < s2;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    FOR(j,0,t){
        int l;
        cin >> l;
        vs cm;
        FOR(i,0,l){
            string s1;
            cin >> s1;
            cm.pb(s1);
        }

        set<string> cs;
        FOR(i,0,l){
            FOR(k,0,l){
                string es = "";
                es.pb(cm[i][k]);
                dfs(cm,i,k,es,cs);
            }
        }

        vs ret;
        for(auto i : cs){
            ret.pb(i);
        }

        sort(all(ret),comp());
        for(auto i : ret){
            printf("%s\n",i.c_str());
        }
        if(j!=t-1) printf("\n");
    }

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343