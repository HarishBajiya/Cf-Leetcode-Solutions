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
#define endl " \n"

const int inf = (1ll << 62) - 1;
const int mod = 1e9 + 7;
const int N = 2003;
const double pi = 3.14159265358979323846;

int bPow(int a, int b){
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

int gcd(int a, int b)
{
    if(a < b)
        swap(a, b);
    if (b == 0)
        return a;
    return gcd(b, a % b);

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
    for (int i = 2; i * i <= N; ++i) {
        if(primes[i] == i){
            for (int j = 2 * i; j < N; j += i) {
                primes[j] = i;
            }
        }
    }
}

void bfs(int u, int v, vector<int>& dist, vector<set<int>> g){
    dist[u] = 0;
    queue<int> q;
    q.push(u);
    while (!q.empty() and q.front() != v){
        int node = q.front();
        q.pop();
        for (auto i : g[node]) {
            if(dist[i] == -1){
                dist[i] = dist[node] + 1;
                q.push(i);
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> setBits(64, 0);
    vector<int> b;
    int maxCount = 0;
    for (int i = 0; i < n; ++i) {
        int cur = a[i];
        for (int j = 0; j < 64; ++j) {
            if((cur >> j) & 1){
                setBits[j]++;
            }
            maxCount = max(maxCount, setBits[j]);
        }
        if(a[i])
            b.push_back(cur);
    }
    if(maxCount > 2){
        cout << 3 << endl;
        return;
    }
    int m = b.size();
    vector<set<int>> graph(204);
    vector<pair<int, int>> pairs;
    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            if(b[i] & b[j]){
                graph[i].insert(j);
                graph[j].insert(i);
                pairs.emplace_back(i, j);
            }
        }
    }
    int ans = inf;
    for (auto & pair : pairs) {
        vector<int> dist(204, -1);
        int x = pair.first, y = pair.second;
        graph[x].erase(y), graph[y].erase(x);
        bfs(x, y, dist, graph);
        if(dist[y] != -1){
            ans = min(ans, dist[y] + 1);
        }
        graph[x].insert(y), graph[y].insert(x);
    }
    cout << (ans == inf ? -1 : ans) << endl;
}


signed main(){
    nitro
    int tc = 1, test = 1;
    //cin >> tc;
    while(tc--){
        //cout << "Case #" << test++ << ": ";
        solve();
    }
}
