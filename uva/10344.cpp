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

bool dfs(vi& v, int total, int ci){

    if(ci == 5){
        return total == 23;
    }

    bool ret = false;

    ret = ret || dfs(v,total + v[ci],ci+1);

    ret = ret || dfs(v,total - v[ci],ci+1);

    ret = ret || dfs(v,total * v[ci],ci+1);

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int i1, i2, i3, i4, i5;
    while(cin >> i1 >> i2 >> i3 >> i4 >> i5 && (i1||i2||i3||i4||i5)){
        vi v;
        v.pb(i1); v.pb(i2); v.pb(i3); v.pb(i4); v.pb(i5);

        sort(all(v));

        bool ret = false;
        do{
            int total = v[0];
            ret = ret || dfs(v,total,1);
        }
        while(next_permutation(all(v)));

        if(ret) {
            printf("Possible\n");
        }
        else printf("Impossible\n");
    }

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343