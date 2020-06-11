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

    int n;
    int cu = 1;
    while(cin >> n && n != 0){

        vi ps;
        FOR(i,0,n){
            int t;
            cin >> t;
            ps.pb(t);
        }

        vector<pa<int,int>> seed;
        int m;
        cin >> m;
        FOR(i,0,m){
            int q, r;
            cin >> q >> r;
            seed.pb(mp(q,r));
        }

        map<int,int> cmin;
        vi vmin;
        int gmindiff;

        sort(all(ps));
        do{
            int c = 0;
            vi p;
            p.pb(0);
            FOR(i,0,sz(ps)){
                c += ps[i];
                p.pb(c);
            }

            map<int,int> cl;
            int lmindiff = 0;
            for(auto i : seed){
                auto it = ub(all(p),i.s);
                int mindiff = INT_MAX;
                if(it!=p.end()){
                    mindiff = min(mindiff,abs(*it-i.s));
                }
                if(it!=p.begin()){
                    mindiff = min(mindiff,abs(*(it-1)-i.s));
                }
                cl[i.f]+=mindiff;
                lmindiff += mindiff;
            }

            if(sz(cmin)==0){
                cmin = cl;
                gmindiff = lmindiff;
                vmin = ps;
            }
            else{
                bool flg = true;
                bool allequal = true;
                for(auto i : cmin){
                    if(i.s != cl[i.f]){
                        allequal = false;
                    }
                    if(i.s > cl[i.f]){
                        flg = false;
                        break;
                    }
                    else if(i.s < cl[i.f]){
                        flg = true;
                        break;
                    }
                }
                // if(sz(ps)==6&&ps[0]==15&&ps[1]==13&&ps[2]==33&&ps[3]==25&&ps[4]==18&&ps[5]==10){
                //     cout<<lmindiff<<endl;
                //     for(auto i : cl){
                //         cout<<i.f<<" "<<i.s<<endl;
                //     }
                // }
                // if(sz(ps)==6&&ps[0]==33&&ps[1]==13&&ps[2]==15&&ps[3]==10&&ps[4]==18&&ps[5]==25){
                //     cout<<lmindiff<<endl;
                //     for(auto i : cl){
                //         cout<<i.f<<" "<<i.s<<endl;
                //     }
                // }
                if(!flg||allequal&&lmindiff<gmindiff){
                    cmin = cl;
                    gmindiff = lmindiff;
                    vmin = ps;
                }
            }
        }
        while(next_permutation(all(ps)));

        printf("Data set %d\n",cu);
        printf("Order:");
        FOR(i,0,sz(vmin)){
            printf(" %d",vmin[i]);
        }
        printf("\n");
        printf("Error: %d\n",gmindiff);

        cu++;
    }

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343