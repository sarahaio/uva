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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin>>t;
    int y = 1;
    while(t!=-1){
        vector<double> ds;
        vector<double> gs;
        vector<double> ts;
        FOR(i,0,t){
            double d, g, y, r;
            cin >> d >> g >> y >> r;
            ds.pb(d);
            gs.pb((g+y));
            ts.pb((g+y+r));
        }

        vi ret;
        FOR(i,30,61){
            bool flg = true;
            FOR(j,0,t){
                double te = ds[j]  * 3600 / i;
                // cout << te << endl;
                if(fmod(te,ts[j])>gs[j]) {
                    flg = false;
                    break;
                }
            }
            if(flg){
                ret.pb(i);
            }
        }

        // for(auto i : ret){
        //     cout<<i<<" ";
        // }

        if(sz(ret)==0){
            printf("Case %d: No acceptable speeds.\n",y);
        }
        else{
            printf("Case %d: ",y);
            int st = -1;
            FOR(i,0,sz(ret)){
                if(st==-1) st = ret[i];
                else{
                    if(ret[i]==ret[i-1]+1) continue;
                    else {
                        if(ret[i-1]==st) printf("%d, ",ret[i-1]);
                        else printf("%d-%d, ",st,ret[i-1]);
                        st = ret[i];
                    }
                }
            }
            if(ret[sz(ret)-1]==st) printf("%d",ret[sz(ret)-1]);
            else printf("%d-%d",st,ret[sz(ret)-1]);
            printf("\n");
        }

        y++;
        cin >> t;
    }

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343