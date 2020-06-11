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

const int maxval = 20010;
int friends[maxval];
int crank[maxval];
int n;

int finde(int i1){
    if(friends[i1]!=i1){
        friends[i1] = finde(friends[i1]);
    }
    return friends[i1];
}

void unionf(int f1, int f2){
    if(f1 == f2){
        return;
    }
    else if(crank[f1] < crank[f2]){
        crank[f2] += crank[f1];
        friends[f1] = friends[f2];
    }
    else{
        crank[f1] += crank[f2];
        friends[f2] = friends[f1];
    }
}

int getenemies(int i1){
    return i1 + n;
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    
    cin >> n;
    FOR(i,0,maxval){
        friends[i] = i;
        crank[i] = 0;
    }
    int c1, c2, c3;
    while(cin >> c1 >> c2 >> c3 && (c1 != 0 || c2 != 0 || c3 != 0)){

        if(c1==1){
            if(finde(getenemies(c2))==finde(c3) || finde(getenemies(c3)) == finde(c2)){
                printf("-1\n");
                continue;
            }
            // union enemy
            unionf(finde(getenemies(c2)),finde(finde(getenemies(c3))));
            // union friends
            unionf(finde(c2),finde(c3));
        }
        else if(c1==2){
            if(finde(c2)==finde(c3) || finde(getenemies(c3)) == finde(getenemies(c2))){
                printf("-1\n");
                continue;
            }
            unionf(finde(c2),finde(getenemies(c3)));
            unionf(finde(c3),finde(getenemies(c2)));
        }
        else if(c1==3){
            printf("%d\n",finde(c2)==finde(c3)?1:0);
        }
        else{
            printf("%d\n",finde(c2) == finde(getenemies(c3))?1:0);
        }

    }

    return 0;
}



