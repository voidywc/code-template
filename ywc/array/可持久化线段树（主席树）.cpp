#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define X first
#define Y second
#define umap unordered_map
using ll = long long;
using ull = unsigned long long;
typedef pair<int, int> pii;
const int maxn = 2e5 + 5, mod = 998244353, maxp = 25, inf = 1e9;
const ll INF = 1e18;
const double eps = 1e-6;

int a[maxn];

int ls[maxn * 22], rs[maxn * 22], cnt[maxn * 22];

int rt[maxn * 22];

int idx;

vector<int> v;

void build(int &x, int l, int r) {
	x = ++idx;
	if (l == r) return;
	int mid = l + r >> 1;
	build(ls[x], l, mid);
	build(rs[x], mid + 1, r);
}

//表示在值域[l, r]之间插入一个数C
void insert(int x, int &y, int l, int r, int C) {//insert(rt[i - 1], rt[i], 1, n, a[i])
	y = ++idx;
	cnt[y] = cnt[x] + 1;
	ls[y] = ls[x];
	rs[y] = rs[x];
	if (l == r) return;
	int mid = l + r >> 1;
	if (C <= mid) insert(ls[x], ls[y], l, mid, C);
	else insert(rs[x], rs[y], mid + 1, r, C);
}

//前缀和思想
int query(int x, int y, int l, int r, int k) {//查询[L, R]之间第k小 query(rt[l - 1], rt[r], 1, n, k)
	if (l == r) return l;
	int mid = l + r >> 1;
	int ct = cnt[ls[y]] - cnt[ls[x]];
	if (k <= ct) return query(ls[x], ls[y], l, mid, k);
	return query(rs[x], rs[y], mid + 1, r, k - ct);
}//注意有离散化, 所以返回的v数组的下标

int get_id(int x) {
	int res = lower_bound(v.begin(), v.end(), x) - v.begin();
	return res;
}

void solve() {
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	auto init = [&]() -> void {
		v.clear();
		idx = 0;
		for (int i = 1; i <= n; i++) {
			v.push_back(a[i]);
		}
		v.push_back(-inf);
		sort(v.begin(), v.end());
		for (int i = 1; i <= n; i++) {
			insert(rt[i - 1], rt[i], 1, n, get_id(a[i]));
		}
	};
	init();
	while (q--) {
		int l, r, k;
		cin >> l >> r >> k;
		int idx = query(rt[l - 1], rt[r], 1, n, k);
		cout << v[idx] << endl;
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