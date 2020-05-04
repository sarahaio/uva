#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
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
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
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


#define FOR(i,a,b) for (int i=a; i<b; i++)
#define F0R(i,a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = b; i > a; i--)
#define F0Rd(i,a) for (int i = a; i > -1; i--)
 
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
#define ex(m,i) m.find(i)!=m.end()
#define nex(m,i) m.find(i)==m.end()


#define uniq(x) x.resize(unique(all(x))-x.begin())
 
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy
const vvi ds = {
    {-1,0},
    {1,0},
    {0,-1},
    {0,1}
};
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    for(ll i1 = 1; i1 < 2001; i1++){
        for(ll i2 = i1; i2 < 2001 && i1 + i2 < 2001; i2++){
            for(ll i3 = i2; i3 < 2001 && i1 + i2 + i3 < 2001; i3++){
                ll t = 1000000 * i1 + 1000000 * i2 + 1000000 * i3;
                ll d = i1 * i2 * i3 - 1000000;
                if(d>0  && t % d == 0){
                    ll fin = t / d;
                    if(fin >= i3 && fin < 2001 && i1 + i2 + i3 + fin < 2001){
                        printf("%.2lf %.2lf %.2lf %.2lf\n",i1/100.0,i2/100.0,i3/100.0,fin/100.0);
                    }
                }
            }
        }
    }
    
    return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343