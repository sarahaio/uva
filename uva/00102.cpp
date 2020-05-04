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
 
 void run_case(string s){

    //  B G C
    int inp[3][3];
    stringstream in(s);
    FOR(i,0,3){
        FOR(j,0,3){
            int t;
            in >> t;
            inp[i][j] = t;
        }
    }
    

    int dp[3][3];
    FOR(i,0,3){
        dp[i][0] = inp[i][1] + inp[i][2];
        dp[i][1] = inp[i][0] + inp[i][2];
        dp[i][2] = inp[i][0] + inp[i][1];
    }

    int per[3];
    FOR(i,0,3) per[i] = i;

    int cmin = INT_MAX;

    string cm[] = {"B","G","C"};
    string smin;
    do{
        int t = dp[0][per[0]]+dp[1][per[1]]+dp[2][per[2]];
        if(t < cmin){
            cmin = t;
            smin = cm[per[0]]+cm[per[1]]+cm[per[2]];
        }
        else if(t==cmin){
            string lmin = cm[per[0]]+cm[per[1]]+cm[per[2]];
            if(lmin < smin){
                smin = lmin;
            }
        }
    }
    while(next_permutation(per,per+3));

    printf("%s %d\n",smin.c_str(),cmin);

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // int T; cin >> T;
    // while(T--) {
        // while (1 == scanf("%[^\n]%*c", input)){
            
        // }
        
    // }
    string s;
    while (getline(cin, s))
        run_case(s);
    
    return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343