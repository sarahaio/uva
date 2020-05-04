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
    {0,1},
    {-1,-1},
    {-1,1},
    {1,-1},
    {1,1}
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int t = 0;
    cin>>t;
    FOR(i,0,t){
        int r = 0, c = 0, q = 0;
        cin >> r >> c >> q;
        vs ss;
        FOR(j,0,r){
            string s = "";
            cin >> s;
            ss.pb(s);
        }

        printf("%d %d %d\n",r,c,q);
        FOR(j,0,q){
            int rqu = 0, cqu = 0;
            cin >> rqu >> cqu;

            vvi dp(r+2,vi(c+2,0));
            dp[rqu+1][cqu+1] = 1;
            char tar = ss[rqu][cqu];

            queue<pa<int,int>> q;
            q.push(mp(rqu,cqu));
            int ret = 0;
            while(true){
                bool flg = true;
                int l = sz(q);
                FOR(k,0,l){
                    auto item = q.front();
                    q.pop();
                    if(item.f < 0 || item.s < 0 || item.f >= r || item.s >= c || ss[item.f][item.s]!=tar){
                        flg = false;
                        break;
                    }
                    for(auto d : ds){
                        int x = item.f + d[0];
                        int y = item.s + d[1];
                        if(dp[x+1][y+1]==0){
                            dp[x+1][y+1] = 1;
                            q.push(mp(x,y));
                        }
                    }
                }
                if(!flg) break;
                else ret++;
            }

            printf("%d\n",ret*2-1);
        }
    }
    
    return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343