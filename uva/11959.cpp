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
    
    int t;
    cin >> t;
    FOR(i,0,t){
        
        string s1;
        string s2;
        cin >> s1 >> s2;

        vvi v = {
            {0,1,2,3,4,5},
            {0,1,3,4,5,2},
            {0,1,4,5,2,3},
            {0,1,5,2,3,4},
            {1,0,5,4,3,2},
            {1,0,4,3,2,5},
            {1,0,3,2,5,4},
            {1,0,2,5,4,3},
            {2,4,1,3,0,5},
            {2,4,3,0,5,1},
            {2,4,0,5,1,3},
            {2,4,5,1,3,0},
            {4,2,0,3,1,5},
            {4,2,3,1,5,0},
            {4,2,1,5,0,3},
            {4,2,5,0,3,1},
            {3,5,2,1,4,0},
            {3,5,1,4,0,2},
            {3,5,4,0,2,1},
            {3,5,0,2,1,4},
            {5,3,2,0,4,1},
            {5,3,0,4,1,2},
            {5,3,4,1,2,0},
            {5,3,1,2,0,4},
        };

        bool flg = true;
        FOR(i,0,sz(v)){
            flg = true; 
            FOR(j,0,6){
                if(s1[j]!=s2[v[i][j]]){
                    flg = false;
                    break;
                }
            }
            if(flg){
                break;
            }
        }

        if(flg){
            printf("Equal\n");
        }
        else {
            printf("Not Equal\n");
        }

    }
    
    return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343