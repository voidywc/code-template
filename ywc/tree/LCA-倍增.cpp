#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define X first
#define Y second
#define umap unordered_map
using ll = long long;
typedef pair<int, int> pii;
const int maxn = 2e5 + 5, mod = 1e9 + 7, maxp = 25, inf = 1e9;
const ll INF = 1e18;

vector<int> E[maxn];


int dep[maxn];

int f[maxn][maxp];

void dfs0(int u) {
	for (int i = 1; i < maxp; i++) f[u][i] = f[f[u][i - 1]][i - 1];
	for (auto v : E[u]) {
		if (f[u][0] == v) continue;
		dep[v] = dep[u] + 1;
		f[v][0] = u;
		dfs0(v);
	}
}

int lca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	for (int t = dep[x] - dep[y], i = maxp - 1; i >= 0; i--) {
		if (t >> i & 1) x = f[x][i];
	}
	if (x == y) return x;
	for (int i = maxp - 1; i >= 0; i--) {
		if (f[x][i] == f[y][i]) continue;
		x = f[x][i], y = f[y][i];
	}
	return f[x][0];
}

void solve() {
	int n, q, rt;
	cin >> n >> q >> rt;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	dep[rt] = 0;
	f[rt][0] = rt;
	dfs0(rt);
	while (q--) {
		int u, v;
		cin >> u >> v;
		cout << lca(u, v) << endl;
	}
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