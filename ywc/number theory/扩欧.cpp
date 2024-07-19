#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
typedef pair<int, int> pii;
const int maxn = 2e5 + 5, mod = 1e9 + 7, maxp = 65, inf = 1e9;
const ll INF = 1e18;

ll extend_gcd(ll a, ll b, ll &x, ll &y) {//返回的是a, b的最大公约数, xy是方程ax + by = __gcd(a, b)的解
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