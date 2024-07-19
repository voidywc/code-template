#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int maxn = 1e5 + 5, mod = 998244353, maxp = 65, inf = 1e9;
const ll INF = 1e18;

ll a[maxn];

struct SegmentTree {
	ll val, lazy;
}tree[maxn << 2];

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