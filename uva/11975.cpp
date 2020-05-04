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
 
 // not solve
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int t = 0;
    cin >> t;
    FOR(i,0,t){
        printf("Case %d:\n",i+1);
        int bs = 0, ts = 0;
        cin >> bs >> ts;
        vi vb;
        FOR(j,0,bs){
            int k;
            cin >> k;
            vb.pb(k);
        }
        int ss[4];
        FOR(j,0,4){
            int k;
            cin >> k;
            ss[j] = k;
        }

        FOR(o,0,ts){
            vvi vs;
            vi tic(100,0);
            FOR(j,0,5){
                vi v;
                FOR(e,0,5){
                    int k = 0;
                    cin >> k;
                    v.pb(k);
                    tic[k] = 1;
                }
                vs.pb(v);
            }

            int c = 0;
            vi l(5,0);
            int d = 0;
            int t = 0;

            FOR(j,0,sz(vb)){
                if(j < 35 && (vb[j]==vs[0][4] || vb[j]==vs[0][0] || vb[j]==vs[4][4] || vb[j]==vs[4][0])) c++;
                FOR(e,0,5){
                    if(j < 40 && (vb[j]==vs[e][0] || vb[j]==vs[e][1] || vb[j]==vs[e][2] || vb[j]==vs[e][3] || vb[j]==vs[e][4])) l[e]++;
                }
                if(j < 45 && (vb[j]==vs[0][0] || vb[j]==vs[1][1] || vb[j]==vs[2][2] || vb[j]==vs[3][3] || vb[j]==vs[4][4]
                    || vb[j]==vs[0][4] || vb[j]==vs[1][3] || vb[j]==vs[2][2] || vb[j]==vs[3][1] || vb[j]==vs[4][0]))
                    d++;
                tic[vb[j]] = 2;
            }

            for(auto e : tic){
                if(e==2) t++;
            }

            int ret = 0;
            if(c == 4) ret += ss[0];
            bool flg = false;
            for(auto e : l){
                if(e==5) {
                    flg = true;
                    break;
                }
            }
            if(flg) ret+= ss[1];
            if(d==9) ret += ss[2];
            if(t>=25) ret += ss[3];
            printf("%d\n",ret);
        }
        
        printf("\n");
    }
    
    return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343