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
 

//  not solved
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    int cases = 1;
    while(cin >> n && cin >> m && (n!=0 || m != 0)){

        vl packets;
        vi sizes(n,0);
        FOR(i,0,n){
            ll siz;
            cin >> siz;
            sizes[i] = siz;
            if(siz==64){
                packets.pb(-1LL);
            }
            else{
                packets.pb((1 << siz) - 1);
            }
        }

        int cb = 0;
        int maxb = 0;
        vi reles(n,0);
        FOR(i,0,m){
            int k1, k2, k3;
            cin >> k1 >> k2 >> k3;
            k1--;
            k2--;
            k3--;
            FOR(j,k2,k3+1){
                packets[k1] = packets[k1] ^ 1 << j - reles[k1];
            }

            cb += k3 - k2 + 1;
            if(packets[k1]>0){
                
            }
            else{
                cb -= sizes[k1];
                sizes[k1] = 0;
            }
            
            // cout<<cb<<endl;
            // maxb=max(maxb,k3-k2+1);
            maxb = max(maxb,cb);
        }

        printf("Case %d: %d\n\n",cases,maxb);

        cases++;

    }
    
    return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343