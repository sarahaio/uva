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
#include <bitset>
#include <deque>

 
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

const int maxel = 32005;
int parent[maxel];
int rankp[maxel];

int findelem(int x1){
    if(parent[x1]!=x1){
        parent[x1] = findelem(parent[x1]);
    }
    return parent[x1];
}

void unionset(int elem1, int elem2){
    int rx = findelem(elem1);
    int ry = findelem(elem2);
    if(rx == ry) return;
    if(rankp[rx]>rankp[ry]){
        rankp[rx] += rankp[ry];
        parent[ry] = parent[rx];
    }
    else{
        rankp[ry] += rankp[rx];
        parent[rx] = parent[ry];
    }
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    
    int n, m;
    while(cin >> n >> m && (n != 0 || m != 0)){

        FOR(i,0,n+1){
            parent[i] = i;
            rankp[i] = 0;
        }

        FOR(i,0,m){
            int k; cin >> k;
            
            int elem = -1;
            FOR(j,0,k){
                int p; cin >> p;
                
                if(elem==-1){
                    elem=p;
                }
                else{
                    unionset(elem,p);
                }

            }
            
        }

        int parent0 = findelem(0);
        int c = 0;
        FOR(i,0,n+1){
            if(findelem(i)==parent0) c++;
        }
        printf("%d\n",c);
    }

    return 0;
}



