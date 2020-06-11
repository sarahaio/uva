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

vi visited;
vi lvisited;
int target;
vvi cm;

bool reachable(int ci){
    if(ci==target) return true;
    if(visited[ci]||lvisited[ci]) return false;
    
    lvisited[ci] = 1;
    bool ret = false;
    for(auto i : cm[ci]){
        ret = ret || reachable(i);
    }
    return ret;
}

void dfs(int ci, vi &cs, vvi &ret)
{
    if (ci == target)
    {
        cs.pb(ci);
        vi tv = cs;
        ret.pb(tv);
        cs.pob();
        return;
    }
    if (visited[ci])
        return;
    if(!reachable(ci)) return;

    cs.pb(ci);
    visited[ci] = 1;

    int intret = 0;
    for (auto i : cm[ci])
    {
        lvisited = vi(21,0);
        dfs(i, cs, ret);
    }

    visited[ci] = 0;
    cs.pob();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int o = 1;
    while (cin >> target)
    {
        int m1, m2;
        cm = vvi(21,vi(21,0));
        visited = vi(21,0);
        lvisited = vi(21,0);
        
        while (cin >> m1 >> m2 && (m1 != 0 || m2 != 0))
        {
            cm[m1].pb(m2);
            cm[m2].pb(m1);
        }

        FOR(i, 0, sz(cm))
        {
            sort(all(cm[i]));
        }

        vi cs;
        vvi ret;

        dfs(1, cs, ret);

        printf("CASE %d:\n", o);
        for (auto i : ret)
        {
            FOR(j, 0, sz(i))
            {
                if (j != sz(i) - 1)
                {
                    printf("%d ", i[j]);
                }
                else
                {
                    printf("%d\n", i[j]);
                }
            }
        }
        printf("There are %d routes from the firestation to streetcorner %d.\n", sz(ret), target);
        o++;
    }

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343