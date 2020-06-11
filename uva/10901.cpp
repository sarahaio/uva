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

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    
    int t; cin >> t;
    FOR(o,0,t){
        if(o!=0) printf("\n");

        int n, p, m; cin >> n >> p >> m;
        queue<pa<int,int>> lq; queue<pa<int,int>> rq;
        FOR(i,0,m){
            int t1; string side; cin >> t1 >> side;
            if(side=="left"){
                lq.push(mp(t1,i));
            }
            else{
                rq.push(mp(t1,i));
            }
        }

        int ct = 0;
        bool isleft = true;
        vi ret(m,0);
        while(sz(lq)>0||sz(rq)>0){
            int lfront = sz(lq)>0?lq.front().f:INT_MAX;
            int rfront = sz(rq)>0?rq.front().f:INT_MAX;
            if(min(lfront,rfront)>ct){
                if(isleft&&lfront>rfront) {
                    ct = rfront + p;
                    isleft = false;
                }
                else if(!isleft&&lfront<rfront) {
                    ct = lfront + p;
                    isleft = true;
                }
                else ct = min(lfront,rfront);
            }
            else{
                if(sz(lq)==0&&isleft) {
                    isleft = false;
                    ct += p;
                }
                else if(sz(rq)==0&&!isleft){
                    isleft = true;
                    ct += p;
                }
            }

            // left to right
            if(isleft){
                int newct = ct + p + (!isleft ? p : 0);
                FOR(i,0,n){
                    if(sz(lq)>0&&ct>=lq.front().f){
                        auto item = lq.front();
                        lq.pop();
                        ret[item.s] = newct;
                    }
                    else break;
                }
                ct = newct;
                
                isleft = !isleft;
            }
            // right to left
            else {
                int newct = ct + p + (isleft ? p : 0);
                FOR(i,0,n){
                    if(sz(rq)>0&&ct>=rq.front().f){
                        auto item = rq.front();
                        rq.pop();
                        ret[item.s] = newct;
                    }
                    else break;
                }
                ct = newct;

                isleft = !isleft;
            }
        }

        for(auto i : ret){
            printf("%d\n",i);
        }
    }

    return 0;
}



