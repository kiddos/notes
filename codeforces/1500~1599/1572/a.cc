#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<vector<int>> a(n+1);
  for (int i = 1; i <= n; ++i) {
    int k = 0;
    cin >> k;
    a[i] = vector<int>(k);
    for (int j = 0; j < k; ++j) {
      cin >> a[i][j];
    }
  }

  vector<int> state(n+1);
  function<bool(int)> find_cycle = [&](int chapter) -> bool {
    if (state[chapter]) {
      return state[chapter] == 1;
    }
    state[chapter] = 1;
    for (int prev_chapter : a[chapter]) {
      if (find_cycle(prev_chapter)) {
        return true;
      }
    }
    state[chapter] = 2;
    return false;
  };

  for (int c = 1; c <= n; ++c) {
    if (!state[c]) {
      if (find_cycle(c)) {
        cout << "-1" << endl;
        return;
      }
    }
  }

  vector<int> min_days(n+1);
  function<void(int)> dfs = [&](int chapter) {
    if (min_days[chapter]) {
      return;
    }

    min_days[chapter] = 1;
    if (a[chapter].size() == 0) {
      return;
    }

    int best = 0;
    int pc = 0;
    for (int prev_chapter : a[chapter]) {
      dfs(prev_chapter);
      if (min_days[prev_chapter] > best) {
        best = min_days[prev_chapter];
        pc = prev_chapter;
      } else if (min_days[prev_chapter] == best) {
        pc = max(pc, prev_chapter);
      }
    }

    if (pc < chapter) {
      min_days[chapter] = best;
    } else {
      min_days[chapter] = best+1;
    }
  };

  for (int c = 1; c <= n; ++c) {
    if (!min_days[c]) {
      dfs(c);
    }
  }

  int ans = *max_element(min_days.begin(), min_days.end());
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
