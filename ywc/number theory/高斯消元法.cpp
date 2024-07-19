#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define X first
#define Y second
#define umap unordered_map
using ll = long long;
typedef pair<int, int> pii;
const int maxn = 2e5 + 5, mod = 1e9 + 7, maxp = 65, inf = 1e9;
const ll INF = 1e18;
const double eps = 1e-6;

double a[105][105];

int n, m;

int gauss() {
	int r = 0;
	for (int c = 0; c < m; c++) {
		int t = r;
		for (int i = r; i < n; i++) {
			if (fabs(a[i][c]) > fabs(a[t][c])) {
				t = i;
			}
		}
		if (fabs(a[t][c]) < eps) continue;
		for (int j = c; j <= m; j++) {
			swap(a[t][j], a[r][j]);
		}
		for (int j = m; j >= c; j--) {
			a[r][j] /= a[r][c];
		}
		for (int i = r + 1; i < n; i++) {
			if (fabs(a[i][c]) < eps) continue;
			for (int j = m; j >= c; j--) {
				a[i][j] -= a[r][j] * a[i][c];
			}
		}
		r++;
	}
	for (int i = r; i < n; i++) {
		if (fabs(a[i][m] > eps)) {
			return 2;//0 = 1, 无解
		}
	}
	if (r < m) {
		return 1;//有效方程个数r < m, 无数解
	}
	for (int i = m - 1; i >= 0; i--) {
		for (int j = i + 1; j < m; j++) {
			a[i][m] -= a[i][j] * a[j][m];
		}
	}
	return 0;//唯一解
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