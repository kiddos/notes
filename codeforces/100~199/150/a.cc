#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<i64> get_factor(i64 x) {
  vector<i64> f;
  for (i64 d = 2; d * d <= x; ++d) {
    if (x % d == 0) {
      f.push_back(d);
      if (x / d != d) {
        f.push_back(x / d);
      }
    }
  }
  sort(f.begin(), f.end());
  return f;
}

void solve() {
  i64 q = 0;
  cin >> q;

  i64 last = 0;
  auto dfs = [&](const auto& self, i64 x) -> bool {
    vector<i64> factors = get_factor(x);
    if (factors.empty()) {
      return true;
    }
    for (i64 f : factors) {
      if (!self(self, f)) {
        last = f;
        return true;
      }
    }
    return false;
  };

  bool result = dfs(dfs, q);
  if (result) {
    cout << "1" << endl;
    cout << last << endl;
  } else {
    cout << "2" << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
