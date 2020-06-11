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

map<char,char> parent;
map<char,int> prank;

char findset(char inp){
    if(inp != parent[inp]){
        parent[inp] = findset(parent[inp]);
    }
    return parent[inp];
}

void unionset(char c1, char c2){
    char c11 = findset(c1);
    char c12 = findset(c2);
    if(c11 == c12) return;
    if(prank[c11] > prank[c12]){
        prank[c11] += prank[c12];
        parent[c12] = parent[c11];
    }
    else {
        prank[c12] += prank[c11];
        parent[c11] = parent[c12];
    }
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    
    string s1;
    while(getline(cin,s1)){
        parent.clear();
        prank.clear();
        int sl; sl = stoi(s1);
        getline(cin,s1);
        int con; con = stoi(s1);
        string awake; getline(cin,awake);

        parent[awake[0]] = awake[0];
        FOR(i,1,sz(awake)){
            parent[awake[i]] = awake[i];
            unionset(awake[i-1],awake[i]);
        }

        char seed = awake[0];

        map<char,set<int>> sls;
        set<pa<char,char>> vc;
        FOR(i,0,con){
            string k; getline(cin,k);
            if(nex(parent,k[0])) parent[k[0]] = k[0];
            if(nex(parent,k[1])) parent[k[1]] = k[1];

            if(findset(k[0])==findset(k[1])) continue;
            vc.ins(mp(k[0],k[1]));
        }
        
        int count = 0;
        while(sz(vc)>0){
            map<char,set<char>> cm;
            for(auto i : vc){
                if(findset(i.first)==findset(seed)) cm[i.second].insert(i.first);
                if(findset(i.second)==findset(seed)) cm[i.first].insert(i.second);
            }

            int c = 0;
            vector<pa<char,char>> erasec;
            for(auto i : cm){
                if(sz(i.second)>2){
                    c++;
                    unionset(i.first,seed);
                    for(auto j : i.second){
                        erasec.pb(mp(i.first,j));
                    }
                }
            }
            for(auto i : vc){
                if(findset(i.first)==findset(i.second)) erasec.pb(mp(i.first,i.second));
            }

            if(sz(erasec)==0) break;

            for(auto i : erasec){
                vc.erase(i);
            }
            count++;
        }

        int wake = 0;
        for(auto i : parent){
            if(findset(i.first)==findset(seed)) wake++;
        }

        if(wake != sl){
            printf("THIS BRAIN NEVER WAKES UP\n");
        }
        else{
            printf("WAKE UP IN, %d, YEARS\n",count);
        }

        string temp;
        getline(cin,temp);
        if(cin.eof()) break;
    }
    

    return 0;
}



