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

int distance(int x1, int y1, int x2, int y2){
    return abs(x1-x2) + abs(y1-y2);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int t;
    cin >> t;
    FOR(i,0,t){

        int c;
        cin >> c;
        vector<pa<pa<int,int>,int>> vs;
        FOR(j,0,c){
            int x, y, v;
            cin >> x >> y >> v;
            vs.pb(mp(mp(x,y),v));
        }

        int cmin = INT_MAX;
        int ret1,ret2,ret3,ret4,ret5;
        FOR(c1,0,25){
            FOR(c2,c1+1,25){
                // if(c2==c1) continue;
                FOR(c3,c2+1,25){
                    // if(c3==c1||c3==c2) continue;
                    FOR(c4,c3+1,25){
                        // if(c4==c1||c4==c2||c4==c3) continue;
                        FOR(c5,c4+1,25){
                            // if(c5==c1||c5==c2||c5==c3||c5==c4) continue;
                            int lmin = 0;
                            for(auto j : vs){
                                lmin += j.s * min(distance(c1/5,c1%5,j.f.f,j.f.s),min(distance(c2/5,c2%5,j.f.f,j.f.s),min(distance(c3/5,c3%5,j.f.f,j.f.s),min(distance(c4/5,c4%5,j.f.f,j.f.s),distance(c5/5,c5%5,j.f.f,j.f.s)))));
                            }
                            if(lmin < cmin){
                                cmin = lmin;
                                ret1 = c1;
                                ret2=c2;
                                ret3=c3;
                                ret4=c4;
                                ret5=c5;
                            }
                        }
                    }
                }
            }
        }

        printf("%d %d %d %d %d\n",ret1,ret2,ret3,ret4,ret5);

    }
    
    return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343