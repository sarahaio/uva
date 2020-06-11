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

struct comp{
    bool operator()(vi& v1, vi& v2) const{
        if(v1[1] != v2[1]){
            return v1[1] > v2[1];
        }
        if(v1[2] != v2[2]){
            return v1[2] < v2[2];
        }
        return v1[0] < v2[0];
    }
};

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);
    

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    
    string t; getline(cin,t);
    string sk;
    getline(cin,sk);
    FOR(o,0,stoi(t)){

        string ss;
        int cm[105][15];
        FOR(i,0,105){
            FOR(j,0,15){
                cm[i][j] = 0;
            }
        }
        set<int> cs;
        while(getline(cin,ss)&&ss!=""){
            stringstream inp = stringstream(ss);
            int t, p, time; string att;
            inp >> t >> p >> time >> att;

            if(att=="C"){
                if(cm[t][p]<=0){
                    cm[t][p] = abs(cm[t][p]) + time;
                }
            }
            else if(att=="I"){
                if(cm[t][p]<=0){
                    cm[t][p] -= 20;
                }
            }
            cs.ins(t);
        }

        vvi ret;
        FOR(i,0,105){
            bool flg = false;
            int c = 0;
            int time = 0;
            FOR(j,0,15){
                flg = flg || cm[i][j] != 0;
                c += cm[i][j] > 0 ? 1 : 0;
                time += cm[i][j] > 0 ? cm[i][j] : 0;
            }
            if(flg||ex(cs,i)){
                ret.pb(vi({i,c,time}));
            }
        }

        sort(all(ret),comp());

        FOR(i,0,sz(ret)){
            printf("%d %d %d\n",ret[i][0],ret[i][1],ret[i][2]);
        }
        if(o!=stoi(t)-1) printf("\n");

    }

    return 0;
}



