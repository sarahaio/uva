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

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);
    

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    
    int t; cin >> t;
    FOR(o,0,t){
        if(o!=0) printf("\n");
        int lines; cin >> lines;
        map<string,int> cm;
        FOR(i,0,lines){
            string s; cin >> s;
            string t = "";
            FOR(j,0,sz(s)){
                if(s[j]>='0'&&s[j]<='9'){
                    t.pb(s[j]);
                }
                else if(s[j]>='A'&&s[j]<='Y'){
                    if(s[j]=='A'||s[j]=='B'||s[j]=='C') t.pb('2');
                    else if(s[j]=='D'||s[j]=='E'||s[j]=='F') t.pb('3');
                    else if(s[j]=='G'||s[j]=='H'||s[j]=='I') t.pb('4');
                    else if(s[j]=='J'||s[j]=='K'||s[j]=='L') t.pb('5');
                    else if(s[j]=='M'||s[j]=='N'||s[j]=='O') t.pb('6');
                    else if(s[j]=='P'||s[j]=='R'||s[j]=='S') t.pb('7');
                    else if(s[j]=='T'||s[j]=='U'||s[j]=='V') t.pb('8');
                    else if(s[j]=='W'||s[j]=='X'||s[j]=='Y') t.pb('9');
                }
            }
            t.insert(t.begin()+3,'-');
            cm[t]++;
        }

        vs once;
        for(auto i : cm){
            if(i.s==1) once.pb(i.f);
        }
        for(auto i : once) cm.erase(i);

        if(sz(cm)==0){
            printf("No duplicates.\n");
        }
        else{
            for(auto i : cm){
                printf("%s %d\n",i.first.c_str(),i.s);
            }
        }
        // printf("\n");
    }

    return 0;
}



