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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    string s = "";
    while(getline(cin,s) && s!="0"){
        stringstream in(s);
        string t = "";
        in >> t;
        t.pob();
        int le = stoi(t);
        vi vs;
        FOR(i,0,le){
            int ti = 0;
            in >> ti;
            vs.pb(ti);
        }

        vvi v(le+1,vi(2*le+1,0));
        bool flg = true;
        FOR(i,0,sz(vs)){
            FOR(j,0,i){
                int diff = vs[i]-vs[j]+le;
                v[vs[i]][diff] = v[vs[j]][diff] + 1;
                if(v[vs[i]][diff]>=2) {
                    flg = false;
                    break;
                }
            }
            if(!flg){
                break;
            }
        }
        // for(auto i : v){
        //     for(auto j : i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        if(!flg) printf("no\n");
        else printf("yes\n");
    }
    
    return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343