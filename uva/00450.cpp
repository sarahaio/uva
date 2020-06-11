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

struct comp{
    bool operator()(vs& v1, vs& v2) const{
        if(v1[2]!=v2[2]) return v1[2] < v2[2];
        return v1[1] < v2[1];
    }
};

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);
    

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    
    string t;
    getline(cin,t);
    vector<vector<string>> cm;
    FOR(o,0,stoi(t)){
        string dep; getline(cin,dep);
        
        string info;
        while(getline(cin,info)&&info!=""){
        
            int pos = 0;
            auto it = info.find(',',pos);
            string title = info.substr(pos,it-pos);
            pos = it + 1;

            it = info.find(',',pos);
            string fn = info.substr(pos,it-pos);
            pos = it + 1;

            it = info.find(',',pos);
            string ln = info.substr(pos,it-pos);
            pos = it + 1;

            it = info.find(',',pos);
            string addr = info.substr(pos,it-pos);
            pos = it + 1;

            it = info.find(',',pos);
            string home = info.substr(pos,it-pos);
            pos = it + 1;

            it = info.find(',',pos);
            string work = info.substr(pos,it-pos);
            pos = it + 1;

            string mail = info.substr(pos,sz(info)-pos);

            cm.pb(vs({title,fn,ln,addr,home,work,mail,dep}));

            if(cin.eof()) break;
        }
    }

    sort(all(cm),comp());

    for(auto i : cm){
        printf("----------------------------------------\n");
        printf("%s %s %s\n",i[0].c_str(),i[1].c_str(),i[2].c_str());
        printf("%s\n",i[3].c_str());
        printf("Department: %s\n",i[7].c_str());
        printf("Home Phone: %s\n",i[4].c_str());
        printf("Work Phone: %s\n",i[5].c_str());
        printf("Campus Box: %s\n",i[6].c_str());
    }

    return 0;
}



