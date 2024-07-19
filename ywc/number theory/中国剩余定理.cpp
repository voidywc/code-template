#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define X first
#define Y second
#define umap unordered_map
using ll = long long;
typedef pair<int, int> pii;
const int maxn = 2e5 + 5, mod = 1e9 + 7, maxp = 65, inf = 1e9;

int a[10], m[10];

int n;

ll extend_gcd(int a, int b, int& x, int& y) {//返回的是a, b的最大公约数, xy是方程ax + by = __gcd(a, b)的解
	if (b == 0) {
		x = 1, y = 0;
		return a;
	}
	ll d = extend_gcd(b, a % b, x, y);
	ll tmp = x;
	x = y;
	y = tmp - a / b * y;
	return d;
}

int extend_Crt() {
	int x = a[1];
	int M = m[1];
	for (int i = 2; i <= n; i++) {
		int Mi = m[i];
		int c = a[i] - x;
		int t, y;
		int d = extend_gcd(M, m[i], t, y);
		if (c % d) {
			return -1;
		}
		Mi /= d, c /= d;
		t = (t * c % Mi + Mi) % Mi;
		x = (M * t % (M * Mi) + x) % (M * Mi);
		M = M * Mi;
	}
	return x == 0 ? M : x;
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