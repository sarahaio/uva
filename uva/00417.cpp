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

vector<string> cs;

void dfs(string s1, int l){

    if(l==0) return;
    if(sz(s1)>0) cs.pb(s1);
    int a = 0;
    if(sz(s1)>0) a = s1[sz(s1)-1] - 'a' + 1;
    FOR(i,a,26){
        char next = 'a' + i;
        if(next >= 'a' && next <= 'z'){
            s1.pb(next);
            dfs(s1,l-1);
            s1.pob();
        }
    }

}

struct comp{
    bool operator()(string& s1, string& s2) const{
        if(sz(s1)!=sz(s2)){
            return sz(s1) < sz(s2);
        }
        FOR(i,0,sz(s1)){
            if(s1[i]!=s2[i]) return s1[i]<s2[i];
        }
        return s1 < s2;
    }
};

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    
    dfs("",6);
    sort(all(cs),comp());

    map<string,int> cm;
    FOR(i,0,sz(cs)){
        cm[cs[i]] = i + 1;
    }

    int ci = 1;

    string s1;
    while(cin >> s1){

        printf("%d\n",cm[s1]);

    }

    return 0;
}



