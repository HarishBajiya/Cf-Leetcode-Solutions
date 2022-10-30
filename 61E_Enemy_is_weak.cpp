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
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

using namespace std;

#define nitro ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//#define int long long
#define double long double
#define endl "\n"

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

int solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> left(n, 0), right(n, 0);
    ordered_set osLeft;
    osLeft.insert(a[0]);
    for(int i = 1; i < n; i++){
        int more = osLeft.size() - osLeft.order_of_key(a[i]);
        left[i] = more;
        osLeft.insert(a[i]);
    }
    ordered_set osRight;
    osRight.insert(a[n - 1]);
    for(int i = n - 2; i >= 0; i--){
        int more = osRight.order_of_key(a[i]);
        right[i] = more;
        osRight.insert(a[i]);
    }
    long long int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += (long long) left[i] * right[i];
    }
    cout << ans << endl;
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


 
