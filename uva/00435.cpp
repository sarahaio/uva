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
    cin >> t;
    FOR(i,0,t){
        int k;
        cin >> k;

        vi org;
        int sum = 0;
        FOR(j,0,k){
            int m;
            cin >> m;
            sum += m;
            org.pb(m);
        }
        int w = sum / 2 + 1;

        FOR(j,0,k){
            int lsum = 0;
            queue<int> q;
            q.push(0);
            FOR(o,0,k){
                if(j==o) continue;
                int l = sz(q);
                FOR(p,0,l){
                    auto item = q.front();
                    q.pop();
                    if(item + org[o] < w) q.push(item + org[o]);
                    q.push(item);
                }
            }
            int ret = 0;
            while(sz(q)>0){
                // cout<<q.front()<<" ";
                if(q.front()+org[j]>=w) ret++;
                q.pop();
            }
            printf("party %d has power index %d\n",j+1,ret);
        }
        printf("\n");
    }

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343