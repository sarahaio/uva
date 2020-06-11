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

vs bs; vs ss;
vs ss1, ss2, ss3;

vs rotate(vs orig){
    vs rets;
    FOR(i,0,sz(orig)){
        string t = "";
        FORd(j,-1,sz(orig)-1){
            t.pb(orig[j][i]);
        }
        rets.pb(t);
    }
    return rets;
}

int count(vs& ss){
    int c = 0;
    FOR(i,0,sz(bs)-sz(ss)+1){
        FOR(j,0,sz(bs)-sz(ss)+1){
            bool flg = true;
            FOR(k,0,sz(ss)){
                FOR(l,0,sz(ss)){
                    if(bs[i+k][j+l]!=ss[k][l]){
                        flg = false;
                        break;
                    }
                }
                if(!flg) break;
            }
            if(flg) c++;
        }
    }
    return c;
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);
    

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    
    int t;
    cin >> t;
    FOR(o,0,t){
        vvi vc;
        FOR(i,1,6){
            vi v;
            FOR(j,0,i){
                int k; cin >> k;
                v.pb(k);
            }
            vc.pb(v);
        }

        vvi ret;
        FORd(i,0,sz(vc)-1){
            vi v1;
            v1.pb(vc[i][0]);
            FOR(j,0,sz(vc[i])-1){
                v1.pb((vc[i-1][j]-vc[i][j+1]-vc[i][j])/2);
                v1.pb(vc[i][j+1]);
            }
            ret.pb(v1);
            vi v2;
            FOR(j,0,sz(v1)-1){
                v2.pb(v1[j]+v1[j+1]);
            }
            ret.pb(v2);
        }
        ret.pb(vi({vc[0][0]}));

        reverse(all(ret));
        FOR(i,0,sz(ret)){
            FOR(j,0,sz(ret[i])){
                if(j!=sz(ret[i])-1) printf("%d ",ret[i][j]);
                else printf("%d",ret[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}



