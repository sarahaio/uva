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
    
    int t; cin >> t;
    FOR(o,0,t){
        int t1; cin >> t1;
        set<int> v1; set<int> s12;
        set<int> v2; set<int> s23;
        set<int> v3; set<int> s13;
        FOR(i,0,t1){
            int k; cin >> k;
            v1.ins(k); s12.ins(k); s13.ins(k);
        }
        int t2; cin >> t2;
        FOR(i,0,t2){
            int k; cin >> k;
            v2.ins(k); s12.ins(k); s23.ins(k);
        }
        int t3; cin >> t3;
        FOR(i,0,t3){
            int k; cin >> k;
            v3.ins(k); s23.ins(k); s13.ins(k);
        }

        for(auto it = v1.begin(); it != v1.end();){
            if(ex(s23,*it)){
                it = v1.erase(it);
            }
            else{
                ++it;
            }
        }
        for(auto it = v2.begin(); it != v2.end();){
            if(ex(s13,*it)){
                it = v2.erase(it);
            }
            else{
                ++it;
            }
        }
        for(auto it = v3.begin(); it != v3.end();){
            if(ex(s12,*it)){
                it = v3.erase(it);
            }
            else{
                ++it;
            }
        }

        printf("Case #%d:\n",o+1);
        int cmax = max(sz(v1),max(sz(v2),sz(v3)));
        if(sz(v1)==cmax){
            printf("1 %d",sz(v1));
            for(auto i : v1){
                printf(" %d",i);
            }
            printf("\n");
        }
        if(sz(v2)==cmax){
            printf("2 %d",sz(v2));
            for(auto i : v2){
                printf(" %d",i);
            }
            printf("\n");
        }
        if(sz(v3)==cmax){
            printf("3 %d",sz(v3));
            for(auto i : v3){
                printf(" %d",i);
            }
            printf("\n");
        }

    }

    return 0;
}



