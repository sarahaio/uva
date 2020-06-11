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

// "The Canterbury Tales" by Chaucer, G.
// "Algorithms" by Sedgewick, R.
// "The C Programming Language" by Kernighan, B. and Ritchie, D.
// END
// BORROW "Algorithms"
// BORROW "The C Programming Language"
// RETURN "Algorithms"
// RETURN "The C Programming Language"
// SHELVE
// END

// Put title first
// Put "The C Programming Language" after "The Canterbury Tales"
// Put "Algorithms" after "The C Programming Language"
// END

int main(){

    // ios_base::sync_with_stdio(0); cin.tie(0);
    

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    string ss;
    // k: title v: author
    map<string,string> cm;
    // k: author, title v: title
    set<pa<string,string>> cs;
    
    while(getline(cin,ss) && ss != "END"){

        auto it = ss.find('"',1);
        string key = ss.substr(1,it-1);

        int auit = it + 5;
        string aukey = ss.substr(auit,sz(ss)-auit);
        cm[key] = aukey;
        cs.ins(mp(aukey,key));

    }

    set<pa<string,string>> pending;
    // set<pa<string,string>> borrow;

    while(getline(cin,ss) && ss != "END"){
        if(ss=="SHELVE"){
            while(sz(pending)>0){
                auto inspa = *(pending.begin());
                cs.ins(inspa);
                auto it = cs.find(inspa);

                pending.erase(pending.begin());

                if(it==cs.begin()){
                    printf("Put \"%s\" first\n",(*it).s.c_str());
                }
                else{
                    string fst = (*it).second;
                    string sst = (*--it).second;
                    printf("Put \"%s\" after \"%s\"\n",fst.c_str(),sst.c_str());
                }
                // cs.ins(inspa);
            }

            printf("END\n");
            continue;
        }
        string tikey = ss.substr(8,sz(ss)-1-8);
        if(ss.substr(0,6)=="BORROW"){

            string aukey = cm[tikey];
            cs.erase(mp(aukey,tikey));
            // borrow.ins(mp(aukey,tikey));
        }
        else{
            // cs.ins(mp(cm[tikey],tikey));
            pending.ins(mp(cm[tikey],tikey));
        }
    }


    return 0;
}



