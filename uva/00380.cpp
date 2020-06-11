#pragma GCC optimize("O3")
#pragma GCC target("sse4")

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

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;

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

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = b; i > a; i--)
#define F0Rd(i, a) for (int i = a; i > -1; i--)

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
#define ex(m, i) m.find(i) != m.end()
#define nex(m, i) m.find(i) == m.end()

#define uniq(x) x.resize(unique(all(x)) - x.begin())

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy
const vvi ds = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}};

int dfs(map<int,vector<pa<pa<int,int>,int>>>& cm, int s, int& time, set<int>& vs){

    if(ex(vs,s)){
        return 9999;
    }
    if(ex(cm,s)){
        vs.ins(s);
        for(auto i : cm[s]){
            if(i.f.f <= time && i.f.s >= time) {
                return dfs(cm,i.s,time,vs);
            }
        }
        return s;
    }
    
    return s;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    printf("CALL FORWARDING OUTPUT\n");
    int t;
    cin>>t;
    FOR(i,0,t){
        printf("SYSTEM %d\n",i+1);
        string from;
        // from, start, end, target
        map<int,vector<pa<pa<int,int>,int>>> cm;
        while(cin >> from && from != "0000"){
            int time;
            int duration;
            int forward;
            cin >> time >> duration >> forward;
            cm[stoi(from)].pb(mp(mp(time,time+duration),forward));
        }

        string time;
        while(cin >> time && time != "9000"){
            int query;
            cin >> query;

            set<int> cache;
            int vtime = stoi(time);
            int ret = dfs(cm,query,vtime,cache);
            printf("AT %04d CALL TO %04d RINGS %04d\n",stoi(time),query,ret);
        }

    }

    printf("END OF OUTPUT\n");

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343