#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define X first
#define Y second
#define umap unordered_map
using ll = long long;
typedef pair<int, int> pii;
const int maxn = 3e5 + 5, mod = 1e9 + 7, maxp = 65, inf = 1e9;

ll fac[maxn], facc[maxn], inv[maxn];

void init() {
    int n = maxn - 5;
    int p = mod;
    fac[0] = facc[0] = inv[1] = 1;
    for (int i = 2; i <= n; i++) {
        inv[i] = (p - p / i) * inv[p % i] % p;
    }
    for (int i = 1; i <= n; i++) {
        fac[i] = fac[i - 1] * i % p;
        facc[i] = facc[i - 1] * inv[i] % p;
    }
}

ll C(ll n, ll m) {
    if (n < m) return 0;
    if (n < 0 || m < 0) return 0;
    return fac[n] * facc[m] % mod * facc[n - m] % mod;
}

void solve() {
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tt = 1;
	cin >> tt;
	init();
	while (tt--) solve();
	return 0;
}