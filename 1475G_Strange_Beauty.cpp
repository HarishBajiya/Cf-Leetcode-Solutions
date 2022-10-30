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
//#define endl " \n"

const int inf = (1ll << 62) - 1;
const int mod = 1e9 + 7;
const int N = 2e5 + 2;
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

vector<int> primes(N, -1);;
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


void solve() {
    int n;
    cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int taken = 0;
    vector<int> dp(N, 0);
    for (int i = N - 1; i > 0; --i) {
        dp[i] = cnt[i];
        for (int j = 2; i * j < N; ++j) {
            dp[i] = max(dp[i], cnt[i] + dp[i * j]);
        }
        taken = max(taken, dp[i]);
    }
    cout << n - taken << endl;
}

signed main(){
    nitro
    int tc = 1, test = 1;
    cin >> tc;
    while(tc--){
        //cout << "Case #" << test << ": ";
        solve();
        test++;
    }
}
