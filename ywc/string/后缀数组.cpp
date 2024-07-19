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
const int maxn = 1e6 + 5, mod = 998244353, maxp = 31, inf = 1e9;
const ll INF = 1e18;
const double eps = 1e-6;

struct SuffixArray {// s要自带" "
    int n;
    int k;
    vector<int> sa, rk, lc, tmp;
    // sa[i]表示第i小的后缀的下标
    // rk[i]表示下标为i的后缀的排名

    SuffixArray(const string &s) {
        n = s.size() - 1;
        getsa(s);
        getlcp(s);
    }

    bool cmp(int i, int j) {
        if (rk[i] != rk[j]) return rk[i] < rk[j];
        int ri = (i + k <= n ? rk[i + k] : -1);
        int rj = (j + k <= n ? rk[j + k] : -1);
        return ri < rj;
    }

    void getsa(const string &s) {
        sa.resize(n + 1);
        rk.resize(n + 1);
        tmp.resize(n + 1);

        iota(sa.begin(), sa.end(), 0);
        for (int i = 1; i <= n; i++) {
            rk[i] = s[i];
        }
        for (k = 1; k <= n; k *= 2) {
            sort(sa.begin() + 1, sa.end(), [&](int i, int j) {
                if (rk[i] != rk[j]) return rk[i] < rk[j];
                int ri = (i + k <= n ? rk[i + k] : -1);
                int rj = (j + k <= n ? rk[j + k] : -1);
                return ri < rj;
            });

            tmp[sa[1]] = 1;
            for (int i = 2; i <= n; i++) {
                tmp[sa[i]] = tmp[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
            }
            rk = tmp;
        }
    }

    void getlcp(const string &s) {
        lc.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            rk[sa[i]] = i;
        }

        int h = 0;
        lc[1] = 0;

        for (int i = 1; i <= n; i++) {
            int j = sa[rk[i] - 1];
            if (h > 0) h--;
            while (i + h <= n && j + h <= n) {
                if (s[i + h] != s[j + h]) break;
                h++;
            }
            lc[rk[i]] = h;
        }
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
};
