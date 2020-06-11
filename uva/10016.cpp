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

vvi vc;
int s;

void upsidedown(int r){
    FOR(i,r,s-r){
        swap(vc[r][i],vc[s-1-r][i]);
    }
    FOR(i,r+1,(s+1)/2){
        swap(vc[i][r],vc[s-1-i][r]);
        swap(vc[i][s-1-r],vc[s-1-i][s-1-r]);
    }
}

void leftright(int r){
    FOR(i,r,s-r){
        swap(vc[i][r],vc[i][s-1-r]);
    }
    FOR(i,r+1,(s+1)/2){
        swap(vc[r][i],vc[r][s-1-i]);
        swap(vc[s-1-r][i],vc[s-1-r][s-1-i]);
    }
}

void maindiagonal(int r){
    FOR(i,r,s-r){
        swap(vc[i][r],vc[r][i]);
    }
    FOR(i,r+1,s-r){
        swap(vc[s-1-r][i],vc[i][s-1-r]);
    }
}

void inversediagonal(int r){
    FOR(i,r,s-r){
        swap(vc[s-1-i][r],vc[s-1-r][i]);
    }
    FOR(i,r+1,s-r){
        swap(vc[r][i],vc[s-1-i][s-1-r]);
    }
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);
    

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    
    int t; cin >> t;
    FOR(o,0,t){
        cin >> s;
        vc = vvi(s,vi(s,0));
        FOR(i,0,s){
            FOR(j,0,s){
                int k; cin >> k;
                vc[i][j] = k;
            }
        }
        int q = (s+1)/2;
        FOR(i,0,q){
            int nq; cin >> nq;
            FOR(j,0,nq){
                int ac; cin >> ac;
                if(ac==1) upsidedown(i);
                else if(ac==2) leftright(i);
                else if(ac==3) maindiagonal(i);
                else inversediagonal(i);
            }
        }

        FOR(i,0,s){
            FOR(j,0,s){
                if(j!=s-1) printf("%d ",vc[i][j]);
                else printf("%d\n",vc[i][j]);
            }
        }
    }

    return 0;
}



