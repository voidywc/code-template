#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define X first
#define Y second
#define umap unordered_map
using ll = long long;
typedef pair<int, int> pii;
const int maxn = 5e5 + 5, mod = 998244353, maxp = 25, inf = 1e9;
const ll INF = 1e18;

vector<int> E[maxn];

int fath[maxn], dep[maxn], son[maxn], sz[maxn];
int top[maxn];

ll a[maxn], b[maxn];
int idx[maxn], oidx[maxn];

int cnt = 0;

int n;

struct SegmentTree {
	ll val, lazy;
}tree[maxn << 2];

void dfs1(int u, int fa) {
	son[u] = 0;
	sz[u] = 1;
	for (auto v : E[u]) {
		if (v == fa) continue;
		fath[v] = u;
		dep[v] = dep[u] + 1;
		dfs1(v, u);
		sz[u] += sz[v];
		if (sz[son[u]] < sz[v]) {
			son[u] = v;
		}
	}
}

void dfs2(int u, int topx) {
	idx[u] = ++cnt;//新的标号
	oidx[cnt] = u;
	a[cnt] = b[u];//权值转移
	top[u] = topx;
	if (!son[u]) return;
	dfs2(son[u], topx);
	for (auto v : E[u]) {
		if (v == fath[u]) continue;
		if (v == son[u]) continue;
		// if (cnt[v]) continue;
		dfs2(v, v);
	}
}

void pushup(ll rt) {
	tree[rt].val = tree[rt << 1].val + tree[rt << 1 | 1].val;
}

void pushdown(ll l, ll r, ll rt) {
	if (tree[rt].lazy == 0) return;
	ll lazy = tree[rt].lazy;
	tree[rt].lazy = 0;
	ll mid = l + r >> 1;
	tree[rt << 1].lazy += lazy;
	tree[rt << 1 | 1].lazy += lazy;
	tree[rt << 1].val += lazy * (mid - l + 1);
	tree[rt << 1 | 1].val += lazy * (r - mid);
}

void build(ll l, ll r, ll rt) {
	tree[rt].lazy = 0;
	if (l == r) {
		tree[rt].val = a[l];
		return;
	}
	ll mid = l + r >> 1;
	build(l, mid, rt << 1);
	build(mid + 1, r, rt << 1 | 1);
	pushup(rt);
}

void update(ll L, ll R, ll C, ll l, ll r, ll rt) {
	if (L <= l && R >= r) {
		tree[rt].lazy += C;
		tree[rt].val += (r - l + 1) * C;
		return;
	}
	ll mid = l + r >> 1;
	pushdown(l, r, rt);
	if (L <= mid) update(L, R, C, l, mid, rt << 1);
	if (R > mid) update(L, R, C, mid + 1, r, rt << 1 | 1);
	pushup(rt);
}

ll query(ll L, ll R, ll l, ll r, ll rt) {
	if (L <= l && R >= r) {
		return tree[rt].val;
	}
	if (l > R || L > r) {
		return 0;
	}
	ll mid = l + r >> 1;
	pushdown(l, r, rt);
	return query(L, R, l, mid, rt << 1) + query(L, R, mid + 1, r, rt << 1 | 1);
}


ll treesum(int x, int y) {//求x到y路径上的和
	ll ans = 0;
	while (top[x] != top[y]) {//不在同一条链上
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		ans += query(idx[top[x]], idx[x], 1, n, 1);//求一整条链上的和
		x = fath[top[x]];
	}
	//现在在同一条链上了, 而且编号是连续的, 直接求区间和
	if (dep[x] > dep[y]) swap(x, y);
	ans += query(idx[x], idx[y], 1, n, 1);
	return ans;
}

void treeadd(int x, int y, ll C) {//x到y路径上统一加x
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		update(idx[top[x]], idx[x], C, 1, n, 1);
		x = fath[top[x]];
	}
	if (dep[x] > dep[y]) swap(x, y);
	update(idx[x], idx[y], C, 1, n, 1);
}

void solve() {
	int q, rt, p;
	cin >> n >> q >> rt >> p;
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	fath[rt] = rt;
	dfs1(rt, -1);
	dfs2(rt, rt);
	build(1, n, 1);
	//对一棵树的子树进行操作时, 区间为[idx[x], idx[x] + sz[x] - 1], 因为某个点与他的儿子节点的

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