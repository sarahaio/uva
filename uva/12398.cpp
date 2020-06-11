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

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);
    

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    
    string s;
    int c = 1;
    while(getline(cin,s)){
        printf("Case #%d:\n",c);
        int cm[3][3] = {};
        FOR(i,0,sz(s)){
            int m = s[i] - 'a';
            int r = m / 3;
            int c = m % 3;

            cm[r][c]++;
            cm[r][c] = cm[r][c] % 10;
            if(r-1>=0) {
                cm[r-1][c]++;
                cm[r-1][c] = cm[r-1][c] % 10;
            }
            if(r+1<3) {
                cm[r+1][c]++;
                cm[r+1][c] = cm[r+1][c] % 10;
            }
            if(c-1>=0) {
                cm[r][c-1]++;
                cm[r][c-1] = cm[r][c-1] % 10;
            }
            if(c+1<3) {
                cm[r][c+1]++;
                cm[r][c+1] = cm[r][c+1] % 10;
            }

        }

        FOR(i,0,3){
            FOR(j,0,3){
                if(j!=2) printf("%d ",cm[i][j]);
                else printf("%d\n",cm[i][j]);
            }
        }
        c++;
    }

    return 0;
}



