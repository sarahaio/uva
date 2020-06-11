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

map<char,set<char>> cm;
map<char,int> cs;
map<int,set<char>> ccount;

void dfs(char cc, int count){

    if(cs[cc]!=0) return;
    cs[cc] = count;
    ccount[count].insert(cc);
    for(auto i : cm[cc]){
        dfs(i,count);
    }

}


int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    
    while(true){
        int m, n; cin >> m >> n;
        if(cin.eof()) break;
        int cm[m][n];
        FOR(i,0,m) FOR(j,0,n) cm[i][j] = 0;

        FOR(i,0,m){
            int k; cin >> k;
            vi nonz;
            FOR(j,0,k){
                int p; cin >> p;
                nonz.pb(p-1);
            }
            for(auto p : nonz){
                int l; cin >> l;
                cm[i][p] = l;
            }
        }

        printf("%d %d\n",n,m);
        FOR(i,0,n){
            vi nonz;
            FOR(j,0,m){
                if(cm[j][i]) nonz.pb(j);
            }
            if(sz(nonz)!=0) printf("%d ",sz(nonz));
            else printf("%d",sz(nonz));
            FOR(j,0,sz(nonz)){
                if(j!=sz(nonz)-1) printf("%d ",nonz[j]+1);
                else printf("%d",nonz[j]+1);
            }
            printf("\n");
            FOR(j,0,sz(nonz)){
                if(j!=sz(nonz)-1) printf("%d ",cm[nonz[j]][i]);
                else printf("%d",cm[nonz[j]][i]);
            }
            printf("\n");
        }
        if(cin.eof()) break;
    }
    

    return 0;
}



