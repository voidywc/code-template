#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define X first
#define Y second
#define umap unordered_map
using ll = long long;
typedef pair<int, int> pii;
const int maxn = 2e5 + 5, mod = 998244353, maxp = 65, inf = 1e9;
const ll INF = 1e18;

int n, m;

int nxt[maxn];

void init(string s) {
	m = s.size();
	nxt[1] = 0;
	for (int i = 2, j = 0; i <= m; i++) {
		while (j && s[i] != s[j + 1]) j = nxt[j];
		if (s[i] == s[j + 1]) j++;
		nxt[i] = j;
	}
}

void KMP(string s1, string s2) {
	n = s1.size(), m = s2.size();
	s1 = " " + s1;
	s2 = " " + s2;
	init(s2);
	for (int i = 1, j = 0; i <= n; i++) {
		while (j && s1[i] != s2[j + 1]) j = nxt[j];
		if (s1[i] == s2[j + 1]) j++;
		if (j == m) {
			cout << i - m + 1 << endl;
		}
	}
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