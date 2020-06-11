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

struct comp{
    bool operator()(pa<int,int> p1, pa<int,int> p2) const {
        return p1.f < p2.f;
    }
};

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    
    int n;
    int q = 1;
    while(cin >> n && n != 0){

        printf("Scenario #%d\n",q);
        map<int,int> cm;
        vi order(n,-1);
        FOR(i,0,n){
            int k; cin >> k;
            FOR(j,0,k){
                int p; cin >> p;
                cm[p] = i;
            }
        }

        queue<int> qu;
        map<int,queue<int>> cm1;

        string s1;
        while(cin >> s1 && s1 != "STOP"){
            if(s1=="ENQUEUE"){
                int m; cin >> m;
                
                if(nex(cm1,cm[m])){
                    qu.push(cm[m]);
                }
                cm1[cm[m]].push(m);
            }
            else {
                printf("%d\n",cm1[qu.front()].front());
                cm1[qu.front()].pop();
                if(sz(cm1[qu.front()])==0) {
                    cm1.erase(qu.front());
                    qu.pop();
                }

            }
        }

        printf("\n");

        q++;
    }

    return 0;
}



