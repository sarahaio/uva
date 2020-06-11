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
#include <cstring>

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

const double epsilon = 1e-9;

int m, n;
vvi v;
vi path;
vvi bt;

int goalx, goaly = INT_MAX;

bool dfs(int x, int y, int i){

    if(x == m){
        if(path[i]==1){
            goalx = x, goaly = min(goaly,y);
            return true;
        }
        else return false;
    }
    
    if(bt[x][y]){
        return false;
    }
    if(v[x][y]!=path[i]){
        return false;
    }

    bt[x][y] = 1;

    bool ret = false;
    for(auto d : ds){
        int x1 = x + d[0];
        int y1 = y + d[1];
        if(x1>=0&&x1<=m&&y1>=0&&y1<n){
            ret = dfs(x1,y1,i+1) || ret;
        }
    }

    bt[x][y] = 0;

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    FOR(o,0,t){
        
        int order;
        cin >> order;

        vs v1;
        vs v2;

        FOR(i,0,6){
            string k; cin >> k;
            v1.pb(k);
        }
        FOR(i,0,6){
            string k; cin >> k;
            v2.pb(k);
        }

        int v[5];
        int vc[5][26] = {};
        memset(v,0,sizeof(v));

        FOR(i,0,5){
            FOR(j,0,6){
                FOR(k,0,6){
                    if(v1[j][i]==v2[k][i]) {
                        vc[i][v1[j][i]-'A'] = 1;
                    }
                }
            }
        }

        vector<vector<char>> vcs = vector<vector<char>>(5,vector<char>());

        FOR(i,0,5){
            FOR(j,0,26){
                if(vc[i][j]) {
                    vcs[i].pb('A'+j);
                    v[i]++;
                }
            }
        }

        if(order>v[0]*v[1]*v[2]*v[3]*v[4]) printf("NO\n");
        else{
            order--;
            string ret = "";
            FORd(i,-1,4){
                ret.pb(vcs[i][order%v[i]]);
                order /= v[i];
            }

            reverse(all(ret));
            printf("%s\n",ret.c_str());
        }

    }

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343