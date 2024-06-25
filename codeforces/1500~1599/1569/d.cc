#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_X = 1000000;
constexpr int MAX_Y = 1000000;

void solve() {
  int n = 0, m = 0, k = 0;
  cin >> n >> m >> k;
  vector<int> x(n), y(m);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }
  for (int i = 0; i < m; ++i) {
    cin >> y[i];
  }

  vector<pair<int, int>> people;
  for (int i = 0; i < k; ++i) {
    int xp = 0, yp = 0;
    cin >> xp >> yp;
    people.emplace_back(xp, yp);
  }

  vector<bool> is_vertical(MAX_X + 1);
  for (int i = 0; i < n; ++i) {
    is_vertical[x[i]] = true;
  }
  vector<bool> is_horizontal(MAX_Y + 1);
  for (int i = 0; i < m; ++i) {
    is_horizontal[y[i]] = true;
  }

  vector<pair<int,int>> l1, l2;
  i64 ans = 0;
  for (int i = 0; i < k; ++i) {
    auto [xp, yp] = people[i];
    if (is_vertical[xp] && is_horizontal[yp]) {
      continue;
    }

    if (is_vertical[xp]) {
      l1.emplace_back(xp, yp);
    }

    if (is_horizontal[yp]) {
      l2.emplace_back(xp, yp);
    }
  }

  sort(x.begin(), x.end());
  sort(y.begin(), y.end());

  sort(l1.begin(), l1.end(), [&](auto& p1, auto& p2) {
    return p1.second < p2.second;
  });
  sort(l2.begin(), l2.end(), [&](auto& p1, auto& p2) {
    return p1.first < p2.first;
  });


  for (int i = 0, j = 0; i < m; ++i) {
    map<int, int> count;
    while (j < (int)l1.size() && l1[j].second <= y[i]) {
      auto [xp, yp] = l1[j];

      count[xp]++;

      j++;
    }

    int sum = 0;
    for (auto& [xp, c] : count) {
      ans += c * sum;
      sum += c;
    }
  }

  for (int i = 0, j = 0; i < n; ++i) {
    map<int, int> count;
    while (j < (int)l2.size() && l2[j].first <= x[i]) {
      auto [xp, yp] = l2[j];
      count[yp]++;

      j++;
    }

    int sum = 0;
    for (auto& [yp, c] : count) {
      ans += c * sum;
      sum += c;
    }
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
