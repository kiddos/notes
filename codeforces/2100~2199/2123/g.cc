#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<int> get_factors(int x) {
  vector<int> f;
  for (int d = 1; d*d <= x; ++d) {
    if (x % d == 0) {
      f.push_back(x/d);
      f.push_back(d);
    }
  }
  sort(f.begin(), f.end());
  f.resize(unique(f.begin(), f.end()) - f.begin());
  return f;
}

int mod(int x, int n){
  return ((x % n) + n) % n;
}

void solve() {
  int n = 0, m = 0, q = 0;
  cin >> n >> m >> q;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  vector<int> factors = get_factors(m);
  map<int,i64> last;
  for (int f : factors) {
    for (int i = 1; i <= n; ++i) {
      last[f] += mod(a[i] - a[i-1], f);
    }
  }

  for (int j = 0; j < q; ++j) {
    int type = 0;
    cin >> type;
    if (type == 1) {
      int i = 0, x = 0;
      cin >> i >> x;

      for (int f : factors) {
        last[f] += mod(x - a[i-1], f);
        last[f] -= mod(a[i] - a[i-1], f);
        if (i+1 <= n) {
          last[f] += mod(a[i+1] - x, f);
          last[f] -= mod(a[i+1] - a[i], f);
        }
      }

      a[i] = x;
    } else if (type == 2) {
      int k = 0;
      cin >> k;
      bool ans = last[gcd(k, m)] < m;
      if (ans) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
