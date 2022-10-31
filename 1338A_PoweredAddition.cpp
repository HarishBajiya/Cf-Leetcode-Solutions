//
// CODED by HARRY on 26/10/2020
//

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
//#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define charToInt(c) (c-'0')

const ll int inf = 2e5 + 1;
const ll int MOD = 1e9 + 7;
const int MAX = 505;

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll maxi = 0;
    for (int i = 1; i < n; ++i) {
        if(a[i] < a[i - 1]){
            maxi = max(maxi, a[i - 1] - a[i]);
            a[i] = a[i - 1];
        }
    }
    cout << (int)ceil(log2(maxi + 1)) << endl;
}

int main(){
    int tc;
    cin >> tc;
    while(tc--)
        solve();
    //solve();
    return 0;
}
