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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<pa<int,vi>> cm(6);
    cm[0] = mp(5,vi({1,2,4,3}));
    cm[5] = mp(0,vi({1,3,4,2}));
    cm[1] = mp(4,vi({5,2,0,3}));
    cm[4] = mp(1,vi({5,3,0,2}));
    cm[2] = mp(3,vi({1,5,4,0}));
    cm[3] = mp(2,vi({1,0,4,5}));

    string s = "";
    while(getline(cin,s)){
        
        bool flg = false;
        FOR(i,0,6){
            flg = false;
            FOR(j,0,6){
                flg = false;
                if(s[i]==s[j+6]&&s[cm[i].f]==s[cm[j].f+6]){
                    FOR(r,0,4){
                        flg = true;
                        FOR(b,0,4){
                            if(s[cm[i].s[b]]!=s[cm[j].s[(b+r)%4]+6]){
                                flg = false;
                                break;
                            }
                        }
                        if(flg)  break;
                    }
                }
                if(flg)  break;
            }
            if(flg)  break;
        }

        if(flg) printf("TRUE\n");
        else printf("FALSE\n");

    }

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343