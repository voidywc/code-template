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

vector<int> E[maxn];

int sz[maxn], fath[maxn], son[maxn], dep[maxn];
int top[maxn];

void dfs1(int u, int fa) {
	sz[u] = 1;
	son[u] = 0;
	for (auto v : E[u]) {
		if (v == fa) continue;
		dep[v] = dep[u] + 1;
		fath[v] = u;
		dfs1(v, u);
		if (sz[v] > sz[son[u]]) {
			son[u] = v;
		}
		sz[u] += sz[v];
	}
}

void dfs2(int u, int topx) {//先遍历重儿子, 再遍历轻儿子, 轻儿子由重儿子传递
	top[u] = topx;
	if (!son[u]) return;//son[u] == 0的点一定为叶子节点, 没有儿子, 就不用继续dfs2了
	dfs2(son[u], topx);//再往下遍历重儿子
	for (auto v : E[u]) {
		if (v == fath[u]) continue;
		if (v == son[u]) continue;
		dfs2(v, v); 
	}
}

int lca(int x, int y) {
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);//让top[x]深度更深的往上跳, 只有这样才能再
		x = fath[top[x]];//跳到链的顶点的父亲节点, 到了一个新的重链上(除根节点以外)
	}
	return dep[x] < dep[y] ? x : y;
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
	fath[rt] = rt;
	dfs1(rt, -1);
	dfs2(rt, rt);
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
	// cin >> tt;
	while (tt--) solve();
	return 0;
}