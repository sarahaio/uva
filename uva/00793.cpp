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

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    
    string p; getline(cin,p);
    string n;
    getline(cin,n);
    FOR(o,0,stoi(p)){
        if(o!=0) printf("\n");
        int m;
        getline(cin,n); m = stoi(n);
        int suc = 0, uns = 0;

        vi cm(m+1,0);
        vvi cm1(m+1,vi());
        while(getline(cin,n) && n != ""){
            stringstream ss1(n);
            string s1; ss1 >> s1;
            int c1, c2; ss1 >> c1 >> c2;
            if(s1=="c"){
                if(c1==c2){
                    continue;
                }
                else if(cm[c1]==0 && cm[c2]==0){
                    cm[c1] = c1;
                    cm[c2] = cm[c1];
                    cm1[c1].pb(c2);
                    cm1[c1].pb(c1);
                }
                else if(cm[c1]!=0 && cm[c2]!=0){
                    if(cm[c1]==cm[c2]) continue;
                    int t= cm[c2];
                    for(auto i : cm1[cm[c2]]){
                        cm[i] = cm[c1];
                        cm1[cm[c1]].pb(i);
                    }
                    cm1[t].clear();
                }
                else if(cm[c1]!=0){
                    cm[c2] = cm[c1];
                    cm1[cm[c1]].pb(c2);
                }
                else {
                    cm[c1] = cm[c2];
                    cm1[cm[c2]].pb(c1);
                }
            }
            else{
                if(c1==c2) suc++;
                else{
                    if(cm[c1]!=0&&cm[c2]!=0&&cm[c1]==cm[c2]) suc++;
                    else uns++;
                }
            }
        }

        printf("%d,%d\n",suc,uns);
    }

    return 0;
}



