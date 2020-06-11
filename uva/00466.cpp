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

// 1
// 3 1 2
// 32.0 54.7 -2

vs res;
vs cm;
int sze;
vs target;

void preserve(){
    FOR(i,0,sze){
        FOR(j,0,sze){
            res[i][j] = cm[i][j];
        }
    }
}

void rotate90(vs inp){
    FOR(i,0,sze){
        FOR(j,0,sze){
            res[j][sze-1-i] = inp[i][j];
        }
    }
}

void rotate180(vs inp){
    FOR(i,0,sze){
        FOR(j,0,sze){
            res[sze-1-i][sze-1-j] = inp[i][j];
        }
    }
}

void rotate270(vs inp){
    FOR(i,0,sze){
        FOR(j,0,sze){
            res[sze-1-j][i] = inp[i][j];
        }
    }
}

void vertical(){
    FOR(i,0,sze){
        FOR(j,0,sze){
            res[sze-1-i][j] = cm[i][j];
        }
    }
}

bool comp(){
    FOR(i,0,sze){
        FOR(j,0,sze){
            if(res[i][j]!=target[i][j]) return false;
        }
    }
    return true;
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);
    

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    
    int c = 1;
    while(cin >> sze){
        cm.clear();
        target.clear();

        FOR(i,0,sze){
            string k; cin >> k;
            cm.pb(k);
            string l; cin >> l;
            target.pb(l);
        }

        res = vs(sze,string(sze,'X'));

        printf("Pattern %d was ",c);

        preserve();
        if(comp()){
            printf("preserved.\n");
        }
        else{
            rotate90(cm);
            if(comp()){
                printf("rotated 90 degrees.\n");
            }
            else {
                rotate180(cm);
                if(comp()){
                    printf("rotated 180 degrees.\n");
                }
                else {
                    rotate270(cm);
                    if(comp()){
                        printf("rotated 270 degrees.\n");
                    }
                    else{
                        vertical();
                        if(comp()){
                            printf("reflected vertically.\n");
                        }
                        else{
                            vertical();
                            rotate90(res);
                            if(comp()){
                                printf("reflected vertically and rotated 90 degrees.\n");
                            }
                            else{
                                vertical();
                                rotate180(res);
                                if(comp()){
                                    printf("reflected vertically and rotated 180 degrees.\n");
                                }
                                else{
                                    vertical();
                                    rotate270(res);
                                    if(comp()){
                                        printf("reflected vertically and rotated 270 degrees.\n");
                                    }
                                    else{
                                        printf("improperly transformed.\n");
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        c++;
    }

    return 0;
}



