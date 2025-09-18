#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<i64> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }

  vector<i64> ans;
  if (n == 1) {
    for (int i = 0; i < m; ++i) {
      ans.push_back(a[0] + b[i]);
    }
  } else {
    vector<i64> d(n);
    for (int i = 1; i < n; ++i) {
      d[i] = abs(a[i] - a[i-1]);
    }
    i64 g = d[1];
    for (int i = 1; i < n; ++i) {
      g = gcd(g, d[i]);
    }

    i64 min_val = *min_element(a.begin(), a.end());
    for (int i = 0; i < m; ++i) {
      i64 x = min_val + b[i];
      ans.push_back(gcd(x, g));
    }
  }

  for (int i = 0; i < m; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
