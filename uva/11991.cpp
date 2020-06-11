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
#include <bitset>
#include <deque>

 
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

struct comp{
    bool operator()(pa<int,int> p1, pa<int,int> p2){
        if(p1.first != p2.first) return p1.first < p2.first;
        return p1.second < p2.second;
    }
};

struct comp2{
    bool operator()(pa<int,int> p1, int ci){
        return p1.first < ci;
    }
};

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    
    while(true){
        int m, n; cin >> m >> n;
        if(cin.eof()) break;
        vector<pa<int,int>> v;
        FOR(i,0,m){
            int k; cin >> k;
            v.pb(mp(k,i));
        }
        sort(all(v),comp());

        FOR(i,0,n){
            int k, o; cin >> k >> o;
            auto it = lb(all(v),o,comp2());
            if(v.end() - it < k - 1){
                printf("0\n");
                continue;
            }
            auto it2 = it + (k - 1);
            if((*it2).first!=o){
                printf("0\n");
            }
            else {
                printf("%d\n",(*it2).second + 1);
            }
        }

        if(cin.eof()) break;
    }

    return 0;
}



