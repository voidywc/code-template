#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define X first
#define Y second
#define umap unordered_map
using ll = long long;
typedef pair<int, int> pii;
const int maxn = 2e5 + 5, mod = 998244353, maxp = 25, inf = 1e9;
const ll INF = 1e18;

bool isprime[maxn];
int prime[maxn];//从1开始
int cnt;

int phi[maxn];

void eulur(int x) {
	phi[1] = 1;
	for (int i = 2; i <= x; i++) isprime[i] = 1;
	for (int i = 2; i <= x; i++) {
		if (isprime[i]) prime[++cnt] = i, phi[i] = i - 1;
		for (int j = 1; j <= cnt && i * prime[j] <= x; j++) {
			isprime[i * prime[j]] = 0;
			if (i % prime[j] == 0) {
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			}
			else {
				phi[i * prime[j]] = phi[i] * (prime[j] - 1);
			}
		} 
	}
}

ll get_phi(ll x) {
	ll res = x;
	for (int i = 2; i * i <= x; i++) {
		if (x % i) continue;
		res -= res / i;
		while (x % i == 0) x /= i;
	}
	if (x > 1) res -= res / x;
	return res;
}

void solve() {

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tt = 1;
	cin >> tt;
	while (tt--) solve();
	return 0;
}