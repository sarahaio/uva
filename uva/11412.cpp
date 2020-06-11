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
const vvi ds = {
    {-1,0},
    {1,0},
    {0,-1},
    {0,1}
};
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int t;
    cin >> t;
    FOR(u,0,t){

        char cm[6] = {'R', 'G', 'B', 'Y', 'O', 'V'};

        string s1;
        int n11, n12;
        cin >> s1 >> n11 >> n12;
        string s2;
        int n21, n22;
        cin >> s2 >> n21 >> n22;
        bool valid = false;
        
        vi src(6,0);
        vi tar1(6,0);
        vi tar2(6,0);
        FOR(j,0,4){
            FOR(k,0,6){
                if(cm[k]==s1[j]){
                    tar1[k]++;
                    break;
                }
            }
        }
        FOR(j,0,4){
            FOR(k,0,6){
                if(cm[k]==s2[j]){
                    tar2[k]++;
                    break;
                }
            }
        }
        bool found = false;

        int match1 = 0;
        int match2 = 0;
        FOR(i1,0,6){
            src[i1]++;
            if(s1[0]==cm[i1]){
                match1++;
            }
            if(s2[0]==cm[i1]){
                match2++;
            }
            FOR(i2,0,6){
                if(i1==i2) continue;
                src[i2]++;
                if(s1[1]==cm[i2]){
                    match1++;
                }
                if(s2[1]==cm[i2]){
                    match2++;
                }
                FOR(i3,0,6){
                    if(i3==i1||i3==i2) continue;
                    src[i3]++;
                    if(s1[2]==cm[i3]){
                        match1++;
                    }
                    if(s2[2]==cm[i3]){
                        match2++;
                    }
                    FOR(i4,0,6){
                        if(i4==i3||i4==i2||i4==i1) continue;
                        src[i4]++;
                        if(s1[3]==cm[i4]){
                            match1++;
                        }
                        if(s2[3]==cm[i4]){
                            match2++;
                        }
                        
                        int si1 = 0;
                        int si2 = 0;
                        FOR(j,0,6){
                            si1 += min(src[j],tar1[j]);
                            si2 += min(src[j],tar2[j]);
                        }

                        si1 -= match1;
                        si2 -= match2;

                        // if(i1==4&&i2==0&&i3==5&&i4==3){
                        //     for(auto m : src){
                        //         cout<<m<<" ";
                        //     }
                        //     cout<<endl;

                        //     for(auto m : tar1){
                        //         cout<<m<<" ";
                        //     }
                        //     cout<<endl;

                        //     for(auto m : tar2){
                        //         cout<<m<<" ";
                        //     }
                        //     cout<<endl;

                        //     cout<<si1<<" "<<si2<<" "<<match1<<" "<<match2;
                        // }

                        if(match1==n11&&si1==n12&&match2==n21&&si2==n22){
                            found=true;
                            break;
                        }

                        src[i4]--;
                        if(s1[3]==cm[i4]){
                            match1--;
                        }
                        if(s2[3]==cm[i4]){
                            match2--;
                        }
                    }
                    if(found) break;
                    src[i3]--;
                    if(s1[2]==cm[i3]){
                        match1--;
                    }
                    if(s2[2]==cm[i3]){
                        match2--;
                    }
                }
                if(found) break;
                src[i2]--;
                if(s1[1]==cm[i2]){
                    match1--;
                }
                if(s2[1]==cm[i2]){
                    match2--;
                }
            }
            if(found) break;
            src[i1]--;
            if(s1[0]==cm[i1]){
                match1--;
            }
            if(s2[0]==cm[i1]){
                match2--;
            }
        }

        if(found) printf("Possible\n");
        else printf("Cheat\n");

    }
    
    return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343