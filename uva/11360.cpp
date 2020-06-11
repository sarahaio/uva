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

    int t; cin >> t;
    FOR(o,0,t){
        int sze; cin >> sze;
        vs cm;
        FOR(i,0,sze){
            string k; cin >> k;
            cm.pb(k);
        }
        int ope; cin >> ope;
        FOR(j,0,ope){
            string f1; cin >> f1;
            if(f1=="row"){
                int r1; int r2; cin >> r1 >> r2;
                swap(cm[r1-1],cm[r2-1]);
            }
            else if(f1=="col"){
                int r1; int r2; cin >> r1 >> r2;
                FOR(i,0,sze){
                    swap(cm[i][r1-1],cm[i][r2-1]);
                }
            }
            else if(f1 == "inc"){
                FOR(i,0,sze){
                    FOR(j,0,sze){
                        cm[i][j]++;
                        if(cm[i][j]=='9'+1) cm[i][j] = '0';
                    }
                }
            }
            else if(f1 == "dec"){
                FOR(i,0,sze){
                    FOR(j,0,sze){
                        cm[i][j]--;
                        if(cm[i][j]=='0'-1) cm[i][j] = '9';
                    }
                }
            }
            else{
                FOR(i,0,sze){
                    FOR(j,i,sze){
                        swap(cm[i][j],cm[j][i]);
                    }
                }
            }
        }

        printf("Case #%d\n",o+1);
        FOR(i,0,sze){
            printf("%s\n",cm[i].c_str());
        }
        printf("\n");
    }

    return 0;
}



