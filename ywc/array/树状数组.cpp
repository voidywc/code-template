#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
typedef pair<int, int> pii;
const int maxn = 2e5 + 5, mod = 1e9 + 7, maxp = 65, inf = 1e9;
const ll INF = 1e18;

struct BIT {
    vector<ll> c;
    int ub;
    BIT() {}
    BIT(int ub_) {
        ub = ub_;
        init();
    }

    void init() {
        c.resize(ub);
        c.assign(ub, 0);
    }

    int lowbit(int x) {
        return x & -x;
    }

    void add(int pos, ll val) {
        if (pos <= 0) return;
        while (pos <= ub) {
            c[pos] += val;
            pos += lowbit(pos);
        }
    }

    ll query(int pos) {
        if (pos <= 0) return 0;
        ll res = 0;
        while (pos) {
            res += c[pos];
            pos -= lowbit(pos);
        }
        return res;
    }

    ll query(int l, int r) {
        return query(r) - query(l - 1); 
    }
};

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