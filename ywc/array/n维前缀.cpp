#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define X first
#define Y second
#define umap unordered_map
using ll = long long;
using ull = unsigned long long;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int maxn = 2e5 + 5, mod = 1e9 + 7, maxp = 31, inf = 1e9;
const ll INF = 1e18;
const double eps = 1e-6;

void solve() {
    int n;
    cin >> n;
    vector<int> s(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    auto n_work = [&]() -> void {
        const int m = log2(n) + 1;
        for (int j = 0; j < m; j++) {
            for (int i = 0; i <= n; i++) {
                if (i >> j & 1) {
                    int k = (i ^ (1 << j));
                    s[i] += s[k];
                }
            }
        }
    };
    n_work();
    for (int i = 1; i <= n; i++) {
        cout << i << " " << s[i] << endl;
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