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
    
    set<string> exclude;
    string s;
    while(cin >> s && s != "::"){
        exclude.insert(s);
    }

    getline(cin,s);
    int c1 = 0;
    map<pa<string,pa<int,int>>,string> cm;
    while(getline(cin,s)){
        if(sz(s)==0) continue;
        int pos = 0;
        while(s[pos]==' ') pos++;
        if(pos==s.size()) continue;
        auto it = s.find(' ',pos);
        if(it==string::npos) it = sz(s);
        FOR(i,0,sz(s)) s[i] = tolower(s[i]);
        int c2 = 0;
        while(true){
            string t = s.substr(pos,it-pos);
            FOR(i,pos,it) s[i] = toupper(s[i]);
            if(nex(exclude,t)){
                cm.insert(mp(mp(t,mp(c1,c2)),s));
            }
            FOR(i,pos,it) s[i] = tolower(s[i]);
            if(it==sz(s)) break;
            pos = it+1;
            while(s[pos]==' ') pos++;
            if(pos==sz(s)) break;
            it = s.find(' ',pos);
            if(it==string::npos) it = sz(s);
            c2++;
        }

        c1++;
        if(cin.eof()) break;
    }

    for(auto i : cm){
        printf("%s\n",i.s.c_str());
    }

    return 0;
}



