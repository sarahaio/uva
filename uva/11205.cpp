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

bool check(vi& ori){
    FOR(i,0,sz(ori)){
        FOR(j,0,sz(ori)){
            if(i!=j&&ori[i]==ori[j]) return false;
        }
    }
    return true;
}
 
void dfs(vi& ori, int i, int cmax, int &gmax, int& p){


    // for(auto i : ori){
    //     cout<<i<<endl;
    // }
    // cout<<"cmax "<<cmax<<endl;

    if(i==p){
        if(check(ori)){
            gmax = max(gmax,cmax);
        }

        return;
    }

    dfs(ori,i+1,cmax,gmax,p);

    int te = 0;
    FOR(j,0,sz(ori)){
        if(ori[j] & 1 << p - i - 1) {
            te = te | 1;
        }
        ori[j] = ori[j] & ~(1 << p - i - 1);
        te <<= 1;
    }
    dfs(ori,i+1,cmax+1,gmax,p);
    // cout<<"te "<<te<<endl;
    FOR(j,0,sz(ori)){
        te >>= 1;
        ori[j] = ori[j] | (te & 1) << p - i - 1;
    }
    // for(auto i : ori){
    //     cout<<i<<endl;
    // }
}


// not solved yet
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int t;
    cin >> t;
    FOR(u,0,t){
        int p, n;
        cin >> p >> n;
        vi ori;
        FOR(i,0,n){
            int re = 0;
            FORd(j,-1,p-1){
                int te;
                cin >> te;
                re = re | te << j;
            }
            ori.pb(re);
        }

        int gmax = 0;
        dfs(ori,0,0,gmax,p);

        printf("%d\n",p-gmax);
    }
    
    return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343