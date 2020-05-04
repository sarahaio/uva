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
 
 void run_case(int s){

    int st = 0;
    int en = pow(10,s/2);

    FOR(i,st,en){
        FOR(j,st,en){
            if((i+j)*(i+j)==en*i+j){
                printf("%0*d%0*d\n",s/2,i,s/2,j);
            }
        }
    }

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int t = 0;
    cin >> t;
    FOR(i,0,t){
        int cl = 0;
        cin >> cl;
        string e;
        getline(cin,e);

        vector<pa<int,pa<int,int>>> v;
        FOR(j,0,cl){
            string s = "";
            getline(cin,s);
            // cout<<"getline "<<s<<endl;
            v.pb(mp(stoi(s.substr(0,4)),mp(s[5]-'0',s[7]-'0')));
        }

        // for(auto i : v){
        //     cout<< i.f << " "<<i.s.f<<" "<<i.s.s<<endl;
        // }

        vi ret;

        FOR(j,0,10000){
            bool flg = true;
            for(auto iv : v){
                int m = 0;
                int n = 0;
                vi vo(10,0);
                vi vt(10,0);
                int to = j;
                int tt = iv.f;
                FOR(k,0,4){
                    if(to%10==tt%10) m++;
                    else {
                        vo[to%10]++;
                        vt[tt%10]++;
                    }
                    to/=10;
                    tt/=10;
                }
                FOR(k,0,10){
                    n += min(vo[k],vt[k]);
                }
                if(m!=iv.s.f||n!=iv.s.s) {
                    flg = false;
                    break;
                }
            }
            if(flg){
                ret.pb(j);
            }
        }

        if(sz(ret)==0) printf("impossible\n");
        else if(sz(ret)==1) printf("%04d\n",ret[0]);
        else printf("indeterminate\n");

    }
    
    return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343