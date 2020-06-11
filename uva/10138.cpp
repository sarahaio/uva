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
    bool operator()(pa<string,pa<string,int>> p1, pa<string,pa<string,int>> p2) const{
        if(p1.f != p2.f) return p1.f < p2.f;
        
        return p1.s < p2.s;
    }
};

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    
    string t; getline(cin,t);
    string b; getline(cin,b);
    FOR(o,0,stoi(t)){

        if(o!=0) printf("\n");

        string numbers; getline(cin,numbers);
        stringstream ss1 = stringstream(numbers);
        vi numb;
        int nu;
        while(ss1 >> nu){
            numb.pb(nu);
        }
        string plates;

        map<string,vector<pa<string,pa<string,int>>>> cm;
        while(getline(cin,plates)&&plates!=""){
            stringstream p1 = stringstream(plates);
            string vehicle, time, action; int distance; p1 >> vehicle >> time >> action >> distance;
            cm[vehicle].pb(mp(time,mp(action,distance)));
        }

        for(auto i : cm){
            sort(all(i.s),comp());
            if(sz(i.s)==1) continue;
            double total = -1;
            for(int j = 0; j < sz(i.s); j++){
                if(j+1>=sz(i.s) || i.s[j].second.first!="enter" || i.s[j+1].second.first!="exit") continue;
                if(total==-1) total = 2;
                total += 1;
                int m1 = stoi(i.s[j].f.substr(0,2));
                int d1 = stoi(i.s[j].f.substr(3,2));
                int h1 = stoi(i.s[j].f.substr(6,2));
                int mi1 = stoi(i.s[j].f.substr(9,2));

                int m2 = stoi(i.s[j+1].f.substr(0,2));
                int d2 = stoi(i.s[j+1].f.substr(3,2));
                int h2 = stoi(i.s[j+1].f.substr(6,2));
                int mi2 = stoi(i.s[j+1].f.substr(9,2));

                total += numb[h1] * abs(i.s[j+1].s.second - i.s[j].s.second) / 100.0;
            }
            // if(total > 0) total += 2;

            if(total >= 0){
                printf("%s $%.2lf\n",i.f.c_str(),total);
            }
        }

    }

    return 0;
}



