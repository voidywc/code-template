#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
typedef pair<int, int> pii;
const int maxn = 2e5 + 5, mod = 1e9 + 7, maxp = 65, inf = 1e9;
const ll INF = 1e18;

vector<int> manacher(string s) {
	string t = "#";
	for (auto c : s) {
		t += c;
		t += '#';
	}
	int n = t.size();
	vector<int> r(n);
	for (int i = 0, j = 0; i < n; i++) {
		if (2 * j - i >= 0 && j + r[j] > i) {
			r[i] = min(r[2 * j - i], j + r[j] - i);
		}
		while (i - r[i] >= 0 && i + r[i] < n && t[i - r[i]] == t[i + r[i]]) {
			r[i]++;
		}
		if (i + r[i] > j + r[j]) {
			j = i;
		}
	}
	return r;
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