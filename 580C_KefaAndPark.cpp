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
//#include <bits/stdc++.h>

using namespace std;

#define nitro ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define ld long double
#define ull unsigned long long
#define charToInt(c) (c-'0')

const ll inf = (1ll << 62) - 1;
const ll MOD = 1e9 + 7;
const int MAX = 2 * 1e9 + 10;
const int N = 2e5 + 5;

using namespace std;

int bPow(int a, int b){
    int res = 1;
    while(b) {
        if (b & 1ll) {
            res = 1ll * res * a % MOD;
        }
        b >>= 1;
        a = 1ll * a * a % MOD;
    }
    return res;
}

int gcd(int a, int b)
{
    if(a < b){
        swap(a, b);
    }
    if (b == 0)
        return a;
    return gcd(b, a % b);

}

vector<int> mpf(N, 0);
void sieve(){
    for (int i = 2; i < N; ++i) {
        if(!mpf[i])
        for (int j = 2 * i; j < N; j += i) {
            mpf[j] = i;
        }
    }
}

int n, m;
vector<vector<int>> adj(N);
vector<bool> vis(N, false);
vector<int > leaves;
set<int> catsPos;

void dfs(int u, int maxCats, int cur){
    if(catsPos.find(u) != catsPos.end()){
        cur++;
        maxCats = max(maxCats, cur);
    }else{
        cur = 0;
    }
    vis[u] = true;
    if(adj[u].size() == 1 and u != 1){
        leaves.push_back(maxCats);
        return;
    }
    for(int i : adj[u]){
        if(!vis[i]){
            dfs(i, maxCats, cur);
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        if(x == 1)
            catsPos.insert(i + 1);
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0, 0);
    int ans = 0;
    for (int i = 0; i < leaves.size(); ++i) {
        if(leaves[i] <= m){
            ans++;
        }
    }
    cout << ans;
}

int main(){
    nitro;
    int tc = 1;
    //cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}
