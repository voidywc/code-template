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
const int maxn = 1e6 + 5, mod = 1e9 + 7, maxp = 31, inf = 1e9;
const ll INF = 1e18;
const double eps = 1e-6;

struct node {
    int a, b, c;
    bool operator< (const node & x) const {
        if (a - x.a) return a < x.a;
        if (b - x.b) return b < x.b;
        return c < x.c;
    }
};

int max_;// 树状数组的上限, 可以考虑离散化

int c[maxn];

int lowbit(int x) {
    return x & -x;
}

void add(int pos, int val) {
    if (pos == 0) return;
    while (pos <= max_) {
        c[pos] += val;
        pos += lowbit(pos);
    }
}

int query(int pos) {
    int ans = 0;
    while (pos) {
        ans += c[pos];
        pos -= lowbit(pos);
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<node> p(n + 1);
    for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        p[i] = {a, b, c};
        max_ = max({max_, a, b, c});
    }
    sort(p.begin() + 1, p.end());
    int ans = 0;
    function<void(int, int)> CDQ = [&](int l, int r) {
        if (l == r) return;
        int mid = l + r >> 1;
        CDQ(l, mid);
        CDQ(mid + 1, r);
        sort(p.begin() + l, p.begin() + mid + 1, [&](node x, node y) {
            if (x.b - y.b) return x.b < y.b;
            return x.c < y.c;
        });
        sort(p.begin() + mid + 1, p.begin() + r + 1, [&](node x, node y) {
            if (x.b - y.b) return x.b < y.b;
            return x.c < y.c;
        });
        int i = l, j = mid + 1;
        while (j <= r) {
            while (i <= mid && p[i].b <= p[j].b) {
                add(p[i].c, 1);
                i++;
            }
            ans += query(p[j].c);
            j++;
        }
        for (int k = l; k < i; k++) {
            add(p[k].c, -1);
        }
    };
    CDQ(1, n);
    cout << ans << endl;
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