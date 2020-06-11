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

// not solve
int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    
    int t; cin >> t;

    FOR(o, 0 ,t){
        int cl; cin >> cl;

        map<string,int> ca;
        map<string,map<string,int>> key;
        vs nameordered;
        FOR(o,0,cl){
            string name; int k, oc; cin >> name >> k >> oc;
            ca[name] = oc;
            FOR(j,0,k){
                string s1; cin >> s1;
                key[s1][name]++;
            }
            nameordered.pb(name);
        }
        
        string s1; getline(cin,s1);
        string s3;
        map<string,int> ltext;
        set<string> vs1;
        
        while(getline(cin,s1)&&s1!=""){
            stringstream s2 = stringstream(s1);
            while(s2>>s3){
                vs retkey;
                if(ex(key,s3)){
                    for(auto p : key[s3]){
                        retkey.pb(p.first);
                    }
                }
                else{
                    for(auto k : key){
                        if(s3.find(k.first)!=string::npos){
                            for(auto p : k.second){
                                retkey.push_back(p.first);
                            }
                        }
                    }
                }
                for(auto p : retkey){
                    ltext[p]++;
                    vs1.insert(p);
                }
            }
        }

        vector<string> ret;
        for(auto p : nameordered){
            if(ltext[p] >= ca[p]) ret.pb(p);
        }

        if(sz(ret)==0){
            printf("SQF Problem.\n");
        }
        FOR(i,0,sz(ret)){
            if(i!=sz(ret)-1){
                printf("%s,",ret[i].c_str());
            }
            else printf("%s\n",ret[i].c_str());
        }
    }
    

    return 0;
}



