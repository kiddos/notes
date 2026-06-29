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

  int ans = 0;
  vector<bool> is_greater(n);
  for (int j = 0; j < m; ++j) {
    bool remove = false;
    vector<bool> will_be_greater(n);
    for (int i = 1; i < n; ++i) {
      if (is_greater[i]) {
        continue;
      }
      if (s[i][j] > s[i-1][j]) {
        will_be_greater[i] = true;
      }
      if (s[i][j] < s[i-1][j]) {
        remove = true;
        break;
      }
    }
    if (remove) {
      ans++;
    } else {
      for (int i = 1; i < n; ++i) {
        is_greater[i] = is_greater[i] || will_be_greater[i];
      }
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
