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
const double epsilon = 1e-6;
 
struct comp{
    bool operator()(pa<int,pa<int,pa<int,int>>> p1, int t) const{
        return p1.f < t;
    }

    bool operator()(int t, pa<int,pa<int,pa<int,int>>> p1) const{
        return t < p1.f;
    }
};

bool equal(double a, double b){
    return abs(a-b) < epsilon;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    vector<pa<int,pa<int,pa<int,int>>>> v;
    for(int i = 1; i < 25600;i++){
        for(int j = i; j < 25600;j++){
            if(i * j - 10000 > 0 && (10000 * i + 10000 * j) % (i * j - 10000) == 0){
                int k = (10000 * i + 10000 * j) / (i * j - 10000);
                if(k < 25600 && k >= j)
                    v.pb(mp(i+j+k,mp(i,mp(j,k))));
            }
        }
    }

    sort(all(v));
    
    double a;
    double b;
    while(scanf("%lf %lf",&a,&b)!=EOF){

        int ia = 100 * a;
        int ib = 100 * b;
        auto ita = ub(all(v),ia,comp());
        auto itb = ub(all(v),ib,comp());

        
        for(int i = ita - v.begin() - 1; i < itb - v.begin(); i++){
            if(i < 0) continue;
            printf("%.2lf = %.2lf + %.2lf + %.2lf = %.2lf * %.2lf * %.2lf\n",v[i].f/100.0,v[i].s.f/100.0,v[i].s.s.f/100.0,v[i].s.s.s/100.0,v[i].s.f/100.0,v[i].s.s.f/100.0,v[i].s.s.s/100.0);
        }

    }

    return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343