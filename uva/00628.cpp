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

void dfs(string& pat, string& word, string& ssf, int i){
    if(i==sz(pat)) {
        printf("%s\n",ssf.c_str());
        return;
    }
    if(pat[i]=='0'){
        FOR(j,0,10){
            ssf.pb(j+'0');
            dfs(pat,word,ssf,i+1);
            ssf.pob();
        }
        return;
    }
    if(pat[i]=='#'){
        string ssf1 = ssf + word;
        dfs(pat,word,ssf1,i+1);
        return;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int nost;
    while(cin >> nost){
        printf("--\n");
        vs cs;
        FOR(i,0,nost){
            string t;
            cin >> t;
            cs.pb(t);
        }
        int pat;
        cin >> pat;
        FOR(i,0,pat){
            string past;
            cin >> past;
            for(auto st : cs){
                string init = "";
                dfs(past,st,init,0);
            }
        }
    }

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343