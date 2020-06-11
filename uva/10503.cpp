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

bool dfs(int s, int& st1, int& st2, int rm, vvi& v){

    if(rm == 0) return s == st1 || s == st2;

    bool ret = false;
    FOR(j,0,7){
        if(v[s][j]){
            v[s][j]=0;
            v[j][s]=0;
            ret = ret || dfs(j,st1,st2,rm-1,v);
            v[j][s]=1;
            v[s][j]=1;
        }
    }
    return ret;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    while(cin >> n && n != 0){
        cin >> m;

        pa<int,int> l;
        pa<int,int> r;

        int l1, l2;
        int r1, r2;
        cin >> l1 >> l2 >> r1 >> r2;

        vvi v(7,vi(7,0));
        FOR(i,0,m){
            int t1,t2;
            cin >> t1 >> t2;
            v[t1][t2] = 1;
            v[t2][t1] = 1;
        }

        bool ret = false;
        ret = ret || dfs(l2,r1,r1,n,v);
        // ret = ret || dfs(l2,r1,r2,n,v);

        if(ret) printf("YES\n");
        else printf("NO\n");

    }

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343