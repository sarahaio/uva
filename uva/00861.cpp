#pragma GCC optimize("O3")
#pragma GCC target("sse4")

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
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;

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

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = b; i > a; i--)
#define F0Rd(i, a) for (int i = a; i > -1; i--)

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
#define ex(m, i) m.find(i) != m.end()
#define nex(m, i) m.find(i) == m.end()

#define uniq(x) x.resize(unique(all(x)) - x.begin())

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy
const vvi ds = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}};

const double epsilon = 1e-9;

int n;
ll c ,k;
int minv[16];
int sumv[16];
ll cache[10][65];

void diagonaldfs(int k, int rc, int cc){
    if(k==0){
        c++;
        return;
    }

    if(cc==n) return;

    if(rc==n-1){
        int rl = rc;
        int cl = cc;
        while(true){
            if(minv[rl-cl+n]==0){
                minv[rl-cl+n]=1;
                diagonaldfs(k-1,rc,cc+1);
                minv[rl-cl+n]=0;
            }
            rl--;
            cl++;
            if(rl<0||cl>=n) break;
        }
    }
    else{
        int rl = rc;
        int cl = cc;
        while(true){
            if(minv[rl-cl+n]==0){
                minv[rl-cl+n]=1;
                diagonaldfs(k-1,rc+1,cc);
                minv[rl-cl+n]=0;
            }
            rl--;
            cl++;
            if(rl<0||cl>=n) break;
        }
    }

    if(rc==n-1) diagonaldfs(k,rc,cc+1);
    else diagonaldfs(k,rc+1,cc);
}

void dfs(int k, int i){
    if(k==0) {
        c++;
        return;
    }

    if(i==n*n) return;

    int j = i % n;
    int o = i / n;
    if(minv[j-o+n]==0&&sumv[j+o]==0){
        minv[j-o+n] = 1;
        sumv[j+o] = 1;
        dfs(k-1,i+1);
        sumv[j+o] = 0;
        minv[j-o+n] = 0;
    }

    dfs(k,i+1);

}

void dp(){
    
    vi row1;
    vi row2;
    FOR(i,1,n+1){
        if(i==n){
            if(i%2) row1.pb(i);
            else row2.pb(i);
        }
        else{
            if(i%2){
                row1.pb(i);
                row1.pb(i);
            }
            else{
                row2.pb(i);
                row2.pb(i);
            }
        }
    }

    int n1 = sz(row1);
    int n2 = sz(row2);
    int dp1[10][70]; int dp2[10][70];
    memset(dp1,0,sizeof(dp1));
    memset(dp2,0,sizeof(dp2));

    dp1[0][0] = 1; dp1[0][1] = 1;
    dp2[0][0] = 1; dp2[0][1] = 2;

    for(int i = 1; i < sz(row1); i++){
        dp1[i][0] = 1;
        for(int j = 1; j < i + 2; j++){
            dp1[i][j] = dp1[i-1][j] + dp1[i-1][j-1] * (row1[i] - (j - 1));
        }
    }

    for(int i = 1; i < sz(row2); i++){
        dp2[i][0] = 1;
        for(int j = 1; j < i + 2; j++){
            dp2[i][j] = dp2[i-1][j] + dp2[i-1][j-1] * (row2[i] - (j-1));
        }
    }

    FOR(i,0,k+1){
        c += dp1[n1 - 1][i] * dp2[n2 - 1][k - i];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    memset(cache,-1,sizeof(cache));

    while(cin >> n >> k && (n!=0 || k != 0)){

        if(k==0||n==1) {
            printf("%d\n",1);
            continue;
        }
        if(cache[n][k]!=-1) {
            printf("%lld\n",cache[n][k]);
            continue;
        }

        c = 0;
        memset(minv,0,sizeof(minv));
        memset(sumv,0,sizeof(sumv));

        // dfs(k,0);
        // diagonaldfs(k,0,0);
        dp();

        cache[n][k] = c;

        printf("%lld\n",c);

    }

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343