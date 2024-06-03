#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_N = 10;

struct Build {
  array<int, MAX_N> selected;
  int strength;
};

struct CompareBuild {
  bool operator()(const Build& b1, const Build& b2) {
    return b1.strength < b2.strength;
  }
};

void solve() {
  int n = 0;
  cin >> n;
  vector<vector<int>> a(n);
  for (int i = 0; i < n; ++i) {
    int c = 0;
    cin >> c;
    vector<int> row(c);
    for (int j = 0; j < c; ++j) cin >> row[j];
    a[i] = std::move(row);
  }

  int m = 0;
  cin >> m;
  set<array<int, MAX_N>> b;
  for (int k = 0; k < m; ++k) {
    array<int, MAX_N> list = {0};
    for (int i = 0; i < n; ++i) {
      cin >> list[i];
      list[i]--;
    }
    b.insert(list);
  }

  priority_queue<Build, vector<Build>, CompareBuild> pq;
  array<int, MAX_N> selected = {0};
  int strength = 0;
  set<array<int, MAX_N>> visited;
  for (int i = 0; i < n; ++i) {
    selected[i] = a[i].size()-1;
    strength += a[i].back();
  }

  if (!b.count(selected)) {
    for (int i = 0; i < n; ++i) {
      cout << selected[i]+1 << " ";
    }
    cout << endl;
    return;
  }

  int best_strength = 0;
  pq.push(Build{selected, strength});
  visited.insert(selected);
  array<int, MAX_N> ans = selected;

  while (!pq.empty()) {
    auto build = pq.top();
    pq.pop();

    if (!b.count(build.selected)) {
      if (build.strength > best_strength) {
        best_strength = build.strength;
        ans = build.selected;
      }
      continue;
    } else {
      for (int i = 0; i < n; ++i) {
        array<int, MAX_N> new_selected = build.selected;
        if (build.selected[i] > 0) {
          new_selected[i]--;

          int old_a = a[i][new_selected[i]+1];
          int new_a = a[i][new_selected[i]];
          int new_strength = build.strength - old_a + new_a;
          if (visited.count(new_selected)) continue;
          visited.insert(new_selected);
          pq.push(Build{new_selected, new_strength});
        }
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i]+1 << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
