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

struct comp{
    bool operator()(pa<int,string> p1, pa<int,string> p2) const{
        if(p1.f!=p2.f){
            return p1.first < p2.first;
        }
        return p1.second < p2.second;
    }
};

// not solve
int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    
    string s1; getline(cin,s1);
    int t = stoi(s1);
    FOR(i,0,t){
        getline(cin,s1);
        string name = s1;

        int ingr, rec, budget; cin >> ingr >> rec >> budget;
        map<string,int> cingr;
        FOR(o,0,ingr){
            string name; int co; cin >> name >> co;
            cingr[name] = co;
        }

        vector<pa<string,map<string,int>>> recs;
        FOR(o,0,rec){
            getline(cin,s1);
            getline(cin,s1);
            string recname = s1;
            int numb; cin >> numb;
            map<string,int> cm1;
            FOR(j,0,numb){
                string s2; int num2; cin >> s2 >> num2;
                cm1[s2] = num2;
            }
            recs.pb(mp(recname,cm1));
        }

        vector<pa<int,string>> ret;

        for(auto i : recs){

            int total = 0;
            for(auto j : i.s){
                total += j.second * cingr[j.first];
                if(total > budget) break;
            }
            if(total <= budget){
                ret.pb(mp(total,i.first));
            }

        }

        sort(all(ret));

        FOR(i,0,sz(name)){
            name[i] = toupper(name[i]);
        }

        printf("%s\n",name.c_str());
        if(sz(ret)==0){
            printf("Too expensive!\n");
        }
        else{
            set<string> printed;
            for(auto i : ret){
                if(nex(printed,i.second)){
                    printf("%s\n",i.second.c_str());
                    printed.insert(i.second);
                }
            }
        }
        printf("\n");
        getline(cin,s1);
    }

    return 0;
}



