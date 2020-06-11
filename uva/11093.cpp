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
#include <cstring>

 
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
const double epsilon = 1e-12;
const vvi ds = {
    {-1,0},
    {1,0},
    {0,-1},
    {0,1}
};

// 1
// 3 1 2
// 32.0 54.7 -2

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);
    

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    
    int t;
    cin >> t;
    FOR(o,0,t){
        int n; cin >> n;
        vl ps; vl cs;
        ll petrol = 0;
        ll cost = 0;
        FOR(j,0,n){
            ll k; cin >> k;
            ps.pb(k);
            petrol += k;
        }
        FOR(j,0,n){
            ll k; cin >> k;
            // cs.pb(k);
            ps[j]-=k;
            cost += k;
        }

        if(petrol < cost) printf("Case %d: Not possible\n",o+1);
        else{

            ll cp = 0;
            int li = 0;
            FOR(i,0,n){
                cp += ps[i];
                if(cp < 0){
                    // reset
                    cp = 0;
                    ps.pb(ps[i]);
                    li = i + 1;
                }
            }
            printf("Case %d: Possible from station %d\n",o+1,li+1);
        }
    }

    return 0;
}



