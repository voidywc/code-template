#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
typedef pair<int, int> pii;
const int maxn = 2e5 + 5, mod = 998244353, maxp = 65, inf = 1e9;
const ll INF = 1e18;

int ch[maxn][26];

int cnt[maxn];

int idx;

void insert(string s) {
	int p = 0;
	for (auto c : s) {
		int j = c - 'a';
		if (!ch[p][j]) ch[p][j] = ++idx;
		p = ch[p][j];
	}
	cnt[p]++;
}

int query(string s) {
	int p = 0;
	for (auto c : s) {
		int j = c - 'a';
		p = ch[p][j];
		if (p == 0) return 0;
	}
	return cnt[p];
}

void solve() {
	for (int i = 0; i <= idx; i++) {
		for (int j = 0; j < 26; j++) {
			ch[i][j] = 0;
		}
	}
	for (int i = 1; i <= idx; i++) {
		cnt[i] = 0;
	}
	idx = 0;
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