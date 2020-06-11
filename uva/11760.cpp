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
    
    int m, n, s;
    int c = 1;
    while(cin >> m >> n >> s && (m!=0 || n != 0 || s != 0)){

        int sx[m]; int sy[n];
        memset(sx,0,sizeof(sx)); memset(sy,0,sizeof(sy));
        FOR(i,0,s){
            int x1, y1; cin >> x1 >> y1;
            sx[x1] = 1; sy[y1] = 1;
        }

        int x2, y2; cin >> x2 >> y2;

        bool flg = false;
        if(sx[x2]==0&&sy[y2]==0) flg = true;
        if(x2-1>=0&&sx[x2-1]==0&&sy[y2]==0) flg = true;
        if(y2-1>=0&&sx[x2]==0&&sy[y2-1]==0) flg = true;
        if(x2+1<m&&sx[x2+1]==0&&sy[y2]==0) flg = true;
        if(y2+1<n&&sx[x2]==0&&sy[y2+1]==0) flg = true;

        if(flg) printf("Case %d: Escaped again! More 2D grid problems!\n",c);
        else printf("Case %d: Party time! Let's find a restaurant!\n",c);

        c++;
    }

    return 0;
}



