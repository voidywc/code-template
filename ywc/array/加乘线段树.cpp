#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
typedef pair<int, int> pii;
const int maxn = 2e5 + 5, mod = 998244353, maxp = 65, inf = 1e9;
const ll INF = 1e18;

ll a[maxn];

ll p;

struct SegmentTree {
	ll val, add, mul;
}tree[maxn << 2];

void calc(ll l, ll r, ll rt, ll add, ll mul) {
	tree[rt].val = (tree[rt].val * mul + (r - l + 1) * add) % p;
	tree[rt].mul = tree[rt].mul * mul % p;
	tree[rt].add = (tree[rt].add * mul + add) % p;
}

void pushup(ll rt) {
	tree[rt].val = (tree[rt << 1].val + tree[rt << 1 | 1].val) % p;
}

void pushdown(ll l, ll r, ll rt) {
	if (tree[rt].add == 0 && tree[rt].mul == 1) return;
	ll add = tree[rt].add;
	ll mul = tree[rt].mul;
	ll mid = l + r >> 1;
	calc(l, mid, rt << 1, add, mul);
	calc(mid + 1, r, rt << 1 | 1, add, mul);
	tree[rt].add = 0;
	tree[rt].mul = 1;
}

void build(ll l, ll r, ll rt) {
	tree[rt].add = 0;
	tree[rt].mul = 1;
	if (l == r) {
		tree[rt].val = a[l];
		return;
	}
	ll mid = l + r >> 1;
	build(l, mid, rt << 1);
	build(mid + 1, r, rt << 1 | 1);
	pushup(rt);
}

void update(ll L, ll R, ll C, ll M, ll l, ll r, ll rt) {
	if (L <= l && R >= r) {
		calc(l, r, rt, C, M);
		return;
	}
	ll mid = l + r >> 1;
	pushdown(l, r, rt);
	if (L <= mid) update(L, R, C, M, l, mid, rt << 1);
	if (R > mid) update(L, R, C, M, mid + 1, r, rt << 1 | 1);
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
	return (query(L, R, l, mid, rt << 1) + query(L, R, mid + 1, r, rt << 1 | 1)) % p;
}

void solve() {
	int n, q;
	cin >> n >> q >> p;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	build(1, n, 1);
	while (q--) {
		int f;
		cin >> f;
		if (f == 1) {
			ll l, r, M;
			cin >> l >> r >> M;
			update(l, r, 0, M, 1, n, 1);
		}
		else if (f == 2) {
			ll l, r, C;
			cin >> l >> r >> C;
			update(l, r, C, 1, 1, n, 1);
		}
		else {
			ll l, r;
			cin >> l >> r;
			cout << query(l, r, 1, n, 1) << endl;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tt = 1;
/*	cin >> tt;*/
	while (tt--) solve();
	return 0;
}