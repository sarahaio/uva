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

struct comp{
    bool operator()(pa<int,int> p1, int p2){
        return p1.f < p2;
    }

    bool operator()(int p1, pa<int,int> p2){
        return p1 < p2.f;
    }
};

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);
    

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    
    int s, b;
    while(cin >> s >> b && (s!=0 || b != 0)){

        vector<pa<int,int>> vp;
        vp.pb(mp(0,0));
        vp.pb(mp(s+1,s+1));

        FOR(i,0,b){
            int l, r;
            cin >> l >> r;

            int retl = -1, retr = -1;
            auto itl = lb(all(vp),l,comp());
            auto itr = lb(all(vp),r,comp());

            --itl;
            if((*itl).s==l-1){
                retl = (*itl).f - 1;
            }
            else{
                retl = l - 1;
            }
            
            if((*itr).f==r+1){
                retr = (*itr).s + 1;
            }
            else{
                retr = r + 1;
            }

            if((*itl).s==l-1 && (*itr).f==r+1){
                (*itl).s = (*itr).s;
                vp.erase(itr);
            }
            else if((*itl).s==l-1){
                (*itl).s = r;
            }
            else if((*itr).f==r+1){
                (*itr).f = l;
            }
            else{
                vp.insert(itr,mp(l,r));
            }
            

            printf("%s %s\n",retl==-1?"*":to_string(retl).c_str(),retr==s+2?"*":to_string(retr).c_str());
        }

        printf("-\n");
    }

    return 0;
}



