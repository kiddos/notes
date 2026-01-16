#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  vector<i64> total_count(26);
  for (int i = 0; i < n; ++i) {
    for (char ch : s[i]) {
      int c = ch - 'A';
      total_count[c]++;
    }
  }
  vector<vector<i64>> can_use(m+1, vector<i64>(26));
  for (int i = 1; i <= m; ++i) {
    for (int c = 0; c < 26; ++c) {
      can_use[i][c] = can_use[i-1][c] + total_count[c];
    }
  }

  auto is_enough = [&](vector<i64>& available, vector<i64>& current_count) -> bool {
    for (int c = 0; c < 26; ++c) {
      if (available[c] < current_count[c]) {
        return false;
      }
    }
    return true;
  };

  vector<int> ans(n, -1);
  for (int i = 0; i < n; ++i) {
    vector<i64> current_count(26);
    for (char ch : s[i]) {
      int c = ch - 'A';
      current_count[c]++;
    }

    int l = 0, r = m;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      vector<i64> available = can_use[mid];
      for (int c = 0; c < 26; ++c) {
        available[c] -= mid * current_count[c];
      }

      if (is_enough(available, current_count)) {
        r = mid-1;
        ans[i] = m - mid;
      } else {
        l = mid+1;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
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
