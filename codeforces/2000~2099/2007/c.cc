#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 a = 0, b = 0;
  cin >> n >> a >> b;
  vector<i64> c(n);
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }

  auto min_diff = [&](i64 add, vector<i64>& d) -> i64 {
    vector<i64> e;
    for (int i = 0; i < n; ++i) {
      e.push_back(d[i] % add);
    }
    sort(e.begin(), e.end());
    e.resize(unique(e.begin(), e.end()) - e.begin());
    if (e.size() == 1) {
      return 0;
    }

    i64 ans = e.back() - e[0];
    for (int i = 0; i < n-1; ++i) {
      ans = min(ans, e[i] + add - e[i+1]);
    }
    d = std::move(e);

    // cout << "add=" << add << endl;
    // for (int x : d) {
    //   cout << x << " ";
    // }
    // cout << endl;
    return ans;
  };

  if (b > a) {
    swap(a, b);
  }

  vector<i64> d = c;
  i64 ans = min_diff(a, d);
  ans = min(ans, min_diff(b, d));
  if (a != b) {
    ans = min(ans, min_diff(gcd(a, b), d));
  }
  cout << ans << endl;
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
