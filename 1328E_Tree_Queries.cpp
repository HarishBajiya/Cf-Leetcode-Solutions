// DeNsE - EcLiPsE //
// WHAT is DEAD may NEVER die //

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>
#include <cmath>
#include <iomanip>
#include <set>
#include <cstring>
#include <stack>
#include <sstream>
#include <queue>
#include <unordered_set>
#include <cstdlib>

using namespace std;

#define nitro ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long
#define double long double
#define endl "\n"

const int inf = 1e17;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
const int H = 35;
const double pi = 3.14159265358979323846;
const double eps = 1e-7;

int     di []    =  {-1 , 0 , 1 , 0 ,-1,-1, 1,  1};
int     dj []    =  { 0 , 1 , 0 ,-1 ,-1, 1, 1, -1};
char    dir[]    =  {'U','R','D','L'};


int bPow(int a, int b){
    if(b < 0){
        return 0;
    }
    int res = 1;
    while(b) {
        if (b & 1) {
            res = (res * a) % mod;
        }
        b >>= 1;
        a = (a * a) % mod;
    }
    return res % mod;
}

int gcd(int a, int b){
    if(a < b)
        swap(a, b);
    if (b == 0)
        return a;
    return gcd(b, a % b);

}

int lcm(int a, int b){
    return (a * b) / gcd(a, b);
}

vector<int> fact(N, 0ll);
void factorial(){
    fact[0] = 1, fact[1] = 1;
    for(int i = 2; i < N; i++){
        fact[i] = (fact[i - 1] * i) % mod;
    }
}

int ncr(int n, int r){
    if(r > n)
        return 0;
    int ans = fact[n] % mod;
    ans *= bPow(fact[r], mod - 2) % mod;
    ans %= mod;
    ans *= bPow(fact[n - r], mod - 2) % mod;
    ans %= mod;
    return ans;
}

vector<int> primes(N, -1);

void sieve(){
    iota(primes.begin(), primes.end(), 0);
    for (int i = 2; i < N; ++i) {
        if(primes[i] == i){
            for (int j = i; j < N; j += i) {
                primes[j] = i;
            }
        }
    }
}

int add(int a, int b){
    a %= mod, b %= mod;
    return ((a + b) % mod + mod) % mod;
}
int mul(int a, int b){
    a %= mod, b %= mod;
    return ((a * b) % mod + mod) % mod;
}
int sub(int a, int b){
    a %= mod, b %= mod;
    return ((a - b + 2 * mod) % mod + mod) % mod;
}

int t = 0;
vector<vector<int>> adj;
vector<int> par, tin, tout, dep;

void dfs(int u, int p, int d){
    par[u] = p, tin[u] = t++, dep[u] = d;
    for(int v : adj[u]){
        if(v == p){
            continue;
        }
        dfs(v, u, d + 1);
    }
    tout[u] = t++;
}

bool isAnc(int v, int u){
    return tin[v] <= tin[u] and tout[v] >= tout[u];
}

void solve() {
    int n, q;
    cin >> n >> q;
    adj = vector<vector<int>> (n + 1);
    par = vector<int> (n + 1, -1);
    dep = vector<int> (n + 1, 0);
    tin = vector<int> (n + 1, 0);
    tout = vector<int> (n + 1, 0);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1, 0);
    while (q--){
        int m;
        cin >> m;
        vector<int> a(m);
        for (int i = 0; i < m; ++i) {
            cin >> a[i];
        }
        int vl = a.front();
        for(int v : a){
            if(dep[vl] < dep[v]){
                vl = v;
            }
        }
        for(int& v : a){
            if(vl == v){
                continue;
            }
            if(par[v] != -1){
                v = par[v];
            }
        }
        bool ok = true;
        for(int v : a){
            if(!isAnc(v, vl)){
                ok = false;
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
}

signed main(){
    /*#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "wb", stdout);
    #endif*/
    nitro;
    int tc = 1, test = 1;
    //cin >> tc;
    while(tc--){
        //cout << "Case #" << test++ << ": ";
        solve();
    }
}


 
