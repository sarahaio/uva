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

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    
    int t; cin >> t;
    FOR(o,0,t){
        string s1, s2; cin >> s1 >> s2;

        map<string,string> cm1;

        int pos = 1;

        bool flg = false;
        while(sz(s1)>2){
            auto s11 = s1.find(':',pos);
            s11++;
            auto s12 = s1.find(',',s11);
            if(s12==string::npos){
                flg = true;
                s12 = sz(s1) - 1;
            }
            cm1[s1.substr(pos,s11-pos-1)] = s1.substr(s11,s12-s11);
            pos = s12 + 1;
            if(flg) break;
        }
        
        map<string,string> cm2;
        pos = 1;

        flg = false;
        while(sz(s2)>2){
            auto s11 = s2.find(':',pos);
            s11++;
            auto s12 = s2.find(',',s11);
            if(s12==string::npos){
                flg = true;
                s12 = sz(s2) - 1;
            }
            cm2[s2.substr(pos,s11-pos-1)] = s2.substr(s11,s12-s11);
            pos = s12 + 1;
            if(flg) break;
        }

        vs plus; vs minus; vs change;
        for(auto i : cm2){
            if(nex(cm1,i.first)) plus.pb(i.first);
        }
        for(auto i : cm1){
            if(nex(cm2,i.first)) minus.pb(i.first);
        }
        for(auto i : cm1){
            if(ex(cm2,i.first)&&i.second!=cm2[i.first]) change.pb(i.first);
        }

        if(sz(plus)>0){
            printf("+");
            FOR(i,0,sz(plus)){
                if(i!=sz(plus)-1){
                    printf("%s,",plus[i].c_str());
                }
                else{
                    printf("%s\n",plus[i].c_str());
                }
            }
        }
        if(sz(minus)>0){
            printf("-");
            FOR(i,0,sz(minus)){
                if(i!=sz(minus)-1){
                    printf("%s,",minus[i].c_str());
                }
                else{
                    printf("%s\n",minus[i].c_str());
                }
            }
        }
        if(sz(change)>0){
            printf("*");
            FOR(i,0,sz(change)){
                if(i!=sz(change)-1){
                    printf("%s,",change[i].c_str());
                }
                else{
                    printf("%s\n",change[i].c_str());
                }
            }
        }
        if(sz(plus)==0&&sz(minus)==0&&sz(change)==0){
            printf("No changes\n");
        }
        printf("\n");
    }

    return 0;
}



