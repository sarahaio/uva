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

const double epsilon = 1e-9;

vi cm = {
    0b1111011, //9
    0b1111111, //8
    0b1110000, //7 -> 1110000 ^ 0000000 -> 1110000 -> 0001111
    0b1011111, //6 -> 
    0b1011011, //5 -> 
    0b0110011, //4 -> 0110011 ^ 0000000 -> 0110011 -> 1001100
    0b1111001, //3 -> 1111001 ^ 1000000 -> 0111001 -> 1000110
    0b1101101, //2 -> 1101101 ^ 1000000 -> 0101101 -> 1010010
    0b0110000, //1 -> 0110000 ^ 1000000 -> 1110000 -> 0001111
    0b1111110  //0 -> 1111110 ^ 0000100 -> 1111010 -> 0000101 
};
int n;
vi v;
vi checkcache;

bool dfs(int ci, int i){

    if(i==sz(v)){

        int bb = 0;
        FOR(i,0,sz(v)){

            int xo = cm[checkcache[i]] ^ v[i];
            if(xo & v[i] | bb & v[i]){
                return false;
            }
            bb = bb | (xo);
        }
        
        return true;
    }
    if(ci==sz(cm)) return false;

    bool ret = false;

    checkcache.pb(ci);
    ret = ret || dfs(ci + 1, i + 1);
    checkcache.pob();

    // ret = ret || dfs(ci + 1, i);

    

    return ret;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    while(cin>>n&&n!=0){

        v = vi();
        FOR(i,0,n){
            string k;
            cin >> k;
            int tk = 0b0;
            FOR(j,0,sz(k)){
                if(k[j]=='Y') tk = tk | 1;
                tk <<= 1;
            }
            tk >>= 1;
            v.pb(tk);
        }

        checkcache = vi();
        bool ret = false;
        FOR(i,0,10){
            ret = ret || dfs(i,0);
        }

        if(ret) printf("MATCH\n");
        else printf("MISMATCH\n");
    }


    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343