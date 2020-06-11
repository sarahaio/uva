// #pragma GCC optimize("O3")
// #pragma GCC target("sse4")

// // #include <bits/stdc++.h>
// #include <vector>
// #include <complex>
// #include <unordered_map>
// #include <unordered_set>
// #include <iostream>
// #include <random>
// #include <queue>
// #include <algorithm>
// #include <climits>
// #include <map>
// #include <set>
// #include <stack>
// #include <sstream>

// using namespace std;

// typedef long long ll;
// typedef long double ld;
// typedef complex<ld> cd;

// typedef pair<int, int> pi;
// typedef pair<ll, ll> pl;
// typedef pair<ld, ld> pd;

// typedef vector<int> vi;
// typedef vector<ld> vd;
// typedef vector<ll> vl;
// typedef vector<pi> vpi;
// typedef vector<pl> vpl;
// typedef vector<pd> vpd;
// typedef vector<cd> vcd;
// typedef vector<string> vs;
// typedef vector<vi> vvi;
// typedef vector<vl> vvl;

// #define FOR(i, a, b) for (int i = a; i < b; i++)
// #define F0R(i, a) for (int i = 0; i < (a); i++)
// #define FORd(i, a, b) for (int i = b; i > a; i--)
// #define F0Rd(i, a) for (int i = a; i > -1; i--)

// #define sz(x) (int)(x).size()
// #define mp make_pair
// #define pb push_back
// #define pob pop_back
// #define f first
// #define s second
// #define lb lower_bound
// #define ub upper_bound
// #define all(x) x.begin(), x.end()
// #define ins insert
// #define que queue
// #define pa pair
// #define ex(m, i) m.find(i) != m.end()
// #define nex(m, i) m.find(i) == m.end()

// #define uniq(x) x.resize(unique(all(x)) - x.begin())

// // mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// const int MOD = 1000000007;
// const ll INF = 1e18;
// const int MX = 100001; //check the limits, dummy
// const vvi ds = {
//     {-1, 0},
//     {1, 0},
//     {0, -1},
//     {0, 1}};

// pa<int,vi> dfs(int ci, int val, vi& ret, map<int,vi>& cm, vi& v){

//     if(val == 3){
//         // set 0
//         v[ci] = 0;
//         int cmax = 0;
//         bool flg = true;
//         vi garr;
//         int lsum = 0;
//         vi larr;
//         for(auto i : cm[ci]){
//             if(v[i]==-1){
//                 auto res = dfs(i,3,ret,cm,v);
//                 if(res.f==-1) {
//                     flg = false;
//                     break;
//                 }
//                 else{
//                      lsum += res.f; 
//                      for(auto j : res.s){
//                          larr.pb(j);
//                      }
//                 }
//             }
//         }
//         if(flg&&lsum>cmax){
//             cmax = lsum;
//             garr = larr;
//         }
//         v[ci] = -1;

//         // set 1
//         flg = true;
//         for(auto j : cm[ci]){
//             if(v[j]) {
//                 flg = false;
//                 break;
//             }
//         }
//         if(flg){
//             v[ci] = 1;
//             lsum = 0;
//             larr = vi();
//             for(auto i : cm[ci]){
//                 if(v[i]==-1){
//                     auto ress = dfs(i,0,ret,cm,v);
//                     if(ress.f==-1){
//                         flg=false;
//                         break;
//                     }
//                     else{
//                         lsum += ress.f;
//                         for(auto j : ress.s){
//                             larr.pb(j);
//                         }
//                     }
//                 }
//             }

//             if(flg&&lsum>cmax){
//                 cmax = lsum;
//                 garr = larr;
//             }
//             v[ci] = -1;
//         }

//         return mp(cmax,garr);
       
//     }
//     else {
//         bool flg = true;
//         int lsum =0;
//         vi larr;
//         v[ci] = 0;
//         for(auto i : cm[ci]){
//             if(v[ci] == -1){
//                 auto res = dfs(ci,3,ret,cm,v);
//                 if(res.f==-1){
//                     flg = false;
//                     break;
//                 }
//                 else{
//                     lsum += res.f;
//                     for(auto i : res.s){
//                         larr.pb(i);
//                     }
//                 }
//             }
//         }
//         if(flg){
//             return mp(lsum,larr);
//         }
//         else return mp(-1,vi());
//         v[ci]=-1;
//     }
// }

// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
    
//     int t;
//     cin >> t;
//     FOR(i,0,t){
//         int n, e;
//         cin >> n >> e;
        
//         map<int,vi> cm;
//         FOR(j,0,e){
//             int j1, j2;
//             cin >> j1 >> j2;
//             cm[j1].pb(j2);
//             cm[j2].pb(j1);
//         }

//         vi v(n+1,-1);

//     }

//     return 0;
// }

// // read the question correctly (ll vs int)
// // template by bqi343