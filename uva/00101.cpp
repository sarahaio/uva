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


// not solve
int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);
    

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    
    string n; getline(cin,n);
    vvi vs(stoi(n),vi());
    FOR(i,0,stoi(n)){
        vs[i].pb(i);
    }

    string s;
    while(getline(cin,s)&&s!="quit"){

        stringstream ss(s);
        string s1; ss >> s1;
        int c1; ss >> c1;
        string s2; ss >> s2;
        int c2; ss >> c2;
        
        if(s1=="move"&&s2=="onto"){
            int flg1 = false, flg2 = false;
            FOR(i,0,sz(vs)){
                FOR(j,0,sz(vs[i])){
                    if(vs[i][j]==c1){
                        flg1 = true;
                        FOR(k,j+1,sz(vs[i])){
                            vs[vs[i][k]].pb(vs[i][k]);
                        }
                        vs[i].pob();
                    }
                    if(flg1) break;
                }
                if(flg1) break;
            }
            FOR(i,0,sz(vs)){
                FOR(j,0,sz(vs[i])){
                    if(vs[i][j]==c2){
                        flg2 = true;
                        FOR(k,j+1,sz(vs[i])){
                            vs[vs[i][k]].pb(vs[i][k]);
                        }
                        vs[i].pb(c1);
                    }
                    if(flg2) break;
                }
                if(flg2) break;
            }
        }
        else if(s1=="move"&&s2=="over"){
            int flg1 = false, flg2 = false;
            FOR(i,0,sz(vs)){
                FOR(j,0,sz(vs[i])){
                    if(vs[i][j]==c1){
                        flg1 = true;
                        FOR(k,j+1,sz(vs[i])){
                            vs[vs[i][k]].pb(vs[i][k]);
                        }
                        vs[i].pob();
                    }
                    if(flg1) break;
                }
                if(flg1) break;
            }
            FOR(i,0,sz(vs)){
                FOR(j,0,sz(vs[i])){
                    if(vs[i][j]==c2){
                        flg2 = true;
                        vs[i].pb(c1);
                    }
                    if(flg2) break;
                }
                if(flg2) break;
            }
        }
        else if(s1=="pile"&&s2=="onto"){
            vi pile;
            int flg1 = false, flg2 = false;
            FOR(i,0,sz(vs)){
                FOR(j,0,sz(vs[i])){
                    if(vs[i][j]==c1){
                        flg1 = true;
                        FOR(k,j,sz(vs[i])){
                            pile.pb(vs[i][k]);
                        }
                        int l = sz(vs[i]) - j;
                        FOR(k,0,l) vs[i].pob();
                    }
                    if(flg1) break;
                }
                if(flg1) break;
            }
            FOR(i,0,sz(vs)){
                FOR(j,0,sz(vs[i])){
                    if(vs[i][j]==c2){
                        flg2 = true;
                        FOR(k,j+1,sz(vs[i])){
                            vs[vs[i][k]].pb(vs[i][k]);
                        }
                        FOR(k,0,sz(pile)){
                            vs[i].pb(pile[k]);
                        }
                    }
                    if(flg2) break;
                }
                if(flg2) break;
            }
        }
        else if(s1=="pile"&&s2=="over"){
            vi pile;
            int flg1 = false, flg2 = false;
            FOR(i,0,sz(vs)){
                FOR(j,0,sz(vs[i])){
                    if(vs[i][j]==c1){
                        flg1 = true;
                        FOR(k,j,sz(vs[i])){
                            pile.pb(vs[i][k]);
                        }
                        int l = sz(vs[i]) - j;
                        FOR(k,0,l) vs[i].pob();
                    }
                    if(flg1) break;
                }
                if(flg1) break;
            }
            FOR(i,0,sz(vs)){
                FOR(j,0,sz(vs[i])){
                    if(vs[i][j]==c2){
                        flg2 = true;
                        FOR(k,0,sz(pile)){
                            vs[i].pb(pile[k]);
                        }
                    }
                    if(flg2) break;
                }
                if(flg2) break;
            }
        }
    }



    return 0;
}



