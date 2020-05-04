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
 
struct comp{
    bool operator()(pa<string,pa<int,int>>& p1, pa<string,pa<int,int>>& p2) const {
        if(p1.s.f != p2.s.f){
            return p1.s.f > p2.s.f;
        }

        if(p1.s.s != p2.s.s){
            return p1.s.s < p2.s.s;
        }
        
        return p1.f < p2.f;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int t;
    cin >> t;
    FOR(i,0,t){

        vector<pa<string,pa<int,int>>> vs;
        FOR(j,0,10){
            string s;
            int a, d;
            cin >> s >> a >> d;
            vs.pb(mp(s,mp(a,d)));
        }

        sort(all(vs),comp());

        vector<string> as;
        vector<string> ds;
        FOR(i,0,5){
            as.pb(vs[i].f);
        }
        FOR(i,5,10){
            ds.pb(vs[i].f);
        }

        sort(all(as));
        sort(all(ds));

        printf("Case %d:\n",i+1);
        printf("(");
        FOR(i,0,5){
            if(i==4) printf("%s",as[i].c_str());
            else printf("%s, ",as[i].c_str());
        }
        printf(")\n");
        printf("(");
        FOR(i,0,5){
            if(i==4) printf("%s",ds[i].c_str());
            else printf("%s, ",ds[i].c_str());
        }
        printf(")\n");
    }
    
    return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343