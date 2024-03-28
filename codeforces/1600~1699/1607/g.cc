#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string empty;
  getline(cin, empty);

  int n = 0, m = 0;
  cin >> n >> m;
  vector<pair<int,int>> dishes;
  for (int i = 0; i < n; ++i) {
    int a = 0, b = 0;
    cin >> a >> b;
    dishes.emplace_back(a, b);
  }

  i64 max_fish = 0, min_meat = 0;
  i64 min_fish = 0, max_meat = 0;
  for (int i = 0; i < n; ++i) {
    int eat_b = min(m, dishes[i].second);
    int eat_a = m - eat_b;
    max_fish += dishes[i].first - eat_a;
    min_meat += dishes[i].second - eat_b;

    eat_a = min(m, dishes[i].first);
    eat_b = m - eat_a;
    min_fish += dishes[i].first - eat_a;
    max_meat += dishes[i].second - eat_b;
  }

  i64 max_balance = max_fish - min_meat;
  i64 min_balance = min_fish - max_meat;

  if (max_balance < 0) {
    // try to eat as much meat as possible
    i64 d = abs(max_balance);
    cout << d << endl;
    for (int i = 0; i < n; ++i) {
      int eat_b = min(m, dishes[i].second);
      int eat_a = m - eat_b;
      cout << eat_a << " " << eat_b << endl;
    }
  } else if (min_balance > 0) {
    // try to eat as much fish as possible
    i64 d = min_balance;
    cout << d << endl;
    for (int i = 0; i < n; ++i) {
      int eat_a = min(m, dishes[i].first);
      int eat_b = m - eat_a;
      cout << eat_a << " " << eat_b << endl;
    }
  } else {
    // (a[i] - x[i]) - (b[i] - y[i])
    // => a[i] - x[i] - (b[i] - (m - x[i]))
    // => a[i] - b[i] + m - 2 * x[i]
    // => make 2 * x[i] as close as a[i] - b[i] + m
    i64 left = 0;
    for (int i = 0; i < n; ++i) {
      left += dishes[i].first - dishes[i].second + m;
    }
    vector<int> x(n);
    i64 right = 0;
    for (int i = 0; i < n; ++i) {
      if (dishes[i].second < m) {
        x[i] = m - dishes[i].second;
        right += x[i] * 2LL;
      }
    }

    for (int i = 0; i < n; ++i) {
      if (right >= left) break;
      if (right + 2 * min(m - x[i], dishes[i].first - x[i]) >= left) {
        // edge case
        int add = (left - right) / 2;
        x[i] += add;
        right += add * 2;
        break;
      }
      int add = min(m, dishes[i].first) - x[i];
      x[i] += add;
      right += add * 2;
    }

    i64 d = abs(left - right);
    cout << d << endl;
    for (int i = 0; i < n; ++i) {
      int eat_a = x[i];
      int eat_b = m - eat_a;
      cout << eat_a << " " << eat_b << endl;
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
