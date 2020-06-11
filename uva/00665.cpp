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
    
    string t;
    getline(cin,t);
    FOR(o,0,stoi(t)){
        if(o!=0) printf("\n");

        string sada;
        getline(cin,sada);
        string haha;
        getline(cin,haha);
        stringstream s1 = stringstream(haha);
        int coi, wei;
        s1 >> coi >> wei;
        vs ne;
        set<int> eqs;

        FOR(l,0,wei){
            string vtemp;
            getline(cin,vtemp);
            string equa;
            getline(cin,equa);

            if(equa!="="){
                ne.pb(vtemp);
            }
            else{
                stringstream ss = stringstream(vtemp);
                int num;
                ss >> num;
                FOR(j,0,2*num){
                    int eq; ss >> eq;
                    eqs.ins(eq);
                }
            }
        }
        

        int ret = 0;
        FOR(i,0,sz(ne)){
            stringstream ss = stringstream(ne[i]);
            int j; ss >> j;
            int note = 0;
            int exi = 0;
            int tret = 0;
            FOR(k,0,j*2){
                int m; ss >> m;
                if(ex(eqs,m)) exi++;
                else {
                    note++;
                    tret = m;
                }
            }
            if(note==1){
                ret = tret;
                break;
            }
        }

        if(sz(eqs)==coi-1){
            FOR(i,1,coi+1){
                if(nex(eqs,i)){
                    ret = i;
                    break;
                }
            }
        }

        printf("%d\n",ret);
    }

    return 0;
}



