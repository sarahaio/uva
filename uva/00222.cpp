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

const double epsilon = 1e-9;

void dfs(vector<pa<double,double>>& cm, int ci, double cost, double gas, double distance, double& capacity, double& milesgallion, double& cmin){

    if(ci==sz(cm)) {
        cmin = min(cmin,cost);
        return;
    }

    double rgas = gas - (cm[ci].f - distance) / milesgallion;

    if((ci != sz(cm) - 1) && rgas < (cm[ci+1].f - cm[ci].f) / milesgallion){
        double ncost = (capacity - rgas) * cm[ci].s / 100;
        dfs(cm,ci+1,cost + ncost + 2, capacity, cm[ci].f, capacity,milesgallion,cmin);
    }
    else if(rgas > capacity / 2){

        dfs(cm,ci+1,cost,rgas, cm[ci].f,capacity,milesgallion,cmin);

    }
    else{
        dfs(cm,ci+1,cost,rgas, cm[ci].f,capacity,milesgallion,cmin);

        double ncost = (capacity - rgas) * cm[ci].s / 100;
        dfs(cm,ci+1,cost + ncost + 2, capacity, cm[ci].f, capacity,milesgallion,cmin);
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    double distance;
    int k = 1;
    while(cin >> distance && abs(distance+1) > epsilon){
        double capacity;
        double miles;
        double prices;
        int gas;
        cin >> capacity >> miles >> prices >> gas;
        vector<pa<double,double>> cm;
        FOR(i,0,gas){
            double d1;
            double p1;
            cin >> d1 >> p1;
            cm.pb(mp(d1,p1));
        }
        cm.pb(mp(distance,0));

        double initcost = prices;

        double cmin = numeric_limits<double>::max();
        dfs(cm,0,initcost,capacity,0,capacity,miles,cmin);

        printf("Data Set #%d\n",k);
        printf("minimum cost = $%.2lf\n",cmin);

        k++;
    }


    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343