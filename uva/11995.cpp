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
    
    while(true){
        string n; cin >> n;
        if(cin.eof()) break;

        vector<pa<int,int>> vc;
        FOR(i,0,stoi(n)){
            int k,d; cin >> k >> d;
            vc.pb(mp(k,d));
        }

        bool iss = true;
        bool isq = true;
        bool ispq = true;

        // stack
        stack<int> st;
        bool flgcont = false;
        for(auto i : vc){
            if(i.first==1){
                st.push(i.s);
            }
            else{
                if(sz(st)==0){
                    printf("impossible\n");
                    flgcont = true;
                    break;
                }
                auto item = st.top();
                st.pop();
                if(item!=i.s){
                    iss = false;
                    break;
                }
            }
        }
        if(flgcont) continue;

        // queue
        queue<int> q;
        for(auto i : vc){
            if(i.first==1){
                q.push(i.second);
            }
            else{
                auto item = q.front();
                q.pop();
                if(item!=i.s){
                    isq = false;
                    break;
                }
            }
        }

        // pq
        priority_queue<int,vi> pq;
        for(auto i : vc){
            if(i.first==1){
                pq.push(i.second);
            }
            else{
                auto item = pq.top();
                pq.pop();
                if(item!=i.s){
                    ispq = false;
                    break;
                }
            }
        }

        if(!iss){
            if(!isq){
                if(!ispq){
                    printf("impossible\n");
                }
                else {
                    printf("priority queue\n");
                }
            }
            else{
                if(!ispq){
                    printf("queue\n");
                }
                else {
                    printf("not sure\n");
                }
            }
        }
        else{
            if(!isq){
                if(!ispq){
                    printf("stack\n");
                }
                else {
                    printf("not sure\n");
                }
            }
            else{
                printf("not sure\n");
            }
        }
        
        if(cin.eof()) break;
    }

    return 0;
}



