#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define X first
#define Y second
#define umap unordered_map
using ll = long long;
typedef pair<int, int> pii;
const int maxn = 3e5 + 5, mod = 1e9 + 7, maxp = 65, inf = 1e9;
const ll INF = 1e18;

int n = 4;//矩阵大小

struct matrix {
	ll t[15][15];
};

matrix mul(matrix u, matrix v) {
	matrix res;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			res.t[i][j] = 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				res.t[i][j] += u.t[i][k] * v.t[k][j];
				res.t[i][j] %= mod;
			}
		}
	}
	return res;
}

matrix m_fastpow(matrix A, int k) {
	matrix res;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) res.t[i][j] = 1;
			else res.t[i][j] = 0;
		}
	}
	while (k) {
		if (k & 1) {
			res = mul(res, A);
		}
		A = mul(A, A);
		k >>= 1;
	}
	return res;
}

matrix u;//递推矩阵

void init() {//初始化递推矩阵

}

ll fk[] = {};//第一项各个系数

void solve() {

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	init();
	int tt = 1;
	cin >> tt;
	while (tt--) solve();
	return 0;
}