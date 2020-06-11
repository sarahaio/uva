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

int cal(vvi& cm){
    int c = 0;

    FOR(i,0,sz(cm)){
        bool once = false;
        FOR(j,0,sz(cm)){
            if(cm[i][j]==-1){
                once = false;
                continue;
            }
            if(once&&cm[i][j]){
                return 0;
            }
            if(cm[i][j]) {
                once = true;
                c++;
            }
        }
    }

    FOR(j,0,sz(cm)){
        bool once = false;
        FOR(i,0,sz(cm)){
            if(cm[i][j]==-1){
                once = false;
                continue;
            }
            if(once&&cm[i][j]){
                return 0;
            }
            if(cm[i][j]) {
                once = true;
            }
        }
    }

    return c;
}

void dfs(vvi& cm, int x, int y, int& gmax){
    if(x==sz(cm)-1&&y==sz(cm)){
        gmax = max(gmax,cal(cm));
        return;
    }
    if(y==sz(cm)){
        dfs(cm,x+1,0,gmax);
        return;
    }
    if(cm[x][y]==-1){
        dfs(cm,x,y+1,gmax);
        return;
    }

    dfs(cm,x,y+1,gmax);

    cm[x][y] = 1;
    dfs(cm,x,y+1,gmax);
    cm[x][y] = 0;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    while(cin >> t && t != 0){
        vvi cm(t,vi(t,0));
        FOR(i,0,t){
            string s;
            cin >> s;
            FOR(j,0,t){
                if(s[j]=='X') cm[i][j] = -1;
            }
        }

        int cmax = 0;
        dfs(cm,0,0,cmax);
        printf("%d\n",cmax);
    }


    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343