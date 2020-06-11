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

void dfs(vi& s, int i, int r, int& c, vector<pa<vi,int>>& ca, vector<pa<int,int>>& sc){
    if(r==0){
        int score = 0;
        int t = c;
        int j = 0;
        while(t > 0){
            if(t&1) score += s[j];
            j++;
            t = t >> 1;
            
        }
        for(auto i : ca){
            for(auto k : i.f){
                if(1<<k & c){
                    score += i.s;
                    break;
                }
            }
        }
        // cout<<c<<endl;
        // cout<<score<<endl;
        if(sz(sc)==0||score>sc[0].f){
            sc.clear();
            sc.pb(mp(score,c));
        }
        else if(score==sc[0].f){
            sc.pb(mp(score,c));
        }
        return;
    }
    if(i==sz(s)) return;

    dfs(s,i+1,r,c,ca,sc);

    c = 1 << i | c;
    // cout<<c<<endl;
    dfs(s,i+1,r-1,c,ca,sc);
    c = 1 << i ^ c;

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int t, b;
    int casen = 1;
    while(cin>>t&&cin>>b&&(t!=0||b!=0)){

        vi ts;
        FOR(i,0,t){
            int te;
            cin >> te;
            ts.pb(te);
        }

        int co;
        cin >> co;
        vector<pa<vi,int>> vs;
        FOR(i,0,co){
            int te;
            cin >> te;
            vi tss;
            FOR(j,0,te){
                int k;
                cin >> k;
                tss.pb(k-1);
            }
            int ks;
            cin >> ks;
            for(auto j : tss){
                ts[j] -= ks;
            }
            // cout<<endl;
            vs.pb(mp(tss,ks));
        }

        vector<pa<int,int>> ret;
        int choice = 0;
        dfs(ts,0,b,choice,vs,ret);

        int cmin = INT_MAX;
        int ncus;
        for(auto r : ret){
            cmin = min(cmin,r.s);
            ncus = r.f;
        }

        printf("Case Number  %d\n",casen);
        printf("Number of Customers: %d\n",ncus);
        printf("Locations recommended:");
        int count = 1;
        while(cmin>0){
            if(cmin&1){
                printf(" %d",count);
            }
            count++;
            cmin >>= 1;
        }
        printf("\n\n");

        casen++;
    }
    
    return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343