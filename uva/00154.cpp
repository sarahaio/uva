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

    string s;
    vvi vs;
    map<char,int> mm = {{'P',0},{'G',1},{'S',2},{'A',3},{'N',4}};
    map<char,int> cm = {{'r',0},{'o',1},{'y',2},{'g',3},{'b',4}};
    while(getline(cin,s)){
        if(s=="#") break;

        if(s[0]=='e'){

            int ret = INT_MAX;
            int ind = 0;
            FOR(i,0,sz(vs)){
                int c = 0;
                FOR(j,0,sz(vs)){
                    if(j==i) continue;
                    FOR(k,0,sz(vs[i])){
                        if(vs[i][k]!=vs[j][k]) c++;
                    }
                }
                if(ret > c) {
                    ret = c;
                    ind = i + 1;
                }
            }
            printf("%d\n",ind);

            vs = vvi();
        }
        else{
            vi v(5,0);
            v[cm[s[0]]] = mm[s[2]];
            v[cm[s[4]]] = mm[s[6]];
            v[cm[s[8]]] = mm[s[10]];
            v[cm[s[12]]] = mm[s[14]];
            v[cm[s[16]]] = mm[s[18]];
            vs.pb(v);
        }

    }

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343