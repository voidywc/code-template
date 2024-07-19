#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
#define ll long long
typedef pair<int, int> pii;
const int maxn = 2e5 + 5, mod = 1e9 + 7, maxp = 65, inf = 1e9;
const ll INF = 1e18;

int f[maxn][26], g[maxn][26];

int n;

int a[maxn];

void init() {
	for (int i = 1; i <= n; i++) {
		f[i][0] = a[i];
	}
	for (int j = 1; j <= 25; j++) {
		for (int i = 1; i + (1 << j) - 1 <= n; i++) {
			f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
		}
	}
	for (int i = 1; i <= n; i++) {
		g[i][0] = a[i];
	}
	for (int j = 1; j <= 25; j++) {
		for (int i = 1; i + (1 << j) - 1 <= n; i++) {
			g[i][j] = min(g[i][j - 1], g[i + (1 << (j - 1))][j - 1]);
		}
	}
}

int query1(int l, int r) {
	int k = log2(r - l + 1);
	return max(f[l][k], f[r - (1 << k) + 1][k]);
}

int query2(int l, int r) {
	int k = log2(r - l + 1);
	return min(g[l][k], g[r - (1 << k) + 1][k]);
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tt = 1;
//	cin >> tt;
	while (tt--) solve();
	return 0;
}