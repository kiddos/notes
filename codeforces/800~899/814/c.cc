#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  int q = 0;
  cin >> q;
  vector<pair<int,char>> queries;
  for (int i = 0; i < q; ++i) {
    int m = 0;
    char ch = '\0';
    cin >> m >> ch;
    queries.push_back({m, ch});
  }

  auto compute_min_change = [&](char ch, int len) -> int {
    int window = 0;
    for (int i = 0; i < len; ++i) {
      if (s[i] != ch) {
        window++;
      }
    }
    int ans = window;
    for (int i = len; i < n; ++i) {
      if (s[i] != ch) {
        window++;
      }
      if (s[i-len] != ch) {
        window--;
      }
      ans = min(ans, window);
    }
    return ans;
  };

  vector<vector<int>> min_changes(26, vector<int>(n+1));
  for (char ch = 'a'; ch <= 'z'; ++ch) {
    for (int len = 1; len <= n; ++len) {
      min_changes[ch-'a'][len] = compute_min_change(ch, len);
    }
  }

  vector<int> ans;
  for (auto [m, ch] : queries) {
    int c = ch-'a';
    int l = 0, r = n;
    int len = 0;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      if (min_changes[c][mid] <= m) {
        len = mid;
        l = mid+1;
      } else {
        r = mid-1;
      }
    }
    ans.push_back(len);
  }

  for (int i = 0; i < q; ++i) {
    cout << ans[i] << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
