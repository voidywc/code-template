#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define X first
#define Y second
#define umap unordered_map
using ll = long long;
typedef pair<int, int> pii;
const int maxn = 3e5 + 5, mod = 998244353, maxp = 65, inf = 1e9;
const ll INF = 1e18;

vector<int> E[maxn], rE[maxn];

stack<int> stk;

bool vis[maxn];

int f[maxn];//保存强连通分量的序号

void rdfs(int u) {
	vis[u] = 1;
	for (auto v : rE[u]) {
		if (vis[v]) continue;
		rdfs(v);
	}
	stk.push(u);
}

void dfs(int u, int idx) {
	vis[u] = 0;
	f[u] = idx;
	for (auto v : E[u]) {
		if (!vis[v]) continue;
		dfs(v, idx);
	}
}

vector<int> G[maxn];//缩点

void solve() {
	int n, m;
	cin >> n >> m;
	while (stk.size()) stk.pop();
	for (int i = 1; i <= n * 2; i++) {
		E[i].clear();
		rE[i].clear();
		G[i].clear();
		vis[i] = 0;
	}
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		E[u].push_back(v);
	}
	for (int u = 1; u <= n; u++) {
		for (auto v : E[u]) {
			rE[v].push_back(u);
		}
	}
	for (int i = 1; i <= n * 2; i++) {
		if (vis[i]) continue;
		rdfs(i);
	}
	while (stk.size()) {
		int u = stk.top();
		stk.pop();
		if (!vis[u]) continue;
		dfs(u, u);
	}

	//缩点建边
	for (int u = 1; u <= n; u++) {
		for (auto v : E[u]) {
			if (f[u] == f[v]) continue;
			G[f[u]].push_back(f[v]);
		}
	}

	
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tt = 1;
	// cin >> tt;
	while (tt--) solve();
	return 0;
}